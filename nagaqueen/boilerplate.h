int* nq_setTokenPositionPointer (VALUE self, int* tokenPosPointer)
{
  rb_funcall(cNagaqueen, rb_intern("setTokenPositionPointer"), self, INT2NUM(*tokenPosPointer));
}

char* nq_StringClone (char* string)
{
  rb_funcall(cNagaqueen, rb_intern("StringClone"), rb_str_new2(string));
}

char* nq_trailingQuest (char* string)
{
  rb_funcall(cNagaqueen, rb_intern("trailingQuest"), rb_str_new2(string));
}

char* nq_trailingBang  (char* string)
{
  rb_funcall(cNagaqueen, rb_intern("trailingBang "), rb_str_new2(string));
}

char* nq_onUse (VALUE self, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onUse"), self, rb_str_new2(name));
}

char* nq_onInclude (VALUE self, char* path)
{
  rb_funcall(cNagaqueen, rb_intern("onInclude"), self, rb_str_new2(path));
}

char* nq_onIncludeDefine (VALUE self, char* name, char* value)
{
  rb_funcall(cNagaqueen, rb_intern("onIncludeDefine"), self, rb_str_new2(name), rb_str_new2(value));
}

char* nq_onImport  (VALUE self, char* path, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onImport "), self, rb_str_new2(path), rb_str_new2(name));
}

int nq_onImportNamespace (VALUE self, char* namespace, int quantity)
{
  rb_funcall(cNagaqueen, rb_intern("onImportNamespace"), self, rb_str_new2(namespace), INT2NUM(quantity));
}

char* nq_onVersionName (VALUE self, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onVersionName"), self, rb_str_new2(name));
}

VALUE nq_onVersionNegation (VALUE self, VALUE spec)
{
  rb_funcall(cNagaqueen, rb_intern("onVersionNegation"), self, spec);
}

VALUE nq_onVersionAnd (VALUE self, VALUE specLeft, VALUE specRight)
{
  rb_funcall(cNagaqueen, rb_intern("onVersionAnd"), self, specLeft, specRight);
}

VALUE nq_onVersionOr (VALUE self, VALUE specLeft, VALUE specRight)
{
  rb_funcall(cNagaqueen, rb_intern("onVersionOr"), self, specLeft, specRight);
}

VALUE nq_onVersionStart (VALUE self, VALUE spec)
{
  rb_funcall(cNagaqueen, rb_intern("onVersionStart"), self, spec);
}

VALUE nq_onVersionElseIfStart (VALUE self, VALUE notSpec, VALUE elseSpec)
{
  rb_funcall(cNagaqueen, rb_intern("onVersionElseIfStart"), self, notSpec, elseSpec);
}

VALUE nq_onVersionElseStart (VALUE self, VALUE notSpec)
{
  rb_funcall(cNagaqueen, rb_intern("onVersionElseStart"), self, notSpec);
}

VALUE nq_onVersionEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onVersionEnd"), self);
}

char* nq_onExtendStart (VALUE self, VALUE type, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onExtendStart"), self, type, rb_str_new2(doc));
}

VALUE nq_onExtendEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onExtendEnd"), self);
}

char* nq_onCoverStart (VALUE self, char* name, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onCoverStart"), self, rb_str_new2(name), rb_str_new2(doc));
}

char* nq_onCoverExtern (VALUE self, char* externName)
{
  rb_funcall(cNagaqueen, rb_intern("onCoverExtern"), self, rb_str_new2(externName));
}

VALUE nq_onCoverFromType (VALUE self, VALUE type)
{
  rb_funcall(cNagaqueen, rb_intern("onCoverFromType"), self, type);
}

VALUE nq_onCoverExtends (VALUE self, VALUE type)
{
  rb_funcall(cNagaqueen, rb_intern("onCoverExtends"), self, type);
}

VALUE nq_onCoverImplements (VALUE self, VALUE type)
{
  rb_funcall(cNagaqueen, rb_intern("onCoverImplements"), self, type);
}

VALUE nq_onCoverEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onCoverEnd"), self);
}

char* nq_onEnumStart (VALUE self, char* name, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onEnumStart"), self, rb_str_new2(name), rb_str_new2(doc));
}

char* nq_onEnumExtern (VALUE self, char* externName)
{
  rb_funcall(cNagaqueen, rb_intern("onEnumExtern"), self, rb_str_new2(externName));
}

VALUE nq_onEnumFromType (VALUE self, VALUE fromType)
{
  rb_funcall(cNagaqueen, rb_intern("onEnumFromType"), self, fromType);
}

VALUE nq_onEnumIncrementExpr (VALUE self, char oper, VALUE step)
{
  rb_funcall(cNagaqueen, rb_intern("onEnumIncrementExpr"), self, oper, step);
}

char* nq_onEnumElementStart (VALUE self, char* name, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onEnumElementStart"), self, rb_str_new2(name), rb_str_new2(doc));
}

VALUE nq_onEnumElementValue (VALUE self, VALUE value)
{
  rb_funcall(cNagaqueen, rb_intern("onEnumElementValue"), self, value);
}

char* nq_onEnumElementExtern (VALUE self, char* externName)
{
  rb_funcall(cNagaqueen, rb_intern("onEnumElementExtern"), self, rb_str_new2(externName));
}

VALUE nq_onEnumElementEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onEnumElementEnd"), self);
}

VALUE nq_onEnumEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onEnumEnd"), self);
}

char* nq_onClassStart (VALUE self, char* name, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onClassStart"), self, rb_str_new2(name), rb_str_new2(doc));
}

VALUE nq_onClassAbstract (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onClassAbstract"), self);
}

VALUE nq_onClassFinal (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onClassFinal"), self);
}

VALUE nq_onClassExtends (VALUE self, VALUE type)
{
  rb_funcall(cNagaqueen, rb_intern("onClassExtends"), self, type);
}

VALUE nq_onClassImplements (VALUE self, VALUE type)
{
  rb_funcall(cNagaqueen, rb_intern("onClassImplements"), self, type);
}

VALUE nq_onClassBody (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onClassBody"), self);
}

VALUE nq_onClassEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onClassEnd"), self);
}

char* nq_onInterfaceStart (VALUE self, char* name, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onInterfaceStart"), self, rb_str_new2(name), rb_str_new2(doc));
}

VALUE nq_onInterfaceExtends (VALUE self, VALUE type)
{
  rb_funcall(cNagaqueen, rb_intern("onInterfaceExtends"), self, type);
}

VALUE nq_onInterfaceEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onInterfaceEnd"), self);
}

char* nq_onPropertyDeclStart (VALUE self, char* name, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onPropertyDeclStart"), self, rb_str_new2(name), rb_str_new2(doc));
}

VALUE nq_onPropertyDeclStatic (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onPropertyDeclStatic"), self);
}

VALUE nq_onPropertyDeclType (VALUE self, VALUE type)
{
  rb_funcall(cNagaqueen, rb_intern("onPropertyDeclType"), self, type);
}

VALUE nq_onPropertyDeclEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onPropertyDeclEnd"), self);
}

char* nq_onPropertyDeclGetterStart (VALUE self, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onPropertyDeclGetterStart"), self, rb_str_new2(doc));
}

VALUE nq_onPropertyDeclGetterEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onPropertyDeclGetterEnd"), self);
}

char* nq_onPropertyDeclSetterStart (VALUE self, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onPropertyDeclSetterStart"), self, rb_str_new2(doc));
}

_Bool nq_onPropertyDeclSetterArgument (VALUE self, char* name, _Bool conventional)
{
  rb_funcall(cNagaqueen, rb_intern("onPropertyDeclSetterArgument"), self, rb_str_new2(name), conventional);
}

VALUE nq_onPropertyDeclSetterEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onPropertyDeclSetterEnd"), self);
}

VALUE nq_onVarDeclStart (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclStart"), self);
}

char* nq_onVarDeclName (VALUE self, char* name, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclName"), self, rb_str_new2(name), rb_str_new2(doc));
}

VALUE nq_onVarDeclTuple (VALUE self, VALUE tuple)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclTuple"), self, tuple);
}

char* nq_onVarDeclExtern (VALUE self, char* externName)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclExtern"), self, rb_str_new2(externName));
}

char* nq_onVarDeclUnmangled (VALUE self, char* unmangledName)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclUnmangled"), self, rb_str_new2(unmangledName));
}

VALUE nq_onVarDeclExpr (VALUE self, VALUE expr)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclExpr"), self, expr);
}

VALUE nq_onVarDeclType (VALUE self, VALUE type)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclType"), self, type);
}

VALUE nq_onVarDeclStatic (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclStatic"), self);
}

VALUE nq_onVarDeclConst (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclConst"), self);
}

VALUE nq_onVarDeclProto (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclProto"), self);
}

VALUE nq_onVarDeclEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclEnd"), self);
}

VALUE nq_onTypeAccess (VALUE self, VALUE type)
{
  rb_funcall(cNagaqueen, rb_intern("onTypeAccess"), self, type);
}

char* nq_onTypeNew (VALUE self, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onTypeNew"), self, rb_str_new2(name));
}

VALUE nq_onTypePointer (VALUE self, VALUE type)
{
  rb_funcall(cNagaqueen, rb_intern("onTypePointer"), self, type);
}

VALUE nq_onTypeReference (VALUE self, VALUE type)
{
  rb_funcall(cNagaqueen, rb_intern("onTypeReference"), self, type);
}

VALUE nq_onTypeBrackets (VALUE self, VALUE type, VALUE inner)
{
  rb_funcall(cNagaqueen, rb_intern("onTypeBrackets"), self, type, inner);
}

VALUE nq_onTypeGenericArgument (VALUE self, VALUE type, VALUE genType)
{
  rb_funcall(cNagaqueen, rb_intern("onTypeGenericArgument"), self, type, genType);
}

char* nq_onFuncTypeGenericArgument (VALUE self, VALUE type, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onFuncTypeGenericArgument"), self, type, rb_str_new2(name));
}

VALUE nq_onTypeList (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onTypeList"), self);
}

VALUE nq_onTypeListElement (VALUE self, VALUE list, VALUE elem)
{
  rb_funcall(cNagaqueen, rb_intern("onTypeListElement"), self, list, elem);
}

VALUE nq_onTypeNamespace (VALUE self, VALUE type, VALUE ident)
{
  rb_funcall(cNagaqueen, rb_intern("onTypeNamespace"), self, type, ident);
}

VALUE nq_onFuncTypeNew (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onFuncTypeNew"), self);
}

VALUE nq_onFuncTypeArgument (VALUE self, VALUE funcType, VALUE argType)
{
  rb_funcall(cNagaqueen, rb_intern("onFuncTypeArgument"), self, funcType, argType);
}

VALUE nq_onFuncTypeVarArg (VALUE self, VALUE funcType)
{
  rb_funcall(cNagaqueen, rb_intern("onFuncTypeVarArg"), self, funcType);
}

VALUE nq_onFuncTypeReturnType (VALUE self, VALUE funcType, VALUE returnType)
{
  rb_funcall(cNagaqueen, rb_intern("onFuncTypeReturnType"), self, funcType, returnType);
}

char* nq_onOperatorStart (VALUE self, char* symbol)
{
  rb_funcall(cNagaqueen, rb_intern("onOperatorStart"), self, rb_str_new2(symbol));
}

VALUE nq_onOperatorEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onOperatorEnd"), self);
}

char* nq_onFunctionStart (VALUE self, char* name, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionStart"), self, rb_str_new2(name), rb_str_new2(doc));
}

char* nq_onFunctionExtern (VALUE self, char* externName)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionExtern"), self, rb_str_new2(externName));
}

char* nq_onFunctionUnmangled (VALUE self, char* unmangledName)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionUnmangled"), self, rb_str_new2(unmangledName));
}

VALUE nq_onFunctionAbstract (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionAbstract"), self);
}

VALUE nq_onFunctionThisRef (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionThisRef"), self);
}

VALUE nq_onFunctionArgsStart (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionArgsStart"), self);
}

VALUE nq_onFunctionArgsEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionArgsEnd"), self);
}

VALUE nq_onFunctionReturnType (VALUE self, VALUE type)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionReturnType"), self, type);
}

VALUE nq_onFunctionConst (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionConst"), self);
}

VALUE nq_onFunctionStatic (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionStatic"), self);
}

VALUE nq_onFunctionInline (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionInline"), self);
}

VALUE nq_onFunctionFinal (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionFinal"), self);
}

VALUE nq_onFunctionProto (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionProto"), self);
}

VALUE nq_onFunctionSuper (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionSuper"), self);
}

char* nq_onFunctionSuffix (VALUE self, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionSuffix"), self, rb_str_new2(name));
}

VALUE nq_onFunctionBody (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionBody"), self);
}

VALUE nq_onFunctionEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionEnd"), self);
}

VALUE nq_onTypeArg (VALUE self, VALUE type)
{
  rb_funcall(cNagaqueen, rb_intern("onTypeArg"), self, type);
}

char* nq_onVarArg (VALUE self, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onVarArg"), self, rb_str_new2(name));
}

char* nq_onDotArg (VALUE self, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onDotArg"), self, rb_str_new2(name));
}

char* nq_onAssArg (VALUE self, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onAssArg"), self, rb_str_new2(name));
}

char* nq_onFunctionCallStart (VALUE self, char* yytext)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionCallStart"), self, rb_str_new2(yytext));
}

char* nq_onFunctionCallSuffix (VALUE self, char* yytext)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionCallSuffix"), self, rb_str_new2(yytext));
}

VALUE nq_onFunctionCallArg (VALUE self, VALUE expr)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionCallArg"), self, expr);
}

VALUE nq_onFunctionCallEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionCallEnd"), self);
}

VALUE nq_onFunctionCallExpr (VALUE self, VALUE call, VALUE expr)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionCallExpr"), self, call, expr);
}

VALUE nq_onFunctionCallChain (VALUE self, VALUE expr, VALUE call)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionCallChain"), self, expr, call);
}

VALUE nq_onFunctionCallCombo (VALUE self, VALUE call, VALUE expr)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionCallCombo"), self, call, expr);
}

VALUE nq_onArrayLiteralStart (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onArrayLiteralStart"), self);
}

VALUE nq_onArrayLiteralEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onArrayLiteralEnd"), self);
}

VALUE nq_onTupleStart (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onTupleStart"), self);
}

VALUE nq_onTupleEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onTupleEnd"), self);
}

char* nq_onStringLiteral (VALUE self, char* text)
{
  rb_funcall(cNagaqueen, rb_intern("onStringLiteral"), self, rb_str_new2(text));
}

char* nq_onCharLiteral (VALUE self, char* value)
{
  rb_funcall(cNagaqueen, rb_intern("onCharLiteral"), self, rb_str_new2(value));
}

VALUE nq_onStatement (VALUE self, VALUE statement)
{
  rb_funcall(cNagaqueen, rb_intern("onStatement"), self, statement);
}

VALUE nq_onReturn (VALUE self, VALUE expr)
{
  rb_funcall(cNagaqueen, rb_intern("onReturn"), self, expr);
}

char* nq_onVarAccess (VALUE self, VALUE expr, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onVarAccess"), self, expr, rb_str_new2(name));
}

VALUE nq_onArrayAccessStart (VALUE self, VALUE array)
{
  rb_funcall(cNagaqueen, rb_intern("onArrayAccessStart"), self, array);
}

VALUE nq_onArrayAccessEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onArrayAccessEnd"), self);
}

VALUE nq_onCast (VALUE self, VALUE expr, VALUE type)
{
  rb_funcall(cNagaqueen, rb_intern("onCast"), self, expr, type);
}

VALUE nq_onBreak (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onBreak"), self);
}

VALUE nq_onContinue (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onContinue"), self);
}

VALUE nq_onBlockStart (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onBlockStart"), self);
}

VALUE nq_onBlockEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onBlockEnd"), self);
}

VALUE nq_onIfStart (VALUE self, VALUE condition)
{
  rb_funcall(cNagaqueen, rb_intern("onIfStart"), self, condition);
}

VALUE nq_onIfEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onIfEnd"), self);
}

VALUE nq_onElseStart (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onElseStart"), self);
}

VALUE nq_onElseEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onElseEnd"), self);
}

VALUE nq_onForeachStart (VALUE self, VALUE decl, VALUE collec)
{
  rb_funcall(cNagaqueen, rb_intern("onForeachStart"), self, decl, collec);
}

VALUE nq_onForeachEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onForeachEnd"), self);
}

VALUE nq_onWhileStart (VALUE self, VALUE condition)
{
  rb_funcall(cNagaqueen, rb_intern("onWhileStart"), self, condition);
}

VALUE nq_onWhileEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onWhileEnd"), self);
}

VALUE nq_onEquals (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onEquals"), self, left, right);
}

VALUE nq_onNotEquals (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onNotEquals"), self, left, right);
}

VALUE nq_onLessThan (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onLessThan"), self, left, right);
}

VALUE nq_onMoreThan (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onMoreThan"), self, left, right);
}

VALUE nq_onCmp (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onCmp"), self, left, right);
}

VALUE nq_onLessThanOrEqual (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onLessThanOrEqual"), self, left, right);
}

VALUE nq_onMoreThanOrEqual (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onMoreThanOrEqual"), self, left, right);
}

char* nq_onDecLiteral (VALUE self, char* value)
{
  rb_funcall(cNagaqueen, rb_intern("onDecLiteral"), self, rb_str_new2(value));
}

char* nq_onBinLiteral (VALUE self, char* value)
{
  rb_funcall(cNagaqueen, rb_intern("onBinLiteral"), self, rb_str_new2(value));
}

char* nq_onOctLiteral (VALUE self, char* value)
{
  rb_funcall(cNagaqueen, rb_intern("onOctLiteral"), self, rb_str_new2(value));
}

char* nq_onHexLiteral (VALUE self, char* value)
{
  rb_funcall(cNagaqueen, rb_intern("onHexLiteral"), self, rb_str_new2(value));
}

char* nq_onFloatLiteral (VALUE self, char* value)
{
  rb_funcall(cNagaqueen, rb_intern("onFloatLiteral"), self, rb_str_new2(value));
}

bool nq_onBoolLiteral (VALUE self, bool value)
{
  rb_funcall(cNagaqueen, rb_intern("onBoolLiteral"), self, value);
}

VALUE nq_onNull (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onNull"), self);
}

VALUE nq_onDoubleArrow (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onDoubleArrow"), self, left, right);
}

VALUE nq_onTernary (VALUE self, VALUE condition, VALUE ifTrue, VALUE ifFalse)
{
  rb_funcall(cNagaqueen, rb_intern("onTernary"), self, condition, ifTrue, ifFalse);
}

VALUE nq_onAssignAnd (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignAnd"), self, left, right);
}

VALUE nq_onAssignOr (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignOr"), self, left, right);
}

VALUE nq_onAssignXor (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignXor"), self, left, right);
}

VALUE nq_onAssignRightShift (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignRightShift"), self, left, right);
}

VALUE nq_onAssignLeftShift (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignLeftShift"), self, left, right);
}

VALUE nq_onAssignDiv (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignDiv"), self, left, right);
}

VALUE nq_onAssignMul (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignMul"), self, left, right);
}

VALUE nq_onAssignExp (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignExp"), self, left, right);
}

VALUE nq_onAssignSub (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignSub"), self, left, right);
}

VALUE nq_onAssignAdd (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignAdd"), self, left, right);
}

VALUE nq_onAssign (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssign"), self, left, right);
}

VALUE nq_onAdd (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onAdd"), self, left, right);
}

VALUE nq_onSub (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onSub"), self, left, right);
}

VALUE nq_onMod (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onMod"), self, left, right);
}

VALUE nq_onMul (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onMul"), self, left, right);
}

VALUE nq_onExp (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onExp"), self, left, right);
}

VALUE nq_onDiv (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onDiv"), self, left, right);
}

VALUE nq_onRangeLiteral (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onRangeLiteral"), self, left, right);
}

VALUE nq_onBinaryLeftShift (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onBinaryLeftShift"), self, left, right);
}

VALUE nq_onBinaryRightShift (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onBinaryRightShift"), self, left, right);
}

VALUE nq_onLogicalOr (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onLogicalOr"), self, left, right);
}

VALUE nq_onLogicalAnd (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onLogicalAnd"), self, left, right);
}

VALUE nq_onBinaryOr (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onBinaryOr"), self, left, right);
}

VALUE nq_onBinaryXor (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onBinaryXor"), self, left, right);
}

VALUE nq_onBinaryAnd (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onBinaryAnd"), self, left, right);
}

VALUE nq_onLogicalNot (VALUE self, VALUE inner)
{
  rb_funcall(cNagaqueen, rb_intern("onLogicalNot"), self, inner);
}

VALUE nq_onBinaryNot (VALUE self, VALUE inner)
{
  rb_funcall(cNagaqueen, rb_intern("onBinaryNot"), self, inner);
}

VALUE nq_onUnaryMinus (VALUE self, VALUE inner)
{
  rb_funcall(cNagaqueen, rb_intern("onUnaryMinus"), self, inner);
}

VALUE nq_onParenthesis (VALUE self, VALUE inner)
{
  rb_funcall(cNagaqueen, rb_intern("onParenthesis"), self, inner);
}

char* nq_onGenericArgument (VALUE self, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onGenericArgument"), self, rb_str_new2(name));
}

VALUE nq_onAddressOf   (VALUE self, VALUE inner)
{
  rb_funcall(cNagaqueen, rb_intern("onAddressOf  "), self, inner);
}

VALUE nq_onDereference (VALUE self, VALUE inner)
{
  rb_funcall(cNagaqueen, rb_intern("onDereference"), self, inner);
}

VALUE nq_onMatchStart (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onMatchStart"), self);
}

VALUE nq_onMatchExpr (VALUE self, VALUE value)
{
  rb_funcall(cNagaqueen, rb_intern("onMatchExpr"), self, value);
}

VALUE nq_onMatchEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onMatchEnd"), self);
}

VALUE nq_onCaseStart (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onCaseStart"), self);
}

VALUE nq_onCaseExpr (VALUE self, VALUE value)
{
  rb_funcall(cNagaqueen, rb_intern("onCaseExpr"), self, value);
}

VALUE nq_onCaseEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onCaseEnd"), self);
}

VALUE nq_onTryStart (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onTryStart"), self);
}

VALUE nq_onTryEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onTryEnd"), self);
}

VALUE nq_onCatchStart (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onCatchStart"), self);
}

VALUE nq_onCatchExpr (VALUE self, VALUE value)
{
  rb_funcall(cNagaqueen, rb_intern("onCatchExpr"), self, value);
}

VALUE nq_onCatchEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onCatchEnd"), self);
}

int nq_error (VALUE self, int errorID, char* defaultMessage, int index)
{
  rb_funcall(cNagaqueen, rb_intern("error"), self, INT2NUM(errorID), rb_str_new2(defaultMessage), INT2NUM(index));
}

