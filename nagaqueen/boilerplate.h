void  nq_setTokenPositionPointer (VALUE self, int* tokenPosPointer)
{
  rb_funcall(cNagaqueen, rb_intern("setTokenPositionPointer"), 2, self, INT2NUM(*tokenPosPointer));
}

char * nq_StringClone (char* string)
{
  rb_funcall(cNagaqueen, rb_intern("StringClone"), 1, rb_str_new2(string));
}

char * nq_trailingQuest (char* string)
{
  rb_funcall(cNagaqueen, rb_intern("trailingQuest"), 1, rb_str_new2(string));
}

char * nq_trailingBang  (char* string)
{
  rb_funcall(cNagaqueen, rb_intern("trailingBang "), 1, rb_str_new2(string));
}

void  nq_onUse (VALUE self, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onUse"), 2, self, rb_str_new2(name));
}

void  nq_onInclude (VALUE self, char* path)
{
  rb_funcall(cNagaqueen, rb_intern("onInclude"), 2, self, rb_str_new2(path));
}

void  nq_onIncludeDefine (VALUE self, char* name, char* value)
{
  rb_funcall(cNagaqueen, rb_intern("onIncludeDefine"), 3, self, rb_str_new2(name), rb_str_new2(value));
}

void  nq_onImport  (VALUE self, char* path, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onImport "), 3, self, rb_str_new2(path), rb_str_new2(name));
}

void  nq_onImportNamespace (VALUE self, char* namespace, int quantity)
{
  rb_funcall(cNagaqueen, rb_intern("onImportNamespace"), 3, self, rb_str_new2(namespace), INT2NUM(quantity));
}

void * nq_onVersionName (VALUE self, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onVersionName"), 2, self, rb_str_new2(name));
}

void * nq_onVersionNegation (VALUE self, VALUE spec)
{
  rb_funcall(cNagaqueen, rb_intern("onVersionNegation"), 2, self, spec);
}

void * nq_onVersionAnd (VALUE self, VALUE specLeft, VALUE specRight)
{
  rb_funcall(cNagaqueen, rb_intern("onVersionAnd"), 3, self, specLeft, specRight);
}

void * nq_onVersionOr (VALUE self, VALUE specLeft, VALUE specRight)
{
  rb_funcall(cNagaqueen, rb_intern("onVersionOr"), 3, self, specLeft, specRight);
}

void  nq_onVersionStart (VALUE self, VALUE spec)
{
  rb_funcall(cNagaqueen, rb_intern("onVersionStart"), 2, self, spec);
}

void * nq_onVersionElseIfStart (VALUE self, VALUE notSpec, VALUE elseSpec)
{
  rb_funcall(cNagaqueen, rb_intern("onVersionElseIfStart"), 3, self, notSpec, elseSpec);
}

void  nq_onVersionElseStart (VALUE self, VALUE notSpec)
{
  rb_funcall(cNagaqueen, rb_intern("onVersionElseStart"), 2, self, notSpec);
}

void * nq_onVersionEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onVersionEnd"), 1, self);
}

void  nq_onExtendStart (VALUE self, VALUE type, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onExtendStart"), 3, self, type, rb_str_new2(doc));
}

void  nq_onExtendEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onExtendEnd"), 1, self);
}

void  nq_onCoverStart (VALUE self, char* name, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onCoverStart"), 3, self, rb_str_new2(name), rb_str_new2(doc));
}

void  nq_onCoverExtern (VALUE self, char* externName)
{
  rb_funcall(cNagaqueen, rb_intern("onCoverExtern"), 2, self, rb_str_new2(externName));
}

void  nq_onCoverFromType (VALUE self, VALUE type)
{
  rb_funcall(cNagaqueen, rb_intern("onCoverFromType"), 2, self, type);
}

void  nq_onCoverExtends (VALUE self, VALUE type)
{
  rb_funcall(cNagaqueen, rb_intern("onCoverExtends"), 2, self, type);
}

void  nq_onCoverImplements (VALUE self, VALUE type)
{
  rb_funcall(cNagaqueen, rb_intern("onCoverImplements"), 2, self, type);
}

void  nq_onCoverEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onCoverEnd"), 1, self);
}

void  nq_onEnumStart (VALUE self, char* name, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onEnumStart"), 3, self, rb_str_new2(name), rb_str_new2(doc));
}

void  nq_onEnumExtern (VALUE self, char* externName)
{
  rb_funcall(cNagaqueen, rb_intern("onEnumExtern"), 2, self, rb_str_new2(externName));
}

void  nq_onEnumFromType (VALUE self, VALUE fromType)
{
  rb_funcall(cNagaqueen, rb_intern("onEnumFromType"), 2, self, fromType);
}

void  nq_onEnumIncrementExpr (VALUE self, char oper, VALUE step)
{
  rb_funcall(cNagaqueen, rb_intern("onEnumIncrementExpr"), 3, self, oper, step);
}

void  nq_onEnumElementStart (VALUE self, char* name, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onEnumElementStart"), 3, self, rb_str_new2(name), rb_str_new2(doc));
}

void  nq_onEnumElementValue (VALUE self, VALUE value)
{
  rb_funcall(cNagaqueen, rb_intern("onEnumElementValue"), 2, self, value);
}

void  nq_onEnumElementExtern (VALUE self, char* externName)
{
  rb_funcall(cNagaqueen, rb_intern("onEnumElementExtern"), 2, self, rb_str_new2(externName));
}

void  nq_onEnumElementEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onEnumElementEnd"), 1, self);
}

void  nq_onEnumEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onEnumEnd"), 1, self);
}

void  nq_onClassStart (VALUE self, char* name, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onClassStart"), 3, self, rb_str_new2(name), rb_str_new2(doc));
}

void  nq_onClassAbstract (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onClassAbstract"), 1, self);
}

void  nq_onClassFinal (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onClassFinal"), 1, self);
}

void  nq_onClassExtends (VALUE self, VALUE type)
{
  rb_funcall(cNagaqueen, rb_intern("onClassExtends"), 2, self, type);
}

void  nq_onClassImplements (VALUE self, VALUE type)
{
  rb_funcall(cNagaqueen, rb_intern("onClassImplements"), 2, self, type);
}

void  nq_onClassBody (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onClassBody"), 1, self);
}

void  nq_onClassEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onClassEnd"), 1, self);
}

void  nq_onInterfaceStart (VALUE self, char* name, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onInterfaceStart"), 3, self, rb_str_new2(name), rb_str_new2(doc));
}

void  nq_onInterfaceExtends (VALUE self, VALUE type)
{
  rb_funcall(cNagaqueen, rb_intern("onInterfaceExtends"), 2, self, type);
}

void  nq_onInterfaceEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onInterfaceEnd"), 1, self);
}

void  nq_onPropertyDeclStart (VALUE self, char* name, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onPropertyDeclStart"), 3, self, rb_str_new2(name), rb_str_new2(doc));
}

void  nq_onPropertyDeclStatic (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onPropertyDeclStatic"), 1, self);
}

void  nq_onPropertyDeclType (VALUE self, VALUE type)
{
  rb_funcall(cNagaqueen, rb_intern("onPropertyDeclType"), 2, self, type);
}

void * nq_onPropertyDeclEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onPropertyDeclEnd"), 1, self);
}

void  nq_onPropertyDeclGetterStart (VALUE self, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onPropertyDeclGetterStart"), 2, self, rb_str_new2(doc));
}

void * nq_onPropertyDeclGetterEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onPropertyDeclGetterEnd"), 1, self);
}

void  nq_onPropertyDeclSetterStart (VALUE self, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onPropertyDeclSetterStart"), 2, self, rb_str_new2(doc));
}

void  nq_onPropertyDeclSetterArgument (VALUE self, char* name, _Bool conventional)
{
  rb_funcall(cNagaqueen, rb_intern("onPropertyDeclSetterArgument"), 3, self, rb_str_new2(name), conventional);
}

void * nq_onPropertyDeclSetterEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onPropertyDeclSetterEnd"), 1, self);
}

void  nq_onVarDeclStart (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclStart"), 1, self);
}

void  nq_onVarDeclName (VALUE self, char* name, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclName"), 3, self, rb_str_new2(name), rb_str_new2(doc));
}

void  nq_onVarDeclTuple (VALUE self, VALUE tuple)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclTuple"), 2, self, tuple);
}

void  nq_onVarDeclExtern (VALUE self, char* externName)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclExtern"), 2, self, rb_str_new2(externName));
}

void  nq_onVarDeclUnmangled (VALUE self, char* unmangledName)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclUnmangled"), 2, self, rb_str_new2(unmangledName));
}

void  nq_onVarDeclExpr (VALUE self, VALUE expr)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclExpr"), 2, self, expr);
}

void  nq_onVarDeclType (VALUE self, VALUE type)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclType"), 2, self, type);
}

void  nq_onVarDeclStatic (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclStatic"), 1, self);
}

void  nq_onVarDeclConst (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclConst"), 1, self);
}

void  nq_onVarDeclProto (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclProto"), 1, self);
}

void * nq_onVarDeclEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclEnd"), 1, self);
}

void * nq_onTypeAccess (VALUE self, VALUE type)
{
  rb_funcall(cNagaqueen, rb_intern("onTypeAccess"), 2, self, type);
}

void * nq_onTypeNew (VALUE self, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onTypeNew"), 2, self, rb_str_new2(name));
}

void * nq_onTypePointer (VALUE self, VALUE type)
{
  rb_funcall(cNagaqueen, rb_intern("onTypePointer"), 2, self, type);
}

void * nq_onTypeReference (VALUE self, VALUE type)
{
  rb_funcall(cNagaqueen, rb_intern("onTypeReference"), 2, self, type);
}

void * nq_onTypeBrackets (VALUE self, VALUE type, VALUE inner)
{
  rb_funcall(cNagaqueen, rb_intern("onTypeBrackets"), 3, self, type, inner);
}

void  nq_onTypeGenericArgument (VALUE self, VALUE type, VALUE genType)
{
  rb_funcall(cNagaqueen, rb_intern("onTypeGenericArgument"), 3, self, type, genType);
}

void  nq_onFuncTypeGenericArgument (VALUE self, VALUE type, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onFuncTypeGenericArgument"), 3, self, type, rb_str_new2(name));
}

void * nq_onTypeList (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onTypeList"), 1, self);
}

void * nq_onTypeListElement (VALUE self, VALUE list, VALUE elem)
{
  rb_funcall(cNagaqueen, rb_intern("onTypeListElement"), 3, self, list, elem);
}

void  nq_onTypeNamespace (VALUE self, VALUE type, VALUE ident)
{
  rb_funcall(cNagaqueen, rb_intern("onTypeNamespace"), 3, self, type, ident);
}

void * nq_onFuncTypeNew (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onFuncTypeNew"), 1, self);
}

void  nq_onFuncTypeArgument (VALUE self, VALUE funcType, VALUE argType)
{
  rb_funcall(cNagaqueen, rb_intern("onFuncTypeArgument"), 3, self, funcType, argType);
}

void  nq_onFuncTypeVarArg (VALUE self, VALUE funcType)
{
  rb_funcall(cNagaqueen, rb_intern("onFuncTypeVarArg"), 2, self, funcType);
}

void  nq_onFuncTypeReturnType (VALUE self, VALUE funcType, VALUE returnType)
{
  rb_funcall(cNagaqueen, rb_intern("onFuncTypeReturnType"), 3, self, funcType, returnType);
}

void  nq_onOperatorStart (VALUE self, char* symbol)
{
  rb_funcall(cNagaqueen, rb_intern("onOperatorStart"), 2, self, rb_str_new2(symbol));
}

void  nq_onOperatorEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onOperatorEnd"), 1, self);
}

void  nq_onFunctionStart (VALUE self, char* name, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionStart"), 3, self, rb_str_new2(name), rb_str_new2(doc));
}

void  nq_onFunctionExtern (VALUE self, char* externName)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionExtern"), 2, self, rb_str_new2(externName));
}

void  nq_onFunctionUnmangled (VALUE self, char* unmangledName)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionUnmangled"), 2, self, rb_str_new2(unmangledName));
}

void  nq_onFunctionAbstract (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionAbstract"), 1, self);
}

void  nq_onFunctionThisRef (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionThisRef"), 1, self);
}

void  nq_onFunctionArgsStart (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionArgsStart"), 1, self);
}

void  nq_onFunctionArgsEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionArgsEnd"), 1, self);
}

void  nq_onFunctionReturnType (VALUE self, VALUE type)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionReturnType"), 2, self, type);
}

void  nq_onFunctionConst (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionConst"), 1, self);
}

void  nq_onFunctionStatic (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionStatic"), 1, self);
}

void  nq_onFunctionInline (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionInline"), 1, self);
}

void  nq_onFunctionFinal (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionFinal"), 1, self);
}

void  nq_onFunctionProto (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionProto"), 1, self);
}

void  nq_onFunctionSuper (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionSuper"), 1, self);
}

void  nq_onFunctionSuffix (VALUE self, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionSuffix"), 2, self, rb_str_new2(name));
}

void  nq_onFunctionBody (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionBody"), 1, self);
}

void * nq_onFunctionEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionEnd"), 1, self);
}

void  nq_onTypeArg (VALUE self, VALUE type)
{
  rb_funcall(cNagaqueen, rb_intern("onTypeArg"), 2, self, type);
}

void  nq_onVarArg (VALUE self, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onVarArg"), 2, self, rb_str_new2(name));
}

void  nq_onDotArg (VALUE self, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onDotArg"), 2, self, rb_str_new2(name));
}

void  nq_onAssArg (VALUE self, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onAssArg"), 2, self, rb_str_new2(name));
}

void  nq_onFunctionCallStart (VALUE self, char* yytext)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionCallStart"), 2, self, rb_str_new2(yytext));
}

void  nq_onFunctionCallSuffix (VALUE self, char* yytext)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionCallSuffix"), 2, self, rb_str_new2(yytext));
}

void  nq_onFunctionCallArg (VALUE self, VALUE expr)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionCallArg"), 2, self, expr);
}

void * nq_onFunctionCallEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionCallEnd"), 1, self);
}

void  nq_onFunctionCallExpr (VALUE self, VALUE call, VALUE expr)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionCallExpr"), 3, self, call, expr);
}

void * nq_onFunctionCallChain (VALUE self, VALUE expr, VALUE call)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionCallChain"), 3, self, expr, call);
}

void  nq_onFunctionCallCombo (VALUE self, VALUE call, VALUE expr)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionCallCombo"), 3, self, call, expr);
}

void  nq_onArrayLiteralStart (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onArrayLiteralStart"), 1, self);
}

void * nq_onArrayLiteralEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onArrayLiteralEnd"), 1, self);
}

void  nq_onTupleStart (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onTupleStart"), 1, self);
}

void * nq_onTupleEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onTupleEnd"), 1, self);
}

void * nq_onStringLiteral (VALUE self, char* text)
{
  rb_funcall(cNagaqueen, rb_intern("onStringLiteral"), 2, self, rb_str_new2(text));
}

void * nq_onCharLiteral (VALUE self, char* value)
{
  rb_funcall(cNagaqueen, rb_intern("onCharLiteral"), 2, self, rb_str_new2(value));
}

void  nq_onStatement (VALUE self, VALUE statement)
{
  rb_funcall(cNagaqueen, rb_intern("onStatement"), 2, self, statement);
}

void * nq_onReturn (VALUE self, VALUE expr)
{
  rb_funcall(cNagaqueen, rb_intern("onReturn"), 2, self, expr);
}

void * nq_onVarAccess (VALUE self, VALUE expr, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onVarAccess"), 3, self, expr, rb_str_new2(name));
}

void  nq_onArrayAccessStart (VALUE self, VALUE array)
{
  rb_funcall(cNagaqueen, rb_intern("onArrayAccessStart"), 2, self, array);
}

void * nq_onArrayAccessEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onArrayAccessEnd"), 1, self);
}

void * nq_onCast (VALUE self, VALUE expr, VALUE type)
{
  rb_funcall(cNagaqueen, rb_intern("onCast"), 3, self, expr, type);
}

void * nq_onBreak (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onBreak"), 1, self);
}

void * nq_onContinue (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onContinue"), 1, self);
}

void  nq_onBlockStart (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onBlockStart"), 1, self);
}

void * nq_onBlockEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onBlockEnd"), 1, self);
}

void  nq_onIfStart (VALUE self, VALUE condition)
{
  rb_funcall(cNagaqueen, rb_intern("onIfStart"), 2, self, condition);
}

void * nq_onIfEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onIfEnd"), 1, self);
}

void  nq_onElseStart (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onElseStart"), 1, self);
}

void * nq_onElseEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onElseEnd"), 1, self);
}

void  nq_onForeachStart (VALUE self, VALUE decl, VALUE collec)
{
  rb_funcall(cNagaqueen, rb_intern("onForeachStart"), 3, self, decl, collec);
}

void * nq_onForeachEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onForeachEnd"), 1, self);
}

void  nq_onWhileStart (VALUE self, VALUE condition)
{
  rb_funcall(cNagaqueen, rb_intern("onWhileStart"), 2, self, condition);
}

void * nq_onWhileEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onWhileEnd"), 1, self);
}

void * nq_onEquals (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onEquals"), 3, self, left, right);
}

void * nq_onNotEquals (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onNotEquals"), 3, self, left, right);
}

void * nq_onLessThan (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onLessThan"), 3, self, left, right);
}

void * nq_onMoreThan (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onMoreThan"), 3, self, left, right);
}

void * nq_onCmp (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onCmp"), 3, self, left, right);
}

void * nq_onLessThanOrEqual (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onLessThanOrEqual"), 3, self, left, right);
}

void * nq_onMoreThanOrEqual (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onMoreThanOrEqual"), 3, self, left, right);
}

void * nq_onDecLiteral (VALUE self, char* value)
{
  rb_funcall(cNagaqueen, rb_intern("onDecLiteral"), 2, self, rb_str_new2(value));
}

void * nq_onBinLiteral (VALUE self, char* value)
{
  rb_funcall(cNagaqueen, rb_intern("onBinLiteral"), 2, self, rb_str_new2(value));
}

void * nq_onOctLiteral (VALUE self, char* value)
{
  rb_funcall(cNagaqueen, rb_intern("onOctLiteral"), 2, self, rb_str_new2(value));
}

void * nq_onHexLiteral (VALUE self, char* value)
{
  rb_funcall(cNagaqueen, rb_intern("onHexLiteral"), 2, self, rb_str_new2(value));
}

void * nq_onFloatLiteral (VALUE self, char* value)
{
  rb_funcall(cNagaqueen, rb_intern("onFloatLiteral"), 2, self, rb_str_new2(value));
}

void * nq_onBoolLiteral (VALUE self, bool value)
{
  rb_funcall(cNagaqueen, rb_intern("onBoolLiteral"), 2, self, value);
}

void * nq_onNull (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onNull"), 1, self);
}

void * nq_onDoubleArrow (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onDoubleArrow"), 3, self, left, right);
}

void * nq_onTernary (VALUE self, VALUE condition, VALUE ifTrue, VALUE ifFalse)
{
  rb_funcall(cNagaqueen, rb_intern("onTernary"), 4, self, condition, ifTrue, ifFalse);
}

void * nq_onAssignAnd (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignAnd"), 3, self, left, right);
}

void * nq_onAssignOr (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignOr"), 3, self, left, right);
}

void * nq_onAssignXor (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignXor"), 3, self, left, right);
}

void * nq_onAssignRightShift (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignRightShift"), 3, self, left, right);
}

void * nq_onAssignLeftShift (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignLeftShift"), 3, self, left, right);
}

void * nq_onAssignDiv (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignDiv"), 3, self, left, right);
}

void * nq_onAssignMul (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignMul"), 3, self, left, right);
}

void * nq_onAssignExp (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignExp"), 3, self, left, right);
}

void * nq_onAssignSub (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignSub"), 3, self, left, right);
}

void * nq_onAssignAdd (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignAdd"), 3, self, left, right);
}

void * nq_onAssign (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssign"), 3, self, left, right);
}

void * nq_onAdd (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onAdd"), 3, self, left, right);
}

void * nq_onSub (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onSub"), 3, self, left, right);
}

void * nq_onMod (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onMod"), 3, self, left, right);
}

void * nq_onMul (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onMul"), 3, self, left, right);
}

void * nq_onExp (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onExp"), 3, self, left, right);
}

void * nq_onDiv (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onDiv"), 3, self, left, right);
}

void * nq_onRangeLiteral (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onRangeLiteral"), 3, self, left, right);
}

void * nq_onBinaryLeftShift (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onBinaryLeftShift"), 3, self, left, right);
}

void * nq_onBinaryRightShift (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onBinaryRightShift"), 3, self, left, right);
}

void * nq_onLogicalOr (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onLogicalOr"), 3, self, left, right);
}

void * nq_onLogicalAnd (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onLogicalAnd"), 3, self, left, right);
}

void * nq_onBinaryOr (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onBinaryOr"), 3, self, left, right);
}

void * nq_onBinaryXor (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onBinaryXor"), 3, self, left, right);
}

void * nq_onBinaryAnd (VALUE self, VALUE left, VALUE right)
{
  rb_funcall(cNagaqueen, rb_intern("onBinaryAnd"), 3, self, left, right);
}

void * nq_onLogicalNot (VALUE self, VALUE inner)
{
  rb_funcall(cNagaqueen, rb_intern("onLogicalNot"), 2, self, inner);
}

void * nq_onBinaryNot (VALUE self, VALUE inner)
{
  rb_funcall(cNagaqueen, rb_intern("onBinaryNot"), 2, self, inner);
}

void * nq_onUnaryMinus (VALUE self, VALUE inner)
{
  rb_funcall(cNagaqueen, rb_intern("onUnaryMinus"), 2, self, inner);
}

void * nq_onParenthesis (VALUE self, VALUE inner)
{
  rb_funcall(cNagaqueen, rb_intern("onParenthesis"), 2, self, inner);
}

void  nq_onGenericArgument (VALUE self, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onGenericArgument"), 2, self, rb_str_new2(name));
}

void * nq_onAddressOf   (VALUE self, VALUE inner)
{
  rb_funcall(cNagaqueen, rb_intern("onAddressOf  "), 2, self, inner);
}

void * nq_onDereference (VALUE self, VALUE inner)
{
  rb_funcall(cNagaqueen, rb_intern("onDereference"), 2, self, inner);
}

void  nq_onMatchStart (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onMatchStart"), 1, self);
}

void  nq_onMatchExpr (VALUE self, VALUE value)
{
  rb_funcall(cNagaqueen, rb_intern("onMatchExpr"), 2, self, value);
}

void * nq_onMatchEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onMatchEnd"), 1, self);
}

void  nq_onCaseStart (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onCaseStart"), 1, self);
}

void  nq_onCaseExpr (VALUE self, VALUE value)
{
  rb_funcall(cNagaqueen, rb_intern("onCaseExpr"), 2, self, value);
}

void  nq_onCaseEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onCaseEnd"), 1, self);
}

void  nq_onTryStart (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onTryStart"), 1, self);
}

void * nq_onTryEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onTryEnd"), 1, self);
}

void  nq_onCatchStart (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onCatchStart"), 1, self);
}

void  nq_onCatchExpr (VALUE self, VALUE value)
{
  rb_funcall(cNagaqueen, rb_intern("onCatchExpr"), 2, self, value);
}

void  nq_onCatchEnd (VALUE self)
{
  rb_funcall(cNagaqueen, rb_intern("onCatchEnd"), 1, self);
}

void  nq_error (VALUE self, int errorID, char* defaultMessage, int index)
{
  rb_funcall(cNagaqueen, rb_intern("error"), 4, self, INT2NUM(errorID), rb_str_new2(defaultMessage), INT2NUM(index));
}

