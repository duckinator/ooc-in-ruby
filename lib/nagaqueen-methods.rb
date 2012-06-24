
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
#    def setTokenPositionPointer (_, tokenPosPointer)
#    end

#    def StringClone (string)
#    end

#    def trailingQuest (string)
#    end

#    def trailingBang (string)
#    end

#    def onUse (_, name)
#    end

#    def onInclude (_, path)
#    end

#    def onIncludeDefine (_, name, value)
#    end

#    def onImport (_, path, name)
#    end

#    def onImportNamespace (_, namespace, quantity)
#    end

#    def onVersionName (_, name)
#    end

#    def onVersionNegation (_, spec)
#    end

#    def onVersionAnd (_, specLeft, specRight)
#    end

#    def onVersionOr (_, specLeft, specRight)
#    end

#    def onVersionStart (_, spec)
#    end

#    def onVersionElseIfStart (_, notSpec, elseSpec)
#    end

#    def onVersionElseStart (_, notSpec)
#    end

#    def onVersionEnd (_)
#    end

#    def onExtendStart (_, type, doc)
#    end

#    def onExtendEnd (_)
#    end

#    def onCoverStart (_, name, doc)
#    end

#    def onCoverExtern (_, externName)
#    end

#    def onCoverFromType (_, type)
#    end

#    def onCoverExtends (_, type)
#    end

#    def onCoverImplements (_, type)
#    end

#    def onCoverEnd (_)
#    end

#    def onEnumStart (_, name, doc)
#    end

#    def onEnumExtern (_, externName)
#    end

#    def onEnumFromType (_, fromType)
#    end

#    def onEnumIncrementExpr (_, oper, step)
#    end

#    def onEnumElementStart (_, name, doc)
#    end

#    def onEnumElementValue (_, value)
#    end

#    def onEnumElementExtern (_, externName)
#    end

#    def onEnumElementEnd (_)
#    end

#    def onEnumEnd (_)
#    end

#    def onClassStart (_, name, doc)
#    end

#    def onClassAbstract (_)
#    end

#    def onClassFinal (_)
#    end

#    def onClassExtends (_, type)
#    end

#    def onClassImplements (_, type)
#    end

#    def onClassBody (_)
#    end

#    def onClassEnd (_)
#    end

#    def onInterfaceStart (_, name, doc)
#    end

#    def onInterfaceExtends (_, type)
#    end

#    def onInterfaceEnd (_)
#    end

#    def onPropertyDeclStart (_, name, doc)
#    end

#    def onPropertyDeclStatic (_)
#    end

#    def onPropertyDeclType (_, type)
#    end

#    def onPropertyDeclEnd (_)
#    end

#    def onPropertyDeclGetterStart (_, doc)
#    end

#    def onPropertyDeclGetterEnd (_)
#    end

#    def onPropertyDeclSetterStart (_, doc)
#    end

#    def onPropertyDeclSetterArgument (_, name, conventional)
#    end

#    def onPropertyDeclSetterEnd (_)
#    end

#    def onVarDeclStart (_)
#    end

#    def onVarDeclName (_, name, doc)
#    end

#    def onVarDeclTuple (_, tuple)
#    end

#    def onVarDeclExtern (_, externName)
#    end

#    def onVarDeclUnmangled (_, unmangledName)
#    end

#    def onVarDeclExpr (_, expr)
#    end

#    def onVarDeclType (_, type)
#    end

#    def onVarDeclStatic (_)
#    end

#    def onVarDeclConst (_)
#    end

#    def onVarDeclProto (_)
#    end

#    def onVarDeclEnd (_)
#    end

#    def onTypeAccess (_, type)
#    end

#    def onTypeNew (_, name)
#    end

#    def onTypePointer (_, type)
#    end

#    def onTypeReference (_, type)
#    end

#    def onTypeBrackets (_, type, inner)
#    end

#    def onTypeGenericArgument (_, type, genType)
#    end

#    def onFuncTypeGenericArgument (_, type, name)
#    end

#    def onTypeList (_)
#    end

#    def onTypeListElement (_, list, elem)
#    end

#    def onTypeNamespace (_, type, ident)
#    end

#    def onFuncTypeNew (_)
#    end

#    def onFuncTypeArgument (_, funcType, argType)
#    end

#    def onFuncTypeVarArg (_, funcType)
#    end

#    def onFuncTypeReturnType (_, funcType, returnType)
#    end

#    def onOperatorStart (_, symbol)
#    end

#    def onOperatorEnd (_)
#    end

#    def onFunctionStart (_, name, doc)
#    end

#    def onFunctionExtern (_, externName)
#    end

#    def onFunctionUnmangled (_, unmangledName)
#    end

#    def onFunctionAbstract (_)
#    end

#    def onFunctionThisRef (_)
#    end

#    def onFunctionArgsStart (_)
#    end

#    def onFunctionArgsEnd (_)
#    end

#    def onFunctionReturnType (_, type)
#    end

#    def onFunctionConst (_)
#    end

#    def onFunctionStatic (_)
#    end

#    def onFunctionInline (_)
#    end

#    def onFunctionFinal (_)
#    end

#    def onFunctionProto (_)
#    end

#    def onFunctionSuper (_)
#    end

#    def onFunctionSuffix (_, name)
#    end

#    def onFunctionBody (_)
#    end

#    def onFunctionEnd (_)
#    end

#    def onTypeArg (_, type)
#    end

#    def onVarArg (_, name)
#    end

#    def onDotArg (_, name)
#    end

#    def onAssArg (_, name)
#    end

#    def onFunctionCallStart (_, yytext)
#    end

#    def onFunctionCallSuffix (_, yytext)
#    end

#    def onFunctionCallArg (_, expr)
#    end

#    def onFunctionCallEnd (_)
#    end

#    def onFunctionCallExpr (_, call, expr)
#    end

#    def onFunctionCallChain (_, expr, call)
#    end

#    def onFunctionCallCombo (_, call, expr)
#    end

#    def onArrayLiteralStart (_)
#    end

#    def onArrayLiteralEnd (_)
#    end

#    def onTupleStart (_)
#    end

#    def onTupleEnd (_)
#    end

#    def onStringLiteral (_, text)
#    end

#    def onCharLiteral (_, value)
#    end

#    def onStatement (_, statement)
#    end

#    def onReturn (_, expr)
#    end

#    def onVarAccess (_, expr, name)
#    end

#    def onArrayAccessStart (_, array)
#    end

#    def onArrayAccessEnd (_)
#    end

#    def onCast (_, expr, type)
#    end

#    def onBreak (_)
#    end

#    def onContinue (_)
#    end

#    def onBlockStart (_)
#    end

#    def onBlockEnd (_)
#    end

#    def onIfStart (_, condition)
#    end

#    def onIfEnd (_)
#    end

#    def onElseStart (_)
#    end

#    def onElseEnd (_)
#    end

#    def onForeachStart (_, decl, collec)
#    end

#    def onForeachEnd (_)
#    end

#    def onWhileStart (_, condition)
#    end

#    def onWhileEnd (_)
#    end

#    def onEquals (_, left, right)
#    end

#    def onNotEquals (_, left, right)
#    end

#    def onLessThan (_, left, right)
#    end

#    def onMoreThan (_, left, right)
#    end

#    def onCmp (_, left, right)
#    end

#    def onLessThanOrEqual (_, left, right)
#    end

#    def onMoreThanOrEqual (_, left, right)
#    end

#    def onDecLiteral (_, value)
#    end

#    def onBinLiteral (_, value)
#    end

#    def onOctLiteral (_, value)
#    end

#    def onHexLiteral (_, value)
#    end

#    def onFloatLiteral (_, value)
#    end

#    def onBoolLiteral (_, value)
#    end

#    def onNull (_)
#    end

#    def onDoubleArrow (_, left, right)
#    end

#    def onTernary (_, condition, ifTrue, ifFalse)
#    end

#    def onAssignAnd (_, left, right)
#    end

#    def onAssignOr (_, left, right)
#    end

#    def onAssignXor (_, left, right)
#    end

#    def onAssignRightShift (_, left, right)
#    end

#    def onAssignLeftShift (_, left, right)
#    end

#    def onAssignDiv (_, left, right)
#    end

#    def onAssignMul (_, left, right)
#    end

#    def onAssignExp (_, left, right)
#    end

#    def onAssignSub (_, left, right)
#    end

#    def onAssignAdd (_, left, right)
#    end

#    def onAssign (_, left, right)
#    end

#    def onAdd (_, left, right)
#    end

#    def onSub (_, left, right)
#    end

#    def onMod (_, left, right)
#    end

#    def onMul (_, left, right)
#    end

#    def onExp (_, left, right)
#    end

#    def onDiv (_, left, right)
#    end

#    def onRangeLiteral (_, left, right)
#    end

#    def onBinaryLeftShift (_, left, right)
#    end

#    def onBinaryRightShift (_, left, right)
#    end

#    def onLogicalOr (_, left, right)
#    end

#    def onLogicalAnd (_, left, right)
#    end

#    def onBinaryOr (_, left, right)
#    end

#    def onBinaryXor (_, left, right)
#    end

#    def onBinaryAnd (_, left, right)
#    end

#    def onLogicalNot (_, inner)
#    end

#    def onBinaryNot (_, inner)
#    end

#    def onUnaryMinus (_, inner)
#    end

#    def onParenthesis (_, inner)
#    end

#    def onGenericArgument (_, name)
#    end

#    def onAddressOf (_, inner)
#    end

#    def onDereference (_, inner)
#    end

#    def onMatchStart (_)
#    end

#    def onMatchExpr (_, value)
#    end

#    def onMatchEnd (_)
#    end

#    def onCaseStart (_)
#    end

#    def onCaseExpr (_, value)
#    end

#    def onCaseEnd (_)
#    end

#    def onTryStart (_)
#    end

#    def onTryEnd (_)
#    end

#    def onCatchStart (_)
#    end

#    def onCatchExpr (_, value)
#    end

#    def onCatchEnd (_)
#    end

#    def error (_, errorID, defaultMessage, index)
#    end

    def method_missing(name, _, *args)
      puts "#{name}(#{args.map(&:inspect).join(', ')})"
    end

  end
end
