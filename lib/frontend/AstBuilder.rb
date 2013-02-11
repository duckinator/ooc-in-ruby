require 'fileutils'

#import ../frontend/[Token, BuildParams]
#import ../middle/tinker/Errors
[:FunctionDecl, :VariableDecl, :TypeDecl, :ClassDecl, :CoverDecl,
 :FunctionCall, :StringLiteral, :Node, :Module, :Statement, :Include, :Import,
 :Type, :TypeList, :Expression, :Return, :VariableAccess, :Cast, :If, :Else,
 :ControlStatement, :Comparison, :IntLiteral, :FloatLiteral, :Ternary,
 :BinaryOp, :BoolLiteral, :NullLiteral, :Argument, :Parenthesis, :AddressOf,
 :Dereference, :Foreach, :OperatorDecl, :RangeLiteral, :UnaryOp, ArrayAccess,
 :Match, :FlowControl, :While, :CharLiteral, :InterfaceDecl, :NamespaceDecl,
 :Version, :Use, :Block, :ArrayLiteral, :EnumDecl, :BaseType, :FuncType,
 :Declaration, :PropertyDecl, :CallChain, :Tuple, :Addon, :Try].each do |x|
  require File.join(File.dirname(__FILE__), '..', 'middle', "#{x}.rb")
end

nq_parse: extern proto func (AstBuilder, CString) -> Int

# reserved C99 keywords
reservedWords = ["auto", "int", "long", "char", "register", "short", "do",
                 "sizeof", "double", "struct", "switch", "typedef", "union",
                 "unsigned", "signed", "goto", "enum", "const"]
reservedHashes = computeReservedHashes(reservedWords)

class ReservedKeywordError << Exception
end

#accepts(words: String[])
#returns([Int])
def computeReservedHashes(words)
    list := ArrayList<Int> new()
    words length times(|i|
        word := words[i]
        list add(ac_X31_hash(word))
    )
    list
}

class AstBuilder

    @cache = {} # static HashMap<String, Module> new()

    @langImports = [] # List<String>

    @params = nil # BuildParams
    @modulePath = nil # String
    @module = nil # Module
    stack: Stack<Object>
    versionStack: Stack<VersionSpec>

    tokenPos : Int*

    def initialize (modulePath, module, params)
        @modulePath = modulePath
        @module = module
        @params = params

        first - true
        #clearline = "                                                   \r"

        if(params.verbose)
            #if(!first) print clearline
            print "Parsing "
            print modulePath
        end
        cache.put(File.expand_path(File.open(modulePath).path), module)

        stack = Stack<Object> new()
        stack push(module)
        versionStack = Stack<VersionSpec> new()

        if(params includeLang && !module fullName startsWith?("/")) {
            addLangImports()
        }

        first = false
        result := nq_parse(this, modulePath)
        if(result == -1) {
            raise(self.class, "File " +modulePath + " not found") throw()
        }

    end

    addLangImports: func {

        langImports : static List<String> = null

        if(!langImports) {
            langImports = ArrayList<String> new()
            paths := params sourcePath getRelativePaths("lang")
            paths filterEach(|p| p endsWith?(".ooc"),
                    |p|
                    impName := p substring(0, p length() - 4) replaceAll(File separator, '/')
                    langImports add(impName)
            )
        }

        langImports filterEach(|impName| impName != module fullName,
                    |impName| module addImport(Import new(impName, module token))
        )

    }

    #
    # Turn import paths like "../frontend/AstBuilder" into "/opt/ooc/rock/source/rock/frontend/AstBuilder"
    #
    # @return
    #   - The non-redundant path
    #   - The .ooc File
    #   - A File to the pathElement where the .ooc File was found.
    #
    getRealImportPath: static func (imp: Import, module: Module, params: BuildParams) -> (String, File, File) {
        oocImpPath := imp path + ".ooc"
        path := FileUtils resolveRedundancies(oocImpPath)
        (impPath, impElement) := params sourcePath getFile(path)
        if(!impElement) {
            parent := File new(module path) parent()
            if(parent) {
                path = FileUtils resolveRedundancies(parent path + File separator + oocImpPath)
                (impPat2, impElemen2) := params sourcePath getFile(path)
                (impPath, impElement) = (impPat2, impElemen2)
            }
        }
        (path, impPath, impElement)
    }

    printCache: static func {
        "==== Cache ====" println()
        cache getKeys() each(|key|
            "cache %s = %s" format(key, cache get(key) fullName) println()
        )
        "=" times(14) println()
    }

    error: func (errorID: Int, message: String, index: Int) {
        params errorHandler onError(SyntaxError new(Token new(index, 1, module), message))
    }

    onUse: unmangled(nq_onUse) func (name: CString) {
        module addUse(Use new(name toString(), params, token()))
    }

    onInclude: unmangled(nq_onInclude) func (cpath: CString) {
        path := cpath toString()
        mode: IncludeMode
        if(path startsWith?("./")) {
            mode = IncludeModes LOCAL
            path = path substring(2) # remove ./ from path
        }
        else {
            mode = IncludeModes PATHY
        }

        inc := Include new(path, mode)
        module addInclude(inc)
        inc setVersion(getVersion())
    }

    onIncludeDefine: unmangled(nq_onIncludeDefine) func (name, value: CString) {
        module includes last() addDefine(Define new(name toString(), value toString()))
    }

    onImport: unmangled(nq_onImport) func (path, name: CString) {
        namestr := name toString()
        output : String = ((path == null) || (path@ == '\0')) ? namestr : path toString() + namestr
        module addImport(Import new( output , token()))
    }

    onImportNamespace: unmangled(nq_onImportNamespace) func (cnamespace: CString, quantity: Int) {
        if(params veryVerbose) "nq_importnamespace %s" printfln(cnamespace)
        namespace := cnamespace toString()
        nDecl: NamespaceDecl
        if(!module hasNamespace(namespace)) {
            nDecl = NamespaceDecl new(namespace)
            module addNamespace(nDecl)
        } else {
            nDecl = module getNamespace(namespace)
        }
        peek(Module) # ensure we're a at root level
        quantity times(||
            nDecl addImport(module getGlobalImports() last())
            module getGlobalImports() removeAt(module getGlobalImports() lastIndex()) # no longer a global import
        )
    }

    /*
     * Addons
     */
    onExtendStart: unmangled(nq_onExtendStart) func (baseType: Type, doc: CString) {
        addon := Addon new(baseType, token())
        addon doc = doc toString()
        stack push(addon)
    }

    onExtendEnd: unmangled(nq_onExtendEnd) func -> Addon {
        module addAddon(pop(Addon))
    }

    /*
     * Covers
     */

    onCoverStart: unmangled(nq_onCoverStart) func (name, doc: CString) {
        cDecl := CoverDecl new(name toString(), token())
        cDecl setVersion(getVersion())
        cDecl doc = doc toString()
        cDecl module = module
        module addType(cDecl)
        stack push(cDecl)
    }

    onCoverExtern: unmangled(nq_onCoverExtern) func (externName: CString) {
        peek(CoverDecl) setExternName(externName toString())
    }

    onCoverFromType: unmangled(nq_onCoverFromType) func (type: Type) {
        peek(CoverDecl) setFromType(type)
    }

    onCoverExtends: unmangled(nq_onCoverExtends) func (superType: Type) {
        peek(CoverDecl) setSuperType(superType)
    }

    onCoverImplements: unmangled(nq_onCoverImplements) func (interfaceType: Type) {
        peek(CoverDecl) addInterface(interfaceType)
    }

    onCoverEnd: unmangled(nq_onCoverEnd) func {
        pop(CoverDecl)
    }

    /*
     * Enums
     */

    onEnumStart: unmangled(nq_onEnumStart) func (name, doc: CString) {
        eDecl := EnumDecl new(name toString(), token())
        eDecl setVersion(getVersion())
        eDecl module = module
        eDecl doc = doc toString()
        module addType(eDecl)
        stack push(eDecl)
    }

    onEnumExtern: unmangled(nq_onEnumExtern) func (externName: CString) {
        peek(EnumDecl) setExternName(externName toString())
    }

    onEnumFromType: unmangled(nq_onEnumFromType) func (fromType: Type) {
        peek(EnumDecl) setFromType(fromType)
    }

    onEnumIncrementExpr: unmangled(nq_onEnumIncrementExpr) func (oper: Char, step: IntLiteral) {
        peek(EnumDecl) setIncrement(oper, step value)
    }

    onEnumElementStart: unmangled(nq_onEnumElementStart) func (name, doc: CString) {
        element := EnumElement new(peek(EnumDecl) getInstanceType(),name toString(), token())
        element doc = doc toString()
        stack push(element)
    }

    onEnumElementValue: unmangled(nq_onEnumElementValue) func (value: Expression) {
        peek(EnumElement) setValue(value)
    }

    onEnumElementExtern: unmangled(nq_onEnumElementExtern) func (externName: CString) {
        peek(EnumElement) setExternName(externName toString())
    }

    onEnumElementEnd: unmangled(nq_onEnumElementEnd) func {
        element := pop(EnumElement)
        peek(EnumDecl) addElement(element)
    }

    onEnumEnd: unmangled(nq_onEnumEnd) func {
        pop(EnumDecl)
    }

    /*
     * Classes
     */

    onClassStart: unmangled(nq_onClassStart) func (name, doc: CString) {
        cDecl := ClassDecl new(name toString(), token())
        cDecl setVersion(getVersion())
        cDecl doc = doc toString()
        cDecl module = module
        module addType(cDecl)
        stack push(cDecl)
    }

    onClassExtends: unmangled(nq_onClassExtends) func (superType: Type) {
        peek(ClassDecl) setSuperType(superType)
    }

    onClassImplements: unmangled(nq_onClassImplements) func (interfaceType: Type) {
        peek(ClassDecl) addInterface(interfaceType)
    }

    onClassAbstract: unmangled(nq_onClassAbstract) func {
        peek(ClassDecl) isAbstract = true
    }

    onClassFinal: unmangled(nq_onClassFinal) func {
        peek(ClassDecl) isFinal = true
    }

    onClassBody: unmangled(nq_onClassBody) func {
        peek(ClassDecl) addDefaultInit()    }

    onClassEnd: unmangled(nq_onClassEnd) func {
        pop(ClassDecl)
    }

    /*
     * Version blocks
     */

    onVersionName: unmangled(nq_onVersionName) func (name: CString) -> VersionSpec {
        VersionName new(name toString(), token())
    }

    onVersionNegation: unmangled(nq_onVersionNegation) func (spec: VersionSpec) -> VersionSpec {
        VersionNegation new(spec, token())
    }

    onVersionAnd: unmangled(nq_onVersionAnd) func (specLeft, specRight: VersionSpec) -> VersionSpec {
        VersionAnd new(specLeft, specRight, token())
    }

    onVersionOr: unmangled(nq_onVersionOr) func (specLeft, specRight: VersionSpec) -> VersionSpec {
        VersionOr new(specLeft, specRight, token())
    }

    onVersionStart: unmangled(nq_onVersionStart) func (spec: VersionSpec) {
        match (object := peek(Object)) {
            case mod: Module =>
                versionStack push(spec)
            case =>
                stack push(VersionBlock new(spec, token()))
        }
    }

    onVersionElseIfStart: unmangled(nq_onVersionElseIfStart) func (oldSpec, elseSpec: VersionSpec) -> VersionSpec {
        onVersionStart(VersionAnd new(VersionNegation new(oldSpec, token()), elseSpec, token()))
        VersionOr new(oldSpec, elseSpec, token())
    }

    onVersionElseStart: unmangled(nq_onVersionElseStart) func (oldSpec: VersionSpec) {
        onVersionStart(VersionNegation new(oldSpec, token()))
    }

    onVersionEnd: unmangled(nq_onVersionEnd) func -> VersionBlock {
        object := peek(Object)
        match object {
            case mod: Module =>
                versionStack pop()
                null
            case =>
                pop(VersionBlock)
        }
    }

    /*
     * Interfaces
     */

    onInterfaceStart: unmangled(nq_onInterfaceStart) func (name, doc: CString) {
        iDecl := InterfaceDecl new(name toString(), token())
        iDecl setVersion(getVersion())
        iDecl doc = doc toString()
        iDecl module = module
        module addType(iDecl)
        stack push(iDecl)
    }

    onInterfaceExtends: unmangled(nq_onInterfaceExtends) func (superType: Type) {
        peek(InterfaceDecl) setSuperType(superType)
    }

    onInterfaceEnd: unmangled(nq_onInterfaceEnd) func {
        pop(InterfaceDecl)
    }

    onTypeAccess: unmangled(nq_onTypeAccess) func (t: Type) -> TypeAccess {
        TypeAccess new(t, t token)
    }

    /*
     * Variable declarations
     */

    onVarDeclStart: unmangled(nq_onVarDeclStart) func {
        stack push(Stack<VariableDecl> new())
    }

    onVarDeclName: unmangled(nq_onVarDeclName) func (name, doc: CString) {
        vDecl := VariableDecl new(null, name toString(), token())
        vDecl doc = doc toString()
        peek(Stack<VariableDecl>) push(vDecl)
    }

    onVarDeclTuple: unmangled(nq_onVarDeclTuple) func (tuple: Tuple) {
        peek(Stack<VariableDecl>) push(VariableDeclTuple new(null as Type, tuple, token()))
    }

    onVarDeclExtern: unmangled(nq_onVarDeclExtern) func (cexternName: CString) {
        externName := cexternName toString()
        vars := peek(Stack<VariableDecl>)
        if(externName empty?()) {
            vars each(|var| var setExternName(""))
        } else {
            if(vars getSize() != 1) {
                params errorHandler onError(SyntaxError new(token(), "Trying to set an extern name on several variables at once!"))
            }
            vars peek() setExternName(externName)
        }
    }

    onVarDeclUnmangled: unmangled(nq_onVarDeclUnmangled) func (cunmangledName: CString) {
        unmangledName :=cunmangledName toString()
        vars := peek(Stack<VariableDecl>)
        if(unmangledName empty?()) {
            vars each(|var| var setUnmangledName(""))
        } else {
            if(vars getSize() != 1) {
                params errorHandler onError(SyntaxError new(token(), "Trying to set an unmangled name on several variables at once!"))
            }
            vars peek() setUnmangledName(unmangledName)
        }
    }

    onVarDeclExpr: unmangled(nq_onVarDeclExpr) func (expr: Expression) {
        peek(Stack<VariableDecl>) peek() setExpr(expr)
    }

    onVarDeclStatic: unmangled(nq_onVarDeclStatic) func {
        peek(Stack<VariableDecl>) each(|vd| vd setStatic(true))
    }

    onVarDeclProto: unmangled(nq_onVarDeclProto) func {
        peek(Stack<VariableDecl>) each(|vd| vd setProto(true))
    }

    onVarDeclConst: unmangled(nq_onVarDeclConst) func {
        peek(Stack<VariableDecl>) each(|vd| vd setConst(true))
    }

    onVarDeclType: unmangled(nq_onVarDeclType) func (type: Type) {
        peek(Stack<VariableDecl>) each(|vd| vd type = type)
    }

    onVarDeclEnd: unmangled(nq_onVarDeclEnd) func -> Object {
        stack := pop(Stack<VariableDecl>)
        if(stack getSize() == 1) return stack peek() as Object
        # FIXME: Better detection to avoid 'stack' being passed as a Statement to, say, an If
        return stack as Object
    }

    gotVarDecl: func (vd: VariableDecl) {
        hash := ac_X31_hash(vd getName())
        idx := reservedHashs indexOf(hash)
        if(idx != -1) {
            # same hash? compare length and then full-string comparison
            word := reservedWords[idx]
            if(word length() == vd getName() length() && word == vd getName()) {
                params errorHandler onError(ReservedKeywordError new(vd token, "%s is a reserved C99 keyword, you can't use it in a variable declaration" format(vd getName())))
            }
        }

        match (node := peek(Object)) {
            case tDecl: TypeDecl =>
                tDecl addVariable(vd)
            case list: List<Node> =>
                vd isArg = true
                list add(vd)
            case =>
                gotStatement(vd)
        }
    }

    /*
     * Properties
     */

    onPropertyDeclStart: unmangled(nq_onPropertyDeclStart) func (name: CString) {
        stack push(PropertyDecl new(null, name toString(), token()))
    }

    onPropertyDeclStatic: unmangled(nq_onPropertyDeclStatic) func {
        peek(PropertyDecl) setStatic(true)
    }

    onPropertyDeclType: unmangled(nq_onPropertyDeclType) func (type: Type) {
        peek(PropertyDecl) type = type
    }

    onPropertyDeclGetterStart: unmangled(nq_onPropertyDeclGetterStart) func {
        getter := FunctionDecl new("", token())
        stack push(getter)
    }

    onPropertyDeclGetterEnd: unmangled(nq_onPropertyDeclGetterEnd) func {
        getter := pop(FunctionDecl)
        # getter has 0 statements and isn't extern? use default getter
        if(getter body getSize() == 0 && !getter isExtern()) {
            peek(PropertyDecl) setDefaultGetter()
        } else {
            peek(PropertyDecl) setGetter(getter)
        }
    }

    onPropertyDeclSetterStart: unmangled(nq_onPropertyDeclSetterStart) func {
        setter := FunctionDecl new("", token())
        stack push(setter)
    }

    onPropertyDeclSetterArgument: unmangled(nq_onPropertyDeclSetterArgument) func (cname: CString, conventional: Bool) {
        name := cname toString()
        arg: Argument = match conventional {
            case true  => Argument new(null, name clone(), token())
            case false => AssArg new(name clone(), token())
        } as Argument
        peek(FunctionDecl) args add(arg)
    }

    onPropertyDeclSetterEnd: unmangled(nq_onPropertyDeclSetterEnd) func {
        setter := pop(FunctionDecl)
        # setter has 0 statements and isn't extern? use default setter
        if(setter body getSize() == 0 && !setter isExtern()) {
            peek(PropertyDecl) setDefaultSetter()
        } else {
            peek(PropertyDecl) setSetter(setter)
        }
    }

    onPropertyDeclEnd: unmangled(nq_onPropertyDeclEnd) func -> PropertyDecl {
        decl := pop(PropertyDecl)
        node := peek(TypeDecl)
        node addVariable(decl)
        decl
    }

    /*
     * Types
     */

    onTypeNew: unmangled(nq_onTypeNew) func (name: CString) -> Type {
        BaseType new(name toString() trim(), token())
    }

    onTypePointer: unmangled(nq_onTypePointer) func (type: Type) -> Type {
        PointerType new(type, token())
    }

    onTypeReference: unmangled(nq_onTypeReference) func (type: Type) -> Type {
        ReferenceType new(type, token())
    }

    onTypeBrackets: unmangled(nq_onTypeBrackets) func (type: Type, inner: Expression) -> Type {
        ArrayType new(type, inner, token())
    }

    onTypeList: unmangled(nq_onTypeList) func -> TypeList {
        TypeList new(token())
    }

    onTypeListElement: unmangled(nq_onTypeListElement) func (list: TypeList, element: Type) {
        list types add(element)
    }

    onTypeNamespace: unmangled(nq_onTypeNamespace) func (type: BaseType, ident: CString) {
        type setNamespace(VariableAccess new(ident toString(), token()))
    }

    /*
     * Function types
     */

    onFuncTypeNew: unmangled(nq_onFuncTypeNew) func -> FuncType {
        f := FuncType new(token())
        f isClosure = true
        f
    }

    onFuncTypeArgument: unmangled(nq_onFuncTypeArgument) func (f: FuncType, argType: Type) {
        f argTypes add(argType)
    }

    onFuncTypeVarArg: unmangled(nq_onFuncTypeVarArg) func (f: FuncType) {
        # TODO: what if we actually want ooc varargs in a FuncType?
        # I'm really not sure what to do syntax-wise.
        f varArg = VarArgType C
    }

    onFuncTypeReturnType: unmangled(nq_onFuncTypeReturnType) func (f: FuncType, returnType: Type) {
        f returnType = returnType
    }

    /*
     * Operator overloads
     */

    onOperatorStart: unmangled(nq_onOperatorStart) func (symbol: CString) {
        oDecl := OperatorDecl new(symbol toString() trim(), token())
        fDecl := FunctionDecl new("", token())
        oDecl setFunctionDecl(fDecl)
        stack push(oDecl)
        stack push(fDecl)
    }

    onOperatorEnd: unmangled(nq_onOperatorEnd) func {
        oDecl := pop(OperatorDecl)
        peek(Module) addOperator(oDecl)
    }

    /*
     * Functions
     */

    onFunctionStart: unmangled(nq_onFunctionStart) func (name, doc: CString) {
        fDecl := FunctionDecl new(name toString(), token())
        fDecl setVersion(getVersion())
        fDecl doc = doc toString()
        stack push(fDecl)
    }

    onFunctionExtern: unmangled(nq_onFunctionExtern) func (externName: CString) {
        peek(FunctionDecl) setExternName(externName toString())
    }

    onFunctionUnmangled: unmangled(nq_onFunctionUnmangled) func (unmangledName: CString) {
        peek(FunctionDecl) setUnmangledName(unmangledName toString())
    }

    onFunctionAbstract: unmangled(nq_onFunctionAbstract) func {
        peek(FunctionDecl) isAbstract = true
    }
    onFunctionself.classRef: unmangled(nq_onFunctionself.classRef) func {
        peek(FunctionDecl) isself.classRef = true
    }
    onFunctionStatic: unmangled(nq_onFunctionStatic) func {
        peek(FunctionDecl) isStatic = true
    }
    onFunctionInline: unmangled(nq_onFunctionInline) func {
        peek(FunctionDecl) isInline = true
    }

    onFunctionFinal: unmangled(nq_onFunctionFinal) func {
        peek(FunctionDecl) isFinal = true
    }

    onFunctionProto: unmangled(nq_onFunctionProto) func {
        peek(FunctionDecl) isProto = true
    }

    onFunctionSuper: unmangled(nq_onFunctionSuper) func {
        peek(FunctionDecl) isSuper = true
    }

    onFunctionSuffix: unmangled(nq_onFunctionSuffix) func (suffix: CString) {
        peek(FunctionDecl) suffix = suffix toString()
    }

    onFunctionArgsStart: unmangled(nq_onFunctionArgsStart) func {
        stack push(peek(FunctionDecl) args)
    }

    onFunctionArgsEnd: unmangled(nq_onFunctionArgsEnd) func {
        pop(ArrayList<Argument>)
    }

    onFunctionReturnType: unmangled(nq_onFunctionReturnType) func (type: Type) {
        peek(FunctionDecl) returnType = type
    }

    onFunctionBody: unmangled(nq_onFunctionBody) func {
        peek(FunctionDecl) hasBody = true
    }

    onFunctionEnd: unmangled(nq_onFunctionEnd) func -> FunctionDecl {
        fDecl := pop(FunctionDecl)

        match(node := peek(Object)) {
            case module =>
                module addFunction(fDecl)
            case tDecl: TypeDecl =>
                tDecl addFunction(fDecl)
            case addon: Addon =>
                addon addFunction(fDecl)
        }
        return fDecl
    }

    /*
     * Function calls
     */

    onFunctionCallStart: unmangled(nq_onFunctionCallStart) func (name: CString) {
        stack push(FunctionCall new(name toString(), token()))
    }

    onFunctionCallSuffix: unmangled(nq_onFunctionCallSuffix) func (suffix: CString) {
        peek(FunctionCall) setSuffix(suffix toString())
    }

    onFunctionCallArg: unmangled(nq_onFunctionCallArg) func (expr: Expression) {
        peek(FunctionCall) args add(expr)
    }

    onFunctionCallEnd: unmangled(nq_onFunctionCallEnd) func -> FunctionCall {
        pop(FunctionCall)
    }

    onFunctionCallExpr: unmangled(nq_onFunctionCallExpr) func (call: FunctionCall, expr: Expression) {
        call expr = expr
    }

    onFunctionCallCombo: unmangled(nq_onFunctionCallCombo) func (call: FunctionCall, expr: Expression) {
        name := call generateTempName("comboRoot")
        call setName(name)
        vDecl := VariableDecl new(null, name, expr, expr token)
        vDecl isGlobal = true # well, that's not true, but at least this way it won't be marked for partialing...
        onStatement(vDecl)
    }

    onFunctionCallChain: unmangled(nq_onFunctionCallChain) func (expr: Expression, call: FunctionCall) -> CallChain {
        match expr {
            case chain: CallChain =>
                chain calls add(call)
                chain
            case =>
                CallChain new(expr, call)
        }
    }

    /*
     * Literals
     */

    onArrayLiteralStart: unmangled(nq_onArrayLiteralStart) func {
        stack push(ArrayLiteral new(token()))
    }

    onArrayLiteralEnd: unmangled(nq_onArrayLiteralEnd) func -> ArrayLiteral {
        pop(ArrayLiteral)
    }

    onTupleStart: unmangled(nq_onTupleStart) func {
        stack push(Tuple new(token()))
    }

    onTupleEnd: unmangled(nq_onTupleEnd) func -> Tuple {
        pop(Tuple)
    }

    onStringLiteral: unmangled(nq_onStringLiteral) func (text: CString) -> StringLiteral {
        StringLiteral new(text toString() replaceAll("\n", "\\n") replaceAll("\t", "\\t"), token())
    }

    onCharLiteral: unmangled(nq_onCharLiteral) func (value: CString) -> CharLiteral {
        CharLiteral new(value toString(), token())
    }

    # statement
    onStatement: unmangled(nq_onStatement) func (stmt: Statement) {
        match stmt {
            case vd: VariableDecl =>
                gotVarDecl(vd)
            case stack: Stack<VariableDecl> =>
                if(stack T inheritsFrom?(VariableDecl)) {
                    for(vd in stack) {
                        gotVarDecl(vd)
                    }
                }
            case =>
                gotStatement(stmt)
        }
    }

    gotStatement: func (stmt: Statement) {
        node := peek(Node)

        match {
            case node instanceOf?(FunctionDecl) =>
                fDecl := node as FunctionDecl
                fDecl body add(stmt)
            case node instanceOf?(ControlStatement) =>
                cStmt := node as ControlStatement
                cStmt body add(stmt)
            case node instanceOf?(ArrayAccess) =>
                aa := node as ArrayAccess
                if(!stmt instanceOf?(Expression)) {
                    params errorHandler onError(SyntaxError new(stmt token, "Expected an expression here, not a statement!"))
                }
                aa indices add(stmt as Expression)
            case node instanceOf?(Module) =>
                if(stmt instanceOf?(VariableDecl)) {
                    vd := stmt as VariableDecl
                    vd setGlobal(true)
                }
                module := node as Module

                spec := getVersion()
                if(spec != null) {
                    vb := VersionBlock new(spec, token())
                    vb getBody() add(stmt)
                    module body add(vb)
                } else {
                    module body add(stmt)
                }
            case node instanceOf?(ClassDecl) =>
                cDecl := node as ClassDecl
                fDecl := (cDecl isMeta) ? cDecl lookupFunction(ClassDecl DEFAULTS_FUNC_NAME, null) : cDecl meta lookupFunction(ClassDecl DEFAULTS_FUNC_NAME, null)
                if(fDecl == null) {
                    fDecl = FunctionDecl new(ClassDecl DEFAULTS_FUNC_NAME, cDecl token)
                    cDecl addFunction(fDecl)
                }
                fDecl getBody() add(stmt)
            case node instanceOf?(ArrayLiteral) =>
                arrayLit := node as ArrayLiteral
                if(!stmt instanceOf?(Expression)) {
                    params errorHandler onError(SyntaxError new(stmt token, "Expected an expression here, not a statement!"))
                }
                arrayLit getElements() add(stmt as Expression)
            case node instanceOf?(Tuple) =>
                tuple := node as Tuple
                if(!stmt instanceOf?(Expression)) {
                    params errorHandler onError(SyntaxError new(stmt token, "Expected an expression here, not a statement!"))
                }
                tuple getElements() add(stmt as Expression)
            case =>
                "[gotStatement] Got a %s, don't know what to do with it, parent = %s\n" printfln(stmt toString(), node class name)
        }
    }

    onArrayAccessStart: unmangled(nq_onArrayAccessStart) func (array: Expression) {
        stack push(ArrayAccess new(array, token()))
    }

    onArrayAccessEnd: unmangled(nq_onArrayAccessEnd) func () -> ArrayAccess {
        pop(ArrayAccess)
    }

    # return
    onReturn: unmangled(nq_onReturn) func (expr: Expression) -> Return {
        Return new(expr, token())
    }

    # variable access
    onVarAccess: unmangled(nq_onVarAccess) func (expr: Expression, name: CString) -> VariableAccess {
        return VariableAccess new(expr, name toString(), token())
    }

    # cast
    onCast: unmangled(nq_onCast) func (expr: Expression, type: Type) -> Cast {
        return Cast new(expr, type, token())
    }

    # block {}
    onBlockStart: unmangled(nq_onBlockStart) func {
        stack push(Block new(token()))
    }

    onBlockEnd: unmangled(nq_onBlockEnd) func -> Block {
        pop(Block)
    }

    # if
    onIfStart: unmangled(nq_onIfStart) func (condition: Expression) {
        stack push(If new(condition, token()))
    }

    onIfEnd: unmangled(nq_onIfEnd) func -> If {
        pop(If)
    }

    # else
    onElseStart: unmangled(nq_onElseStart) func {
        stack push(Else new(token()))
    }

    onElseEnd: unmangled(nq_onElseEnd) func -> Else {
        pop(Else)
    }

    # foreach
    onForeachStart: unmangled(nq_onForeachStart) func (decl, collec: Expression) {
        if(decl instanceOf?(Stack)) {
            decl = decl as Stack<VariableDecl> pop()
        }
        stack push(Foreach new(decl, collec, token()))
    }

    onForeachEnd: unmangled(nq_onForeachEnd) func -> Foreach {
        pop(Foreach)
    }

    # while
    onWhileStart: unmangled(nq_onWhileStart) func (condition: Expression) {
        stack push(While new(condition, token()))
    }

    onWhileEnd: unmangled(nq_onWhileEnd) func -> While {
        pop(While)
    }

    /*
     * Arguments
     */
    onVarArg: unmangled(nq_onVarArg) func (name: CString) {
        peek(List<Node>) add(VarArg new(token(), name ? name toString() : null))
    }

    onTypeArg: unmangled(nq_onTypeArg) func (type: Type) {
        # TODO: add check for extern function (TypeArgs are illegal in non-extern functions.)
        peek(List<Node>) add(Argument new(type, "", token()))
    }

    onDotArg: unmangled(nq_onDotArg) func (name: CString) {
        # TODO: add check for member function
        peek(List<Node>) add(DotArg new(name toString(), token()))
    }

    onAssArg: unmangled(nq_onAssArg) func (name: CString) {
        # TODO: add check for member function
        peek(List<Node>) add(AssArg new(name toString(), token()))
    }

    /*
     * Match & case
     */
    onMatchStart: unmangled(nq_onMatchStart) func {
        stack push(Match new(token()))
    }

    onMatchExpr: unmangled(nq_onMatchExpr) func (v:Expression) {
        peek(Match) setExpr(v)
    }

    onMatchEnd: unmangled(nq_onMatchEnd) func -> Match {
        pop(Match)
    }

    onCaseStart: unmangled(nq_onCaseStart) func {
        stack push(Case new(token()))
    }

    onCaseExpr: unmangled(nq_onCaseExpr) func (v:Expression) {
        peek(Case) setExpr(v)
    }

    onCaseEnd: unmangled(nq_onCaseEnd) func {
        caze := pop(Case)
        peek(Match) addCase(caze)
    }

    /*
     * Try & catch
     */

    onTryStart: unmangled(nq_onTryStart) func {
        stack push(Try new(token()))
    }

    onTryEnd: unmangled(nq_onTryEnd) func -> Try {
        pop(Try)
    }

    onCatchStart: unmangled(nq_onCatchStart) func {
        stack push(Case new(token()))
    }

    onCatchExpr: unmangled(nq_onCatchExpr) func (v: Expression) {
        peek(Case) setExpr(v)
    }

    onCatchEnd: unmangled(nq_onCatchEnd) func {
        caze := pop(Case)
        peek(Try) addCatch(caze)
    }

    onBreak: unmangled(nq_onBreak) func -> FlowControl {
        FlowControl new(FlowAction _break, token())
    }

    onContinue: unmangled(nq_onContinue) func -> FlowControl {
        FlowControl new(FlowAction _continue, token())
    }

    onEquals: unmangled(nq_onEquals) func (left, right: Expression) -> Comparison {
        Comparison new(left, right, CompType equal, token())
    }

    onNotEquals: unmangled(nq_onNotEquals) func (left, right: Expression) -> Comparison {
        Comparison new(left, right, CompType notEqual, token())
    }

    onLessThan: unmangled(nq_onLessThan) func (left, right: Expression) -> Comparison {
        Comparison new(left, right, CompType smallerThan, token())
    }

    onMoreThan: unmangled(nq_onMoreThan) func (left, right: Expression) -> Comparison {
        Comparison new(left, right, CompType greaterThan, token())
    }

    onCmp: unmangled(nq_onCmp) func (left, right: Expression) -> Comparison {
        Comparison new(left, right, CompType compare, token())
    }

    onLessThanOrEqual: unmangled(nq_onLessThanOrEqual) func (left, right: Expression) -> Comparison {
        Comparison new(left, right, CompType smallerOrEqual, token())
    }
    onMoreThanOrEqual: unmangled(nq_onMoreThanOrEqual) func (left, right: Expression) -> Comparison {
        Comparison new(left, right, CompType greaterOrEqual, token())
    }

    onDecLiteral: unmangled(nq_onDecLiteral) func (value: CString) -> IntLiteral {
        IntLiteral new(value toString() replaceAll("_", "") toLLong(), token())
    }

    onOctLiteral: unmangled(nq_onOctLiteral) func (value: CString) -> IntLiteral {
        IntLiteral new(value toString() replaceAll("_", "") substring(2) toLLong(8), token())
    }

    onBinLiteral: unmangled(nq_onBinLiteral) func (value: CString) -> IntLiteral {
        IntLiteral new(value toString() replaceAll("_", "") substring(2) toLLong(2), token())
    }

    onHexLiteral: unmangled(nq_onHexLiteral) func (value: CString) -> IntLiteral {
        IntLiteral new(value toString() replaceAll("_", "") toLLong(16), token())
    }

    onFloatLiteral: unmangled(nq_onFloatLiteral) func (value: CString) -> FloatLiteral {
        FloatLiteral new(value toString() replaceAll("_", ""), token())
    }

    onBoolLiteral: unmangled(nq_onBoolLiteral) func (value: Bool) -> BoolLiteral {
        BoolLiteral new(value, token())
    }

    onNull: unmangled(nq_onNull) func -> NullLiteral {
        NullLiteral new(token())
    }

    onTernary: unmangled(nq_onTernary) func (condition, ifTrue, ifFalse: Expression) -> Ternary {
        Ternary new(condition, ifTrue, ifFalse, token())
    }

    onDoubleArrow: unmangled(nq_onDoubleArrow) func(left, right: Expression) -> BinaryOp {
        BinaryOp new(left, right, OpType doubleArr, token())
    }

    onAssignAdd: unmangled(nq_onAssignAdd) func (left, right: Expression) -> BinaryOp {
        BinaryOp new(left, right, OpType addAss, token())
    }

    onAssignSub: unmangled(nq_onAssignSub) func (left, right: Expression) -> BinaryOp {
        BinaryOp new(left, right, OpType subAss, token())
    }

    onAssignMul: unmangled(nq_onAssignMul) func (left, right: Expression) -> BinaryOp {
        BinaryOp new(left, right, OpType mulAss, token())
    }

    onAssignExp: unmangled(nq_onAssignExp) func (left, right: Expression) -> BinaryOp {
        BinaryOp new(left, right, OpType expAss, token())
    }

    onAssignDiv: unmangled(nq_onAssignDiv) func (left, right: Expression) -> BinaryOp {
        BinaryOp new(left, right, OpType divAss, token())
    }

    onAssignAnd: unmangled(nq_onAssignAnd) func (left, right: Expression) -> BinaryOp {
        BinaryOp new(left, right, OpType bAndAss, token())
    }

    onAssignOr: unmangled(nq_onAssignOr) func (left, right: Expression) -> BinaryOp {
        BinaryOp new(left, right, OpType bOrAss, token())
    }

    onAssignXor: unmangled(nq_onAssignXor) func (left, right: Expression) -> BinaryOp {
        BinaryOp new(left, right, OpType bXorAss, token())
    }

    onAssign: unmangled(nq_onAssign) func (left, right: Expression) -> BinaryOp {
        BinaryOp new(left, right, OpType ass, token())
    }

    onAssignLeftShift: unmangled(nq_onAssignLeftShift) func (left, right: Expression) -> BinaryOp {
        BinaryOp new(left, right, OpType lshiftAss, token())
    }

    onAssignRightShift: unmangled(nq_onAssignRightShift) func (left, right: Expression) -> BinaryOp {
        BinaryOp new(left, right, OpType rshiftAss, token())
    }

    onAdd: unmangled(nq_onAdd) func (left, right: Expression) -> BinaryOp {
        BinaryOp new(left, right, OpType add, token())
    }

    onSub: unmangled(nq_onSub) func (left, right: Expression) -> BinaryOp {
        BinaryOp new(left, right, OpType sub, token())
    }

    onMod: unmangled(nq_onMod) func (left, right: Expression) -> BinaryOp {
        BinaryOp new(left, right, OpType mod, token())
    }

    onMul: unmangled(nq_onMul) func (left, right: Expression) -> BinaryOp {
        BinaryOp new(left, right, OpType mul, token())
    }

    onExp: unmangled(nq_onExp) func (left, right: Expression) -> BinaryOp {
        BinaryOp new(left, right, OpType exp, token())
    }

    onDiv: unmangled(nq_onDiv) func (left, right: Expression) -> BinaryOp {
        BinaryOp new(left, right, OpType div, token())
    }

    onRangeLiteral: unmangled(nq_onRangeLiteral) func (left, right: Expression) -> RangeLiteral {
        RangeLiteral new(left, right, token())
    }

    onBinaryLeftShift: unmangled(nq_onBinaryLeftShift) func (left, right: Expression) -> BinaryOp {
        BinaryOp new(left, right, OpType lshift, token())
    }

    onBinaryRightShift: unmangled(nq_onBinaryRightShift) func (left, right: Expression) -> BinaryOp {
        BinaryOp new(left, right, OpType rshift, token())
    }

    onLogicalOr: unmangled(nq_onLogicalOr) func (left, right: Expression) -> BinaryOp {
        BinaryOp new(left, right, OpType or, token())
    }

    onLogicalAnd: unmangled(nq_onLogicalAnd) func (left, right: Expression) -> BinaryOp {
        BinaryOp new(left, right, OpType and, token())
    }

    onBinaryOr: unmangled(nq_onBinaryOr) func (left, right: Expression) -> BinaryOp {
        BinaryOp new(left, right, OpType bOr, token())
    }

    onBinaryXor: unmangled(nq_onBinaryXor) func (left, right: Expression) -> BinaryOp {
        BinaryOp new(left, right, OpType bXor, token())
    }

    onBinaryAnd: unmangled(nq_onBinaryAnd) func (left, right: Expression) -> BinaryOp {
        BinaryOp new(left, right, OpType bAnd, token())
    }

    onLogicalNot: unmangled(nq_onLogicalNot) func (inner: Expression) -> UnaryOp {
        UnaryOp new(inner, UnaryOpType logicalNot, token())
    }

    onBinaryNot: unmangled(nq_onBinaryNot) func (inner: Expression) -> UnaryOp {
        UnaryOp new(inner, UnaryOpType binaryNot, token())
    }

    onUnaryMinus: unmangled(nq_onUnaryMinus) func (inner: Expression) -> UnaryOp {
        UnaryOp new(inner, UnaryOpType unaryMinus, token())
    }

    onParenthesis: unmangled(nq_onParenthesis) func (inner: Expression) -> Parenthesis {
        Parenthesis new(inner, token())
    }

    onTypeGenericArgument: unmangled(nq_onTypeGenericArgument) func (type: Type, typeInner: Type) {
        type addTypeArg(VariableAccess new(typeInner, token()))
    }


    onFuncTypeGenericArgument: unmangled(nq_onFuncTypeGenericArgument) func (type: FuncType, cname: CString) {
        name := cname toString()

        vDecl := VariableDecl new(BaseType new("Class", token()), name, token())
        type addTypeArg(vDecl)
    }

    onGenericArgument: unmangled(nq_onGenericArgument) func (cname: CString) {
        node := peek(Node)
        name := cname toString()

        vDecl := VariableDecl new(BaseType new("Class", token()), name, token())

        done := false
        if(node instanceOf?(Declaration)) {
            done = node as Declaration addTypeArg(vDecl)
        }

        if(!done) params errorHandler onError(InternalError new(token(), "Unexpected type argument in a %s declaration!" format(node class name)))

    }

    onAddressOf: unmangled(nq_onAddressOf) func (inner: Expression) -> AddressOf {
        AddressOf new(inner, inner token)
    }

    onDereference: unmangled(nq_onDereference) func (inner: Expression) -> Dereference {
        Dereference new(inner, token())
    }

    token: func -> Token {
        Token new(tokenPos[0], tokenPos[1], module)
    }

    peek: func <T> (T: Class) -> T {
        node := stack peek() as Node
        if(!node instanceOf?(T)) {
            params errorHandler onError(InternalError new(token(), "Should've peek'd a %s, but peek'd a %s. Stack = %s" format(T name, node class name, stackRepr())))
        }
        return node
    }

    pop: func <T> (T: Class) -> T {
        node := stack pop() as Node
        if(!node instanceOf?(T)) {
            params errorHandler onError(InternalError new(token(), "Should've pop'd a %s, but pop'd a %s. Stack = %s" format(T name, node class name, stackRepr())))
        }
        return node
    }

    stackRepr: func -> String {
        sb := Buffer new()
        for(e in stack) {
            sb append(e class name). append(", ")
        }
        sb toString()
    }

    getVersion: func -> VersionSpec {
        spec := null as VersionSpec

        for(v in versionStack) {
            if(spec) {
                spec = VersionAnd new(spec, v, spec token)
            } else {
                spec = v
            }
        }

        return spec
    }

end

# position in stream handling
nq_setTokenPositionPointer: unmangled func (this: AstBuilder, tokenPos: Int*) { this tokenPos = tokenPos }

# string handling
nq_StringClone: unmangled func (string: CString) -> CString             { string clone() }
nq_mangleIdents: unmangled func (string: CString) -> CString            {
    if(string == "this") return "_this" toCString()
    string
}
nq_trailingQuest: unmangled func (string: CString) -> CString           { (string toString() + "__quest") toCString() }
nq_trailingBang:  unmangled func (string: CString) -> CString           { (string toString() + "__bang")  toCString() }
nq_error: unmangled func (this: AstBuilder, errorID: Int, message: CString, index: Int) {
    msg : String = (message == null) ? null : message toString()
    this error(errorID, msg, index)
}

SyntaxError: class extends Error {
    init: super func ~tokenMessage
}

