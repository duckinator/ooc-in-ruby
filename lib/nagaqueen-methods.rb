
# This is the accompanying module for what's created in
# Init_nagaqueen() in ruby_nagaqueen.c.
#
# Unfortunately, nagaqueen seems biased towards rock (self-hosting ooc compiler),
# and this leads to most functions explicitly passing 'this'/'self',
# so instead of mutilating nagaqueen.c I simply called it _.
#
# I recommend not referencing _ at all. It seems to result in a segfault of the
# ruby interpreter. Yay!

module Nagaqueen
  class << self
    def setTokenPositionPointer (tokenPos)
      @tokenPos = tokenPos
    end

    def StringClone (string)
      string.dup
    end

    def trailingQuest (string)
      string + "__quest"
    end

    def trailingBang (string)
      string + "__bang"
    end

#    def onUse (name)
#    end

#    def onInclude (path)
#    end

#    def onIncludeDefine (name, value)
#    end

#    def onImport (path, name)
#    end

#    def onImportNamespace (namespace, quantity)
#    end

#    def onVersionName (name)
#    end

#    def onVersionNegation (spec)
#    end

#    def onVersionAnd (specLeft, specRight)
#    end

#    def onVersionOr (specLeft, specRight)
#    end

#    def onVersionStart (spec)
#    end

#    def onVersionElseIfStart (notSpec, elseSpec)
#    end

#    def onVersionElseStart (notSpec)
#    end

#    def onVersionEnd
#    end

#    def onExtendStart (type, doc)
#    end

#    def onExtendEnd
#    end

#    def onCoverStart (name, doc)
#    end

#    def onCoverExtern (externName)
#    end

#    def onCoverFromType (type)
#    end

#    def onCoverExtends (type)
#    end

#    def onCoverImplements (type)
#    end

#    def onCoverEnd
#    end

#    def onEnumStart (name, doc)
#    end

#    def onEnumExtern (externName)
#    end

#    def onEnumFromType (fromType)
#    end

#    def onEnumIncrementExpr (oper, step)
#    end

#    def onEnumElementStart (name, doc)
#    end

#    def onEnumElementValue (value)
#    end

#    def onEnumElementExtern (externName)
#    end

#    def onEnumElementEnd
#    end

#    def onEnumEnd
#    end

#    def onClassStart (name, doc)
#    end

#    def onClassAbstract
#    end

#    def onClassFinal
#    end

#    def onClassExtends (type)
#    end

#    def onClassImplements (type)
#    end

#    def onClassBody
#    end

#    def onClassEnd
#    end

#    def onInterfaceStart (name, doc)
#    end

#    def onInterfaceExtends (type)
#    end

#    def onInterfaceEnd
#    end

#    def onPropertyDeclStart (name, doc)
#    end

#    def onPropertyDeclStatic
#    end

#    def onPropertyDeclType (type)
#    end

#    def onPropertyDeclEnd
#    end

#    def onPropertyDeclGetterStart (doc)
#    end

#    def onPropertyDeclGetterEnd
#    end

#    def onPropertyDeclSetterStart (doc)
#    end

#    def onPropertyDeclSetterArgument (name, conventional)
#    end

#    def onPropertyDeclSetterEnd
#    end

#    def onVarDeclStart
#    end

#    def onVarDeclName (name, doc)
#    end

#    def onVarDeclTuple (tuple)
#    end

#    def onVarDeclExtern (externName)
#    end

#    def onVarDeclUnmangled (unmangledName)
#    end

#    def onVarDeclExpr (expr)
#    end

#    def onVarDeclType (type)
#    end

#    def onVarDeclStatic
#    end

#    def onVarDeclConst
#    end

#    def onVarDeclProto
#    end

#    def onVarDeclEnd
#    end

#    def onTypeAccess (type)
#    end

#    def onTypeNew (name)
#    end

#    def onTypePointer (type)
#    end

#    def onTypeReference (type)
#    end

#    def onTypeBrackets (type, inner)
#    end

#    def onTypeGenericArgument (type, genType)
#    end

#    def onFuncTypeGenericArgument (type, name)
#    end

#    def onTypeList
#    end

#    def onTypeListElement (list, elem)
#    end

#    def onTypeNamespace (type, ident)
#    end

#    def onFuncTypeNew
#    end

#    def onFuncTypeArgument (funcType, argType)
#    end

#    def onFuncTypeVarArg (funcType)
#    end

#    def onFuncTypeReturnType (funcType, returnType)
#    end

#    def onOperatorStart (symbol)
#    end

#    def onOperatorEnd
#    end

#    def onFunctionStart (name, doc)
#    end

#    def onFunctionExtern (externName)
#    end

#    def onFunctionUnmangled (unmangledName)
#    end

#    def onFunctionAbstract
#    end

#    def onFunctionThisRef
#    end

#    def onFunctionArgsStart
#    end

#    def onFunctionArgsEnd
#    end

#    def onFunctionReturnType (type)
#    end

#    def onFunctionConst
#    end

#    def onFunctionStatic
#    end

#    def onFunctionInline
#    end

#    def onFunctionFinal
#    end

#    def onFunctionProto
#    end

#    def onFunctionSuper
#    end

#    def onFunctionSuffix (name)
#    end

#    def onFunctionBody
#    end

#    def onFunctionEnd
#    end

#    def onTypeArg (type)
#    end

#    def onVarArg (name)
#    end

#    def onDotArg (name)
#    end

#    def onAssArg (name)
#    end

#    def onFunctionCallStart (yytext)
#    end

#    def onFunctionCallSuffix (yytext)
#    end

#    def onFunctionCallArg (expr)
#    end

#    def onFunctionCallEnd
#    end

#    def onFunctionCallExpr (call, expr)
#    end

#    def onFunctionCallChain (expr, call)
#    end

#    def onFunctionCallCombo (call, expr)
#    end

#    def onArrayLiteralStart
#    end

#    def onArrayLiteralEnd
#    end

#    def onTupleStart
#    end

#    def onTupleEnd
#    end

    def onStringLiteral (text)
      text
    end

#    def onCharLiteral (value)
#    end

#    def onStatement (statement)
#    end

#    def onReturn (expr)
#    end

#    def onVarAccess (expr, name)
#    end

#    def onArrayAccessStart (array)
#    end

#    def onArrayAccessEnd
#    end

#    def onCast (expr, type)
#    end

#    def onBreak
#    end

#    def onContinue
#    end

#    def onBlockStart
#    end

#    def onBlockEnd
#    end

#    def onIfStart (condition)
#    end

#    def onIfEnd
#    end

#    def onElseStart
#    end

#    def onElseEnd
#    end

#    def onForeachStart (decl, collec)
#    end

#    def onForeachEnd
#    end

#    def onWhileStart (condition)
#    end

#    def onWhileEnd
#    end

#    def onEquals (left, right)
#    end

#    def onNotEquals (left, right)
#    end

#    def onLessThan (left, right)
#    end

#    def onMoreThan (left, right)
#    end

#    def onCmp (left, right)
#    end

#    def onLessThanOrEqual (left, right)
#    end

#    def onMoreThanOrEqual (left, right)
#    end

#    def onDecLiteral (value)
#    end

#    def onBinLiteral (value)
#    end

#    def onOctLiteral (value)
#    end

#    def onHexLiteral (value)
#    end

#    def onFloatLiteral (value)
#    end

#    def onBoolLiteral (value)
#    end

#    def onNull
#    end

#    def onDoubleArrow (left, right)
#    end

#    def onTernary (condition, ifTrue, ifFalse)
#    end

#    def onAssignAnd (left, right)
#    end

#    def onAssignOr (left, right)
#    end

#    def onAssignXor (left, right)
#    end

#    def onAssignRightShift (left, right)
#    end

#    def onAssignLeftShift (left, right)
#    end

#    def onAssignDiv (left, right)
#    end

#    def onAssignMul (left, right)
#    end

#    def onAssignExp (left, right)
#    end

#    def onAssignSub (left, right)
#    end

#    def onAssignAdd (left, right)
#    end

#    def onAssign (left, right)
#    end

#    def onAdd (left, right)
#    end

#    def onSub (left, right)
#    end

#    def onMod (left, right)
#    end

#    def onMul (left, right)
#    end

#    def onExp (left, right)
#    end

#    def onDiv (left, right)
#    end

#    def onRangeLiteral (left, right)
#    end

#    def onBinaryLeftShift (left, right)
#    end

#    def onBinaryRightShift (left, right)
#    end

#    def onLogicalOr (left, right)
#    end

#    def onLogicalAnd (left, right)
#    end

#    def onBinaryOr (left, right)
#    end

#    def onBinaryXor (left, right)
#    end

#    def onBinaryAnd (left, right)
#    end

#    def onLogicalNot (inner)
#    end

#    def onBinaryNot (inner)
#    end

#    def onUnaryMinus (inner)
#    end

#    def onParenthesis (inner)
#    end

#    def onGenericArgument (name)
#    end

#    def onAddressOf (inner)
#    end

#    def onDereference (inner)
#    end

#    def onMatchStart
#    end

#    def onMatchExpr (value)
#    end

#    def onMatchEnd
#    end

#    def onCaseStart
#    end

#    def onCaseExpr (value)
#    end

#    def onCaseEnd
#    end

#    def onTryStart
#    end

#    def onTryEnd
#    end

#    def onCatchStart
#    end

#    def onCatchExpr (value)
#    end

#    def onCatchEnd
#    end

#    def error (errorID, defaultMessage, index)
#    end

    def method_missing(name, *args)
      puts "#{name}(#{args.map(&:inspect).join(", ")})"
    end
  end
end
