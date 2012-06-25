
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
#    def setTokenPositionPointer (this, tokenPosPointer)
#    end

#    def StringClone (string)
#    end

#    def trailingQuest (string)
#    end

#    def trailingBang (string)
#    end

#    def onUse (this, name)
#    end

#    def onInclude (this, path)
#    end

#    def onIncludeDefine (this, name, value)
#    end

#    def onImport (this, path, name)
#    end

#    def onImportNamespace (this, namespace, quantity)
#    end

#    def onVersionName (this, name)
#    end

#    def onVersionNegation (this, spec)
#    end

#    def onVersionAnd (this, specLeft, specRight)
#    end

#    def onVersionOr (this, specLeft, specRight)
#    end

#    def onVersionStart (this, spec)
#    end

#    def onVersionElseIfStart (this, notSpec, elseSpec)
#    end

#    def onVersionElseStart (this, notSpec)
#    end

#    def onVersionEnd (this)
#    end

#    def onExtendStart (this, type, doc)
#    end

#    def onExtendEnd (this)
#    end

#    def onCoverStart (this, name, doc)
#    end

#    def onCoverExtern (this, externName)
#    end

#    def onCoverFromType (this, type)
#    end

#    def onCoverExtends (this, type)
#    end

#    def onCoverImplements (this, type)
#    end

#    def onCoverEnd (this)
#    end

#    def onEnumStart (this, name, doc)
#    end

#    def onEnumExtern (this, externName)
#    end

#    def onEnumFromType (this, fromType)
#    end

#    def onEnumIncrementExpr (this, oper, step)
#    end

#    def onEnumElementStart (this, name, doc)
#    end

#    def onEnumElementValue (this, value)
#    end

#    def onEnumElementExtern (this, externName)
#    end

#    def onEnumElementEnd (this)
#    end

#    def onEnumEnd (this)
#    end

#    def onClassStart (this, name, doc)
#    end

#    def onClassAbstract (this)
#    end

#    def onClassFinal (this)
#    end

#    def onClassExtends (this, type)
#    end

#    def onClassImplements (this, type)
#    end

#    def onClassBody (this)
#    end

#    def onClassEnd (this)
#    end

#    def onInterfaceStart (this, name, doc)
#    end

#    def onInterfaceExtends (this, type)
#    end

#    def onInterfaceEnd (this)
#    end

#    def onPropertyDeclStart (this, name, doc)
#    end

#    def onPropertyDeclStatic (this)
#    end

#    def onPropertyDeclType (this, type)
#    end

#    def onPropertyDeclEnd (this)
#    end

#    def onPropertyDeclGetterStart (this, doc)
#    end

#    def onPropertyDeclGetterEnd (this)
#    end

#    def onPropertyDeclSetterStart (this, doc)
#    end

#    def onPropertyDeclSetterArgument (this, name, conventional)
#    end

#    def onPropertyDeclSetterEnd (this)
#    end

#    def onVarDeclStart (this)
#    end

#    def onVarDeclName (this, name, doc)
#    end

#    def onVarDeclTuple (this, tuple)
#    end

#    def onVarDeclExtern (this, externName)
#    end

#    def onVarDeclUnmangled (this, unmangledName)
#    end

#    def onVarDeclExpr (this, expr)
#    end

#    def onVarDeclType (this, type)
#    end

#    def onVarDeclStatic (this)
#    end

#    def onVarDeclConst (this)
#    end

#    def onVarDeclProto (this)
#    end

#    def onVarDeclEnd (this)
#    end

#    def onTypeAccess (this, type)
#    end

#    def onTypeNew (this, name)
#    end

#    def onTypePointer (this, type)
#    end

#    def onTypeReference (this, type)
#    end

#    def onTypeBrackets (this, type, inner)
#    end

#    def onTypeGenericArgument (this, type, genType)
#    end

#    def onFuncTypeGenericArgument (this, type, name)
#    end

#    def onTypeList (this)
#    end

#    def onTypeListElement (this, list, elem)
#    end

#    def onTypeNamespace (this, type, ident)
#    end

#    def onFuncTypeNew (this)
#    end

#    def onFuncTypeArgument (this, funcType, argType)
#    end

#    def onFuncTypeVarArg (this, funcType)
#    end

#    def onFuncTypeReturnType (this, funcType, returnType)
#    end

#    def onOperatorStart (this, symbol)
#    end

#    def onOperatorEnd (this)
#    end

#    def onFunctionStart (this, name, doc)
#    end

#    def onFunctionExtern (this, externName)
#    end

#    def onFunctionUnmangled (this, unmangledName)
#    end

#    def onFunctionAbstract (this)
#    end

#    def onFunctionThisRef (this)
#    end

#    def onFunctionArgsStart (this)
#    end

#    def onFunctionArgsEnd (this)
#    end

#    def onFunctionReturnType (this, type)
#    end

#    def onFunctionConst (this)
#    end

#    def onFunctionStatic (this)
#    end

#    def onFunctionInline (this)
#    end

#    def onFunctionFinal (this)
#    end

#    def onFunctionProto (this)
#    end

#    def onFunctionSuper (this)
#    end

#    def onFunctionSuffix (this, name)
#    end

#    def onFunctionBody (this)
#    end

#    def onFunctionEnd (this)
#    end

#    def onTypeArg (this, type)
#    end

#    def onVarArg (this, name)
#    end

#    def onDotArg (this, name)
#    end

#    def onAssArg (this, name)
#    end

#    def onFunctionCallStart (this, yytext)
#    end

#    def onFunctionCallSuffix (this, yytext)
#    end

#    def onFunctionCallArg (this, expr)
#    end

#    def onFunctionCallEnd (this)
#    end

#    def onFunctionCallExpr (this, call, expr)
#    end

#    def onFunctionCallChain (this, expr, call)
#    end

#    def onFunctionCallCombo (this, call, expr)
#    end

#    def onArrayLiteralStart (this)
#    end

#    def onArrayLiteralEnd (this)
#    end

#    def onTupleStart (this)
#    end

#    def onTupleEnd (this)
#    end

#    def onStringLiteral (this, text)
#    end

#    def onCharLiteral (this, value)
#    end

#    def onStatement (this, statement)
#    end

#    def onReturn (this, expr)
#    end

#    def onVarAccess (this, expr, name)
#    end

#    def onArrayAccessStart (this, array)
#    end

#    def onArrayAccessEnd (this)
#    end

#    def onCast (this, expr, type)
#    end

#    def onBreak (this)
#    end

#    def onContinue (this)
#    end

#    def onBlockStart (this)
#    end

#    def onBlockEnd (this)
#    end

#    def onIfStart (this, condition)
#    end

#    def onIfEnd (this)
#    end

#    def onElseStart (this)
#    end

#    def onElseEnd (this)
#    end

#    def onForeachStart (this, decl, collec)
#    end

#    def onForeachEnd (this)
#    end

#    def onWhileStart (this, condition)
#    end

#    def onWhileEnd (this)
#    end

#    def onEquals (this, left, right)
#    end

#    def onNotEquals (this, left, right)
#    end

#    def onLessThan (this, left, right)
#    end

#    def onMoreThan (this, left, right)
#    end

#    def onCmp (this, left, right)
#    end

#    def onLessThanOrEqual (this, left, right)
#    end

#    def onMoreThanOrEqual (this, left, right)
#    end

#    def onDecLiteral (this, value)
#    end

#    def onBinLiteral (this, value)
#    end

#    def onOctLiteral (this, value)
#    end

#    def onHexLiteral (this, value)
#    end

#    def onFloatLiteral (this, value)
#    end

#    def onBoolLiteral (this, value)
#    end

#    def onNull (this)
#    end

#    def onDoubleArrow (this, left, right)
#    end

#    def onTernary (this, condition, ifTrue, ifFalse)
#    end

#    def onAssignAnd (this, left, right)
#    end

#    def onAssignOr (this, left, right)
#    end

#    def onAssignXor (this, left, right)
#    end

#    def onAssignRightShift (this, left, right)
#    end

#    def onAssignLeftShift (this, left, right)
#    end

#    def onAssignDiv (this, left, right)
#    end

#    def onAssignMul (this, left, right)
#    end

#    def onAssignExp (this, left, right)
#    end

#    def onAssignSub (this, left, right)
#    end

#    def onAssignAdd (this, left, right)
#    end

#    def onAssign (this, left, right)
#    end

#    def onAdd (this, left, right)
#    end

#    def onSub (this, left, right)
#    end

#    def onMod (this, left, right)
#    end

#    def onMul (this, left, right)
#    end

#    def onExp (this, left, right)
#    end

#    def onDiv (this, left, right)
#    end

#    def onRangeLiteral (this, left, right)
#    end

#    def onBinaryLeftShift (this, left, right)
#    end

#    def onBinaryRightShift (this, left, right)
#    end

#    def onLogicalOr (this, left, right)
#    end

#    def onLogicalAnd (this, left, right)
#    end

#    def onBinaryOr (this, left, right)
#    end

#    def onBinaryXor (this, left, right)
#    end

#    def onBinaryAnd (this, left, right)
#    end

#    def onLogicalNot (this, inner)
#    end

#    def onBinaryNot (this, inner)
#    end

#    def onUnaryMinus (this, inner)
#    end

#    def onParenthesis (this, inner)
#    end

#    def onGenericArgument (this, name)
#    end

#    def onAddressOf (this, inner)
#    end

#    def onDereference (this, inner)
#    end

#    def onMatchStart (this)
#    end

#    def onMatchExpr (this, value)
#    end

#    def onMatchEnd (this)
#    end

#    def onCaseStart (this)
#    end

#    def onCaseExpr (this, value)
#    end

#    def onCaseEnd (this)
#    end

#    def onTryStart (this)
#    end

#    def onTryEnd (this)
#    end

#    def onCatchStart (this)
#    end

#    def onCatchExpr (this, value)
#    end

#    def onCatchEnd (this)
#    end

#    def error (this, errorID, defaultMessage, index)
#    end

    def method_missing(name, *args)
      puts "#{name}(#{args.map(&:inspect).join(", ")})"
    end
  end
end
