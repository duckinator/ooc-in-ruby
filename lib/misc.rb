__END__

# TODO

Module  =  ModuleCore
          | WS ( !EOL . )*
          EOL { tokenPos; char *message = "Expected include, import, statement or declaration\n";
            if(G->buf[core->token[0]] == _CBRACK) { message = "Unmatched closing bracket"; }
            nq_error(core->this, NQE_EXP_INC_IMP_STMT_OR_DECL, message, core->token[0]);
          }

ModuleCore = (WS 'version' { tokenPos }
              WS '('
              - spec: VersionSpec
              WS ')'
              ((
              - '{' { nq_onVersionStart(core->this, spec) }
              WS ModuleCore* WS
              - '}' { nq_onVersionEnd(core->this) }
              )
              |
              (
              - s:Stmt { nq_onVersionStart(core->this, spec); nq_onStatement(core->this, s); nq_onVersionEnd(core->this) }
              ))
              (
                  WS 'else' - 'version' { tokenPos }
                  WS '('
                  - elseSpec: VersionSpec
                  WS ')'
                  ((
                  - '{' { spec = nq_onVersionElseIfStart(core->this, spec, elseSpec) }
                  WS ModuleCore* WS
                  - '}' { nq_onVersionEnd(core->this) }
                  )
                  |
                  (
                  - s:Stmt { spec = nq_onVersionElseIfStart(core->this, spec, elseSpec); nq_onStatement(core->this, s); nq_onVersionEnd(core->this) }
                  ))
              )*
              (
                  WS 'else' { tokenPos }
                  ((
                  - '{' { nq_onVersionElseStart(core->this, spec) }
                  WS ModuleCore* WS
                  - '}' { nq_onVersionEnd(core->this) }
                  )
                  |
                  (
                  - s:Stmt { nq_onVersionElseStart(core->this, spec); nq_onStatement(core->this, s); nq_onVersionEnd(core->this) }
                  ))
              )?
            )
          |(WS Include WS
          | WS Import WS
          | WS Use WS
          | WS Decl WS
          | WS stmt:Stmt WS { nq_onStatement(core->this, stmt) }
          )

VersionSpec = ((- '(' - l:VersionSpec - ')') | (l:VersionCore))
                ((- '&&' { tokenPos; } - r:VersionSpec { l=$$=nq_onVersionAnd(core->this, l, r); }) |
                 (- '||' { tokenPos; } - r:VersionSpec { l=$$=nq_onVersionOr (core->this, l, r); }))*

VersionCore = (VersionNegation | VersionName)

VersionName = - < [a-zA-Z0-9_]+ > { tokenPos; $$=nq_onVersionName(core->this, yytext) }
VersionNegation = - '!' { tokenPos; } - spec:VersionSpec { $$=nq_onVersionNegation(core->this, spec) }

Use = USE_KW [ \t]
      - UseCore
      (
      - ','
      - UseCore
      )*

UseCore = < ([A-Za-z0-9/._] | '-')+ > { tokenPos; nq_onUse(core->this, nq_StringClone(yytext)) }

Include = INCLUDE_KW [ \t]
          - IncludeCore
          (
          - ','
          - IncludeCore
          )*

DefineName  = < ([A-Za-z0-9_/._] | '-')+ > { $$=nq_StringClone(yytext) }
DefineValue = ('=' < ([A-Za-z0-9_/._] | '-')+ >)? { $$=nq_StringClone(yytext) }
            | { $$=""; }

IncludeCore = < ([A-Za-z0-9/._] | '-')+ >  { tokenPos; nq_onInclude(core->this, nq_StringClone(yytext)) }
          (- '|'
           - '('
            - defineName:DefineName defineVal:DefineValue { nq_onIncludeDefine(core->this, defineName, defineVal) }
           (- ','
            - defineName:DefineName defineVal:DefineValue { nq_onIncludeDefine(core->this, defineName, defineVal) }
           )*
           - ')'
          )?

Import  = IMPORT_KW [ \t]
          - ImportAtom
          (
          ',' WS
          - ImportAtom
          )*

ImportAtom = path:ImportPath
            ((name:ImportName { tokenPosPlusOne; }             { nq_onImport(core->this, (char*) path, (char*) name) }
             (- INTO_KW - namespace:IDENT               { nq_onImportNamespace(core->this, (char*) namespace, 1) })?
             ) | (
            '[' { core->importQuantity = 0; }
            (name:ImportName { tokenPosPlusOne; } - ',' WS   { core->importQuantity++; nq_onImport(core->this, (char*) path, (char*) name) })*
            (name:ImportName { tokenPosPlusOne; }              { core->importQuantity++; nq_onImport(core->this, (char*) path, (char*) name) })
            ']'
             (- INTO_KW - namespace:IDENT               { nq_onImportNamespace(core->this, (char*) namespace, core->importQuantity) })?
            ))

ImportPath = < (([A-Za-z_0-9] | "." | "-")+ "/")* > { $$=nq_StringClone(yytext) }
ImportName = < ([A-Za-z_0-9] | "-")+ >                { $$=nq_StringClone(yytext) }


Decl    = ( ClassDecl
          | CoverDecl
          | ExtendDecl
          | EnumDecl
          | InterfaceDecl
          | OperatorDecl
          | FunctionDecl
          | PropertyDecl
          | vd:VariableDecl Terminator+ { nq_onStatement(core->this, vd) }
          )

GenericArguments =
            (
            - LESSTHAN
            - name:IDENT         { nq_onGenericArgument(core->this, name) }
            (
            - ','
            - name:IDENT         { nq_onGenericArgument(core->this, name) }
            )*
            MORETHAN -
            )

OperatorDecl =
            OPERATOR_KW { tokenPos; } -
            - < ( "=>" | "<=>"| ">>="| "<<="| ">>" | "<<"
                | ">=" | "<=" | "!=" | "==" | ">" | "<" | "!"
                | "+=" | "-=" | "*=" | "**="| "/=" | "+" | "-" | "**" | "/" | "*" | "="
                | "[]="| "[]" | "&&" | "||" | "%" | "as" | "implicit as"
                | "&=" | "|=" | "^=" | "&"  | "|" | "^" | "~"
                ) >
            { nq_onOperatorStart(core->this, yytext) } -
            FunctionDeclBody
            { nq_onOperatorEnd(core->this) }

FunctionDecl = SuperFunctionDecl | RegularFunctionDecl

SuperFunctionDecl = name:IDENT - COLON - 'super' - FUNC_KW -
            { tokenPos; nq_onFunctionStart(core->this, name, ""); nq_onFunctionSuper(core->this) }
            # optional suffix
            (
            - '~' suffix:IDENT { nq_onFunctionSuffix(core->this, suffix) }
            )?
            { $$=nq_onFunctionEnd(core->this) }

RegularFunctionDecl =
            doc: OocDoc

            name:IDENT { tokenPos; nq_onFunctionStart(core->this, name, doc) }
            - COLON

            # modifiers
            (-  ( externName:ExternName  { nq_onFunctionExtern(core->this, externName) }
                | unmangledName:UnmangledName { nq_onFunctionUnmangled(core->this, unmangledName) }
                | ABSTRACT_KW { nq_onFunctionAbstract(core->this) }
                | STATIC_KW   { nq_onFunctionStatic(core->this) }
                | INLINE_KW   { nq_onFunctionInline(core->this) }
                | FINAL_KW    { nq_onFunctionFinal(core->this) }
                | PROTO_KW    { nq_onFunctionProto(core->this) }
                )
            )*

            FunctionDeclCore

AnonymousFunctionDecl = { nq_onFunctionStart(core->this, "", "") } FunctionDeclCore

FunctionDeclCore =
            - FUNC_KW
            ('@' { nq_onFunctionThisRef(core->this) })?

            # optional suffix
            (
            - '~' suffix:IDENT { nq_onFunctionSuffix(core->this, suffix) }
            )?

            FunctionDeclBody


FunctionDeclBody = (
            GenericArguments?

            # arguments are optional
            (
                WS '(' { nq_onFunctionArgsStart(core->this) }
                (          WS Argument WS
                    (',' WS Argument WS)*
                )?
                WS CLOS_PAREN ~{ nq_error(core->this, NQE_EXP_ARG, "Malformed function argument (remember, it's `name: Type` in ooc, not `Type name`)\n", G->pos + G->offset) }
                              { nq_onFunctionArgsEnd(core->this) }
            )?
            
            # optional suffix
            (
            - '~' suffix:IDENT { nq_error(core->this, NQE_MISPLACED_SUFFIX, "Misplaced function suffix (remember, it's `name: func ~suffix (args)`, not `name: func (args) ~suffix`", core->token[0]) }
            )?

            # return type is optional
            (
                - R_ARROW
                - t:Type ~{ nq_error(core->this, NQE_EXP_RET_TYPE, "Missing return type.\n", G->pos + G->offset) }
                          { nq_onFunctionReturnType(core->this, t) }
            )?

            # body is optional (for abstract/extern-named functions)
            (
                { nq_onFunctionBody(core->this); }
                WS '{' WS
                (WS
                (s:Stmt  { nq_onStatement(core->this, s) })
                WS)*
                WS CLOS_BRACK ~{ rewindWhiteSpace; nq_error(core->this, NQE_EXP_STATEMENT_OR_CLOSING_BRACKET, "Malformed statement or closing bracket missing\n", G->pos + G->offset) }
            )?
            ) { $$=nq_onFunctionEnd(core->this); }

Argument    = ( (DOT dotName:IDENT -)    { tokenPos; nq_onDotArg(core->this, dotName) }
              | (ASS assName:IDENT -)    { tokenPos; nq_onAssArg(core->this, assName) }
              | vd:VariableDecl          { tokenPos; nq_onStatement(core->this, vd) }
              | (vargName:IDENT - ":" - "..." -) { tokenPos; nq_onVarArg(core->this, vargName) } # ooc varargs
              | type:Type                { tokenPos; nq_onTypeArg(core->this, type) }
              | "..."                    { tokenPos; nq_onVarArg(core->this, NULL) } # C varargs
              )


ClassDecl   = (
            doc: OocDoc

            className:IDENT { tokenPos; nq_onClassStart(core->this, className, doc) }
            - COLON

            # modifiers
            (-  ( ExternName
                | ABSTRACT_KW { nq_onClassAbstract(core->this) }
                | FINAL_KW    { nq_onClassFinal(core->this) }
                )
            )*

            - CLASS_KW

            GenericArguments?

            # subclassing
            (
            - EXTENDS_KW - t:Type { nq_onClassExtends(core->this, t) }
            )?

            # interface subclassing
            (
            - IMPLEMENTS_KW
                     - t:Type { nq_onClassImplements(core->this, t) }
            (- ',' - t:Type { nq_onClassImplements(core->this, t) })*
            )?

            { nq_onClassBody(core->this); }

            (
                WS '{' WS

                # classdecl contents
                (WS
                    ( vd:VariableDecl { tokenPos; nq_onStatement(core->this, vd); } Terminator+
                    | pd:PropertyDecl { tokenPos; nq_onStatement(core->this, pd); }
                    | fd:FunctionDecl
                    | stmt:Stmt { tokenPos; nq_onStatement(core->this, stmt); }
                    )
                WS)*

                WS
                CLOS_BRACK ~{ nq_error(core->this, NQE_EXP_VAR_OR_FUNC_DECL, "Expected variable declaration or function declaration\n", G->pos + G->offset); }
            )
            ) { nq_onClassEnd(core->this) }

EnumDecl    = (
            doc: OocDoc

            enumName:IDENT { tokenPos; nq_onEnumStart(core->this, enumName, doc); }
            - COLON

            # modifiers (extern)
            (- externName:ExternName { nq_onEnumExtern(core->this, externName); })?

            - ENUM_KW

            # optional from-type
            (- FROM_KW - fromType:Type { tokenPos; nq_onEnumFromType(core->this, fromType); })?

            # increment expression (ex: *2 or +1)
            (
            - '('
            - op:EnumIncrementOper WS step:IntLiteral { nq_onEnumIncrementExpr(core->this, op, step); }
            - ')'
            )?

            (
                WS '{' WS

                # enumeration elements
                (EnumElement
                (
                    (Terminator+ WS FunctionDecl) |
                    ((',' | Terminator+) WS EnumElement)
                )*
                )?

                WS
                CLOS_BRACK ~{ nq_error(core->this, NQE_EXP_VAR_OR_FUNC_DECL, "Expected enum element!\n", G->pos + G->offset); }
            )

            ) { tokenPos; nq_onEnumEnd(core->this) }

EnumElement = (
                doc: OocDoc

                i:IDENT { tokenPos; nq_onEnumElementStart(core->this, i, doc); }
                - ( ASS value:Expr { nq_onEnumElementValue(core->this, value); }
                  | COLON
                    - externName:ExternName { nq_onEnumElementExtern(core->this, externName); }
                  )?
            ) { nq_onEnumElementEnd(core->this) }

EnumIncrementOper =  ( STAR { $$='*'; }
                     | PLUS { $$='+'; }
                     )

ExtendDecl  = (
            doc: OocDoc

            "extend" WS
            extendedType: Type { tokenPos; nq_onExtendStart(core->this, extendedType, doc); }

            # body
            (
                WS '{' WS

                # coverdecl content
                (WS
                    ( fd:FunctionDecl
                    )
                WS)*

                WS
                CLOS_BRACK ~{ nq_error(core->this, NQE_EXP_VAR_OR_FUNC_DECL, "Expected or function declaration\n", G->pos + G->offset); }
            )

            { nq_onExtendEnd(core->this); }
            )

CoverDecl   = (
            doc: OocDoc

            coverName:IDENT { tokenPos; nq_onCoverStart(core->this, coverName, doc); }
            - COLON

            # modifiers
            (- externName:ExternName { nq_onCoverExtern(core->this, externName); })?

            - COVER_KW

            GenericArguments?

            # covering another type
            (
            - FROM_KW - t:Type { nq_onCoverFromType(core->this, t) }
            )?

            # extending another type
            (
            - EXTENDS_KW - t:Type { nq_onCoverExtends(core->this, t) }
            )?

            # interface subclassing
            (
            - IMPLEMENTS_KW
                     - t:Type { nq_onCoverImplements(core->this, t) }
            (- ',' - t:Type { nq_onCoverImplements(core->this, t) })*
            )?

            # body is optional for covers
            (
                WS '{' WS

                # coverdecl content
                (WS
                    ( vd:VariableDecl { tokenPos; nq_onStatement(core->this, vd); } Terminator+
                    | pd:PropertyDecl { tokenPos; nq_onStatement(core->this, pd); }
                    | fd:FunctionDecl
                    )
                WS)*

                WS
                CLOS_BRACK  ~{ nq_error(core->this, NQE_EXP_VAR_OR_FUNC_DECL, "Expected variable declaration or function declaration\n", G->pos + G->offset); }
            )?
            )
            { nq_onCoverEnd(core->this); }

InterfaceDecl = (
            doc: OocDoc

            interfaceName:IDENT { tokenPos; nq_onInterfaceStart(core->this, interfaceName, doc); }
            - COLON

            - INTERFACE_KW

            GenericArguments?

            # extending another interface
            (
            - EXTENDS_KW - t:Type { nq_onInterfaceExtends(core->this, t) }
            )?

            # interface subclassing
            (
            - IMPLEMENTS_KW
                     - t:Type { nq_onClassImplements(core->this, t) }
            (- ',' - t:Type { nq_onClassImplements(core->this, t) })*
            )?

            # body is required for interfaces
            (
                WS '{' WS

                # interface content
                (WS
                    fd:FunctionDecl
                WS)*

                WS
                CLOS_BRACK  ~{ nq_error(core->this, NQE_EXP_VAR_OR_FUNC_DECL, "Expected function declaration\n", G->pos + G->offset); }
            )
            )
            { nq_onInterfaceEnd(core->this); }

ExternName = EXTERN_KW { $$="" }
              (
              - '('
              - < [A-Za-z_] [A-Za-z0-9_]* > { $$=yytext } # is that correct? should it be $$=$$? what's happening?
              - ')'
              )?

UnmangledName = UNMANGLED_KW { $$="" }
             (
             - '('
             - unmangledName:IDENT { $$=unmangledName }
             - ')'
             )?

VarDeclFromExpr = ( doc: OocDoc

                    ( i:IDENT   { tokenPos; nq_onVarDeclStart(core->this); nq_onVarDeclName (core->this, i,   doc); }
                    | tup:Tuple { nq_onVarDeclStart(core->this); nq_onVarDeclTuple(core->this, tup); })
                  - ASS_DECL
                  (-
                    (
                        STATIC_KW { nq_onVarDeclStatic(core->this); }
                      | CONST_KW  { nq_onVarDeclConst (core->this); }
                      | PROTO_KW  { nq_onVarDeclProto (core->this); }
                    ) &[^A-Za-z_0-9]
                  )*
                  - r:Expr { nq_onVarDeclExpr(core->this, r); }
                  - { $$=nq_onVarDeclEnd(core->this); }
                  )

ConventionalVarDecl =
            { nq_onVarDeclStart(core->this); }

            (
            doc: OocDoc
            varDeclName:IDENT { tokenPos; nq_onVarDeclName(core->this, varDeclName, doc); }
            (- ASS - Expr { nq_onVarDeclExpr(core->this, $$); })?

            # multi-decls
            (
            - ','
            doc: OocDoc
            WS nextDeclName:IDENT { nq_onVarDeclName(core->this, nextDeclName, doc); }
            (- ASS - Expr { nq_onVarDeclExpr(core->this, $$); })?
            -
            )*

            WS COLON WS
            (-
              (
                  STATIC_KW { nq_onVarDeclStatic(core->this); }
                | CONST_KW  { nq_onVarDeclConst (core->this); }
                | PROTO_KW  { nq_onVarDeclProto (core->this); }
                | externName:ExternName { nq_onVarDeclExtern(core->this, externName); }
                | unmangledName:UnmangledName { nq_onVarDeclUnmangled(core->this, unmangledName); }
              )
            )*
            WS Type { nq_onVarDeclType(core->this, $$); }
            (- ASS - Expr { nq_onVarDeclExpr(core->this, $$); })?
            )  { $$=nq_onVarDeclEnd(core->this); }

VariableDecl = (v:VarDeclFromExpr     { $$=v })
             | (v:ConventionalVarDecl { $$=v })

PropertyDecl =
           (
           doc: OocDoc
           propertyName:IDENT { tokenPos; nq_onPropertyDeclStart(core->this, propertyName, doc); }

           WS COLON WS

           (STATIC_KW { nq_onPropertyDeclStatic(core->this); })?
           WS

           Type { nq_onPropertyDeclType(core->this, $$); }

           WS '{' WS
           PropertyDeclCore
           WS '}' WS

           ) { $$=nq_onPropertyDeclEnd(core->this); }

PropertyDeclCore =
           (
               PropertyDeclGetter
             | PropertyDeclSetter
           )*

PropertyDeclGetter =
           doc: OocDoc

           { nq_onPropertyDeclGetterStart(core->this, doc); }
           WS GET_KW WS
           (
             COLON
             WS
             externName:ExternName { nq_onFunctionExtern(core->this, externName); }
           )?
           ('{'
                (WS
                (s:Stmt  { nq_onStatement(core->this, s) })
                WS)*
           '}')?
           { $$=nq_onPropertyDeclGetterEnd(core->this); }

PropertyDeclSetter =
           doc: OocDoc

           { nq_onPropertyDeclSetterStart(core->this, doc); }
           WS SET_KW WS
           (
             COLON
             WS
             externName:ExternName { nq_onFunctionExtern(core->this, externName); }
           )?
           ('(' WS
                (
                      (argName:IDENT       { nq_onPropertyDeclSetterArgument(core->this, argName, 1); })
                    | (ASS assName:IDENT - { nq_onPropertyDeclSetterArgument(core->this, assName, 0); })
                )
           ')' WS
           '{'
                (WS
                (s:Stmt  { nq_onStatement(core->this, s) })
                WS)*
           '}')?
           { $$=nq_onPropertyDeclSetterEnd(core->this); }

TypeBase = FuncType |
          (< { tokenPos; core->typeBuffer[0]='\0'; } (CONST_KW -)?
            (
                ( "unsigned"                                  { strcat(core->typeBuffer, "unsigned "); } -
                | "signed"                                    { strcat(core->typeBuffer, "signed "); } -
                | "long" &(- ("long" | "double" | "int"))     { strcat(core->typeBuffer, "long "); } -
                | "struct"			                          { strcat(core->typeBuffer, "struct "); } -
                | "union"			                          { strcat(core->typeBuffer, "union "); } -
                )
            - )*
            rest:IDENT { strcat(core->typeBuffer, rest); }
          > { $$=nq_onTypeNew(core->this, core->typeBuffer); })

# a GenericType is just like a Type but with non-optional generic type arguments
# it's used when we have to decide between a Type and a VariableAccess
GenericType
        = (
           temp: Old # When entering the TypeBase rule, i gets overwritten, so we just use a dummy rule to store it
           - i:IDENT { temp=nq_StringClone(i); }
           - t:TypeBase !FuncType { nq_onTypeNamespace(core->this, t, temp); }
           - '<' - t2:Type { nq_onTypeGenericArgument(core->this, t, t2); }
          (- ','    - t2:Type { nq_onTypeGenericArgument(core->this, t, t2); })*
           - '>'
           - ('*' { t=$$=nq_onTypePointer  (core->this, t); }
          |   '@' { t=$$=nq_onTypeReference(core->this, t); }
          | "[" WS { inner=NULL; } - inner:Expr? "]" { t=$$=nq_onTypeBrackets(core->this, t, inner); }
          )*
          - { $$=t; }
          ) |
          (t:TypeBase
           - '<' - t2:Type { nq_onTypeGenericArgument(core->this, t, t2); }
          (- ','    - t2:Type { nq_onTypeGenericArgument(core->this, t, t2); })*
           - '>'
           - ('*' { t=$$=nq_onTypePointer  (core->this, t); }
          |   '@' { t=$$=nq_onTypeReference(core->this, t); }
          | "[" WS { inner=NULL; } - inner:Expr? "]" { t=$$=nq_onTypeBrackets(core->this, t, inner); }
          )*
          - { $$=t; })

Type    = list:TypeList { $$=list; } | (
          t:TypeBase
          (- '<' - genType:Type { nq_onTypeGenericArgument(core->this, t, genType); }
          (- ','    - genType:Type { nq_onTypeGenericArgument(core->this, t, genType); })*
           - '>')?
          - (STAR { t=$$=nq_onTypePointer  (core->this, t); }
          |  '@'   { t=$$=nq_onTypeReference(core->this, t); }
          | "[" WS { inner=NULL; } - inner:Expr? "]" { t=$$=nq_onTypeBrackets(core->this, t, inner); }
          )*
          - { $$=t; }) |
          ('('
           temp: Old # When entering the TypeBase rule, i gets overwritten, so we just use a dummy rule to store it
           - i:IDENT { temp=nq_StringClone(i); }
           - t:TypeBase !FuncType { nq_onTypeNamespace(core->this, t, temp); }
           (- '<' - genType:Type { nq_onTypeGenericArgument(core->this, t, genType); }
          (- ','    - genType:Type { nq_onTypeGenericArgument(core->this, t, genType); })*
           - '>')?
          - (STAR { t=$$=nq_onTypePointer  (core->this, t); }
          |  '@'   { t=$$=nq_onTypeReference(core->this, t); }
          | "[" WS { inner=NULL; } - inner:Expr? "]" { t=$$=nq_onTypeBrackets(core->this, t, inner); }
          )*
          - { $$=t; }
           ')'
          )


TypeListCore = { $$=nq_onTypeList(core->this); }
TypeList = '(' WS list:TypeListCore
                      elem:Type { nq_onTypeListElement(core->this, list, elem) }
           (WS ',' WS elem:Type { nq_onTypeListElement(core->this, list, elem) })*
           ')' -
           { $$=list; }

FuncTypeCore = "Func" &[^A-Za-z0-9_] { tokenPos; $$=nq_onFuncTypeNew(core->this); }

FuncType  = funcType:FuncTypeCore
            (- '<' - genType:IDENT { nq_onFuncTypeGenericArgument(core->this, funcType, genType); }
            (- ',' - genType:IDENT { nq_onFuncTypeGenericArgument(core->this, funcType, genType); })*
            - '>')?
            (
            - '('
            (    - argType:Type { nq_onFuncTypeArgument(core->this, funcType, argType); }
            (',' - argType:Type { nq_onFuncTypeArgument(core->this, funcType, argType); })*
            )?
            ("..." - { nq_onFuncTypeVarArg(core->this, funcType); })?
            - ')'
            )?
            (- '->'
             - returnType:Type { nq_onFuncTypeReturnType(core->this, funcType, returnType); }
            )?
            { $$=funcType; }
