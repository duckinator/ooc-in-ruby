void nq_setTokenPositionPointer (void* this, int* tokenPosPointer)
{
  rb_funcall((VALUE)(this), rb_intern("setTokenPositionPointer"), 1,  INT2NUM(*tokenPosPointer));
}

char * nq_StringClone (char* string)
{
  VALUE *tmp = malloc(sizeof(VALUE));
  *tmp = rb_funcall(cNagaqueen, rb_intern("StringClone"), 1,  rb_str_new2(string));
  return rb_string_value_cstr(tmp);
}

char * nq_trailingQuest (char* string)
{
  VALUE *tmp = malloc(sizeof(VALUE));
  *tmp = rb_funcall(cNagaqueen, rb_intern("trailingQuest"), 1,  rb_str_new2(string));
  return rb_string_value_cstr(tmp);
}

char * nq_trailingBang (char* string)
{
  VALUE *tmp = malloc(sizeof(VALUE));
  *tmp = rb_funcall(cNagaqueen, rb_intern("trailingBang"), 1,  rb_str_new2(string));
  return rb_string_value_cstr(tmp);
}

void nq_onUse (void* this, char* name)
{
  rb_funcall((VALUE)(this), rb_intern("onUse"), 1,  rb_str_new2(name));
}

void nq_onInclude (void* this, char* path)
{
  rb_funcall((VALUE)(this), rb_intern("onInclude"), 1,  rb_str_new2(path));
}

void nq_onIncludeDefine (void* this, char* name, char* value)
{
  rb_funcall((VALUE)(this), rb_intern("onIncludeDefine"), 2,  rb_str_new2(name), rb_str_new2(value));
}

void nq_onImport (void* this, char* path, char* name)
{
  rb_funcall((VALUE)(this), rb_intern("onImport"), 2,  rb_str_new2(path), rb_str_new2(name));
}

void nq_onImportNamespace (void* this, char* namespace, int quantity)
{
  rb_funcall((VALUE)(this), rb_intern("onImportNamespace"), 2,  rb_str_new2(namespace), INT2NUM(quantity));
}

void * nq_onVersionName (void* this, char* name)
{
  rb_funcall((VALUE)(this), rb_intern("onVersionName"), 1,  rb_str_new2(name));
}

void * nq_onVersionNegation (void* this, void* spec)
{
  rb_funcall((VALUE)(this), rb_intern("onVersionNegation"), 1,  spec);
}

void * nq_onVersionAnd (void* this, void* specLeft, void* specRight)
{
  rb_funcall((VALUE)(this), rb_intern("onVersionAnd"), 2,  specLeft, specRight);
}

void * nq_onVersionOr (void* this, void* specLeft, void* specRight)
{
  rb_funcall((VALUE)(this), rb_intern("onVersionOr"), 2,  specLeft, specRight);
}

void nq_onVersionStart (void* this, void* spec)
{
  rb_funcall((VALUE)(this), rb_intern("onVersionStart"), 1,  spec);
}

void * nq_onVersionElseIfStart (void* this, void* notSpec, void* elseSpec)
{
  rb_funcall((VALUE)(this), rb_intern("onVersionElseIfStart"), 2,  notSpec, elseSpec);
}

void nq_onVersionElseStart (void* this, void* notSpec)
{
  rb_funcall((VALUE)(this), rb_intern("onVersionElseStart"), 1,  notSpec);
}

void * nq_onVersionEnd (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onVersionEnd"), 0 );
}

void nq_onExtendStart (void* this, void* type, char* doc)
{
  rb_funcall((VALUE)(this), rb_intern("onExtendStart"), 2,  type, rb_str_new2(doc));
}

void nq_onExtendEnd (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onExtendEnd"), 0 );
}

void nq_onCoverStart (void* this, char* name, char* doc)
{
  rb_funcall((VALUE)(this), rb_intern("onCoverStart"), 2,  rb_str_new2(name), rb_str_new2(doc));
}

void nq_onCoverExtern (void* this, char* externName)
{
  rb_funcall((VALUE)(this), rb_intern("onCoverExtern"), 1,  rb_str_new2(externName));
}

void nq_onCoverFromType (void* this, void* type)
{
  rb_funcall((VALUE)(this), rb_intern("onCoverFromType"), 1,  type);
}

void nq_onCoverExtends (void* this, void* type)
{
  rb_funcall((VALUE)(this), rb_intern("onCoverExtends"), 1,  type);
}

void nq_onCoverImplements (void* this, void* type)
{
  rb_funcall((VALUE)(this), rb_intern("onCoverImplements"), 1,  type);
}

void nq_onCoverEnd (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onCoverEnd"), 0 );
}

void nq_onEnumStart (void* this, char* name, char* doc)
{
  rb_funcall((VALUE)(this), rb_intern("onEnumStart"), 2,  rb_str_new2(name), rb_str_new2(doc));
}

void nq_onEnumExtern (void* this, char* externName)
{
  rb_funcall((VALUE)(this), rb_intern("onEnumExtern"), 1,  rb_str_new2(externName));
}

void nq_onEnumFromType (void* this, void* fromType)
{
  rb_funcall((VALUE)(this), rb_intern("onEnumFromType"), 1,  fromType);
}

void nq_onEnumIncrementExpr (void* this, char oper, void* step)
{
  rb_funcall((VALUE)(this), rb_intern("onEnumIncrementExpr"), 2,  oper, step);
}

void nq_onEnumElementStart (void* this, char* name, char* doc)
{
  rb_funcall((VALUE)(this), rb_intern("onEnumElementStart"), 2,  rb_str_new2(name), rb_str_new2(doc));
}

void nq_onEnumElementValue (void* this, void* value)
{
  rb_funcall((VALUE)(this), rb_intern("onEnumElementValue"), 1,  value);
}

void nq_onEnumElementExtern (void* this, char* externName)
{
  rb_funcall((VALUE)(this), rb_intern("onEnumElementExtern"), 1,  rb_str_new2(externName));
}

void nq_onEnumElementEnd (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onEnumElementEnd"), 0 );
}

void nq_onEnumEnd (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onEnumEnd"), 0 );
}

void nq_onClassStart (void* this, char* name, char* doc)
{
  rb_funcall((VALUE)(this), rb_intern("onClassStart"), 2,  rb_str_new2(name), rb_str_new2(doc));
}

void nq_onClassAbstract (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onClassAbstract"), 0 );
}

void nq_onClassFinal (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onClassFinal"), 0 );
}

void nq_onClassExtends (void* this, void* type)
{
  rb_funcall((VALUE)(this), rb_intern("onClassExtends"), 1,  type);
}

void nq_onClassImplements (void* this, void* type)
{
  rb_funcall((VALUE)(this), rb_intern("onClassImplements"), 1,  type);
}

void nq_onClassBody (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onClassBody"), 0 );
}

void nq_onClassEnd (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onClassEnd"), 0 );
}

void nq_onInterfaceStart (void* this, char* name, char* doc)
{
  rb_funcall((VALUE)(this), rb_intern("onInterfaceStart"), 2,  rb_str_new2(name), rb_str_new2(doc));
}

void nq_onInterfaceExtends (void* this, void* type)
{
  rb_funcall((VALUE)(this), rb_intern("onInterfaceExtends"), 1,  type);
}

void nq_onInterfaceEnd (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onInterfaceEnd"), 0 );
}

void nq_onPropertyDeclStart (void* this, char* name, char* doc)
{
  rb_funcall((VALUE)(this), rb_intern("onPropertyDeclStart"), 2,  rb_str_new2(name), rb_str_new2(doc));
}

void nq_onPropertyDeclStatic (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onPropertyDeclStatic"), 0 );
}

void nq_onPropertyDeclType (void* this, void* type)
{
  rb_funcall((VALUE)(this), rb_intern("onPropertyDeclType"), 1,  type);
}

void * nq_onPropertyDeclEnd (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onPropertyDeclEnd"), 0 );
}

void nq_onPropertyDeclGetterStart (void* this, char* doc)
{
  rb_funcall((VALUE)(this), rb_intern("onPropertyDeclGetterStart"), 1,  rb_str_new2(doc));
}

void * nq_onPropertyDeclGetterEnd (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onPropertyDeclGetterEnd"), 0 );
}

void nq_onPropertyDeclSetterStart (void* this, char* doc)
{
  rb_funcall((VALUE)(this), rb_intern("onPropertyDeclSetterStart"), 1,  rb_str_new2(doc));
}

void nq_onPropertyDeclSetterArgument (void* this, char* name, _Bool conventional)
{
  rb_funcall((VALUE)(this), rb_intern("onPropertyDeclSetterArgument"), 2,  rb_str_new2(name), conventional);
}

void * nq_onPropertyDeclSetterEnd (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onPropertyDeclSetterEnd"), 0 );
}

void nq_onVarDeclStart (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onVarDeclStart"), 0 );
}

void nq_onVarDeclName (void* this, char* name, char* doc)
{
  rb_funcall((VALUE)(this), rb_intern("onVarDeclName"), 2,  rb_str_new2(name), rb_str_new2(doc));
}

void nq_onVarDeclTuple (void* this, void* tuple)
{
  rb_funcall((VALUE)(this), rb_intern("onVarDeclTuple"), 1,  tuple);
}

void nq_onVarDeclExtern (void* this, char* externName)
{
  rb_funcall((VALUE)(this), rb_intern("onVarDeclExtern"), 1,  rb_str_new2(externName));
}

void nq_onVarDeclUnmangled (void* this, char* unmangledName)
{
  rb_funcall((VALUE)(this), rb_intern("onVarDeclUnmangled"), 1,  rb_str_new2(unmangledName));
}

void nq_onVarDeclExpr (void* this, void* expr)
{
  rb_funcall((VALUE)(this), rb_intern("onVarDeclExpr"), 1,  expr);
}

void nq_onVarDeclType (void* this, void* type)
{
  rb_funcall((VALUE)(this), rb_intern("onVarDeclType"), 1,  type);
}

void nq_onVarDeclStatic (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onVarDeclStatic"), 0 );
}

void nq_onVarDeclConst (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onVarDeclConst"), 0 );
}

void nq_onVarDeclProto (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onVarDeclProto"), 0 );
}

void * nq_onVarDeclEnd (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onVarDeclEnd"), 0 );
}

void * nq_onTypeAccess (void* this, void* type)
{
  rb_funcall((VALUE)(this), rb_intern("onTypeAccess"), 1,  type);
}

void * nq_onTypeNew (void* this, char* name)
{
  rb_funcall((VALUE)(this), rb_intern("onTypeNew"), 1,  rb_str_new2(name));
}

void * nq_onTypePointer (void* this, void* type)
{
  rb_funcall((VALUE)(this), rb_intern("onTypePointer"), 1,  type);
}

void * nq_onTypeReference (void* this, void* type)
{
  rb_funcall((VALUE)(this), rb_intern("onTypeReference"), 1,  type);
}

void * nq_onTypeBrackets (void* this, void* type, void* inner)
{
  rb_funcall((VALUE)(this), rb_intern("onTypeBrackets"), 2,  type, inner);
}

void nq_onTypeGenericArgument (void* this, void* type, void* genType)
{
  rb_funcall((VALUE)(this), rb_intern("onTypeGenericArgument"), 2,  type, genType);
}

void nq_onFuncTypeGenericArgument (void* this, void* type, char* name)
{
  rb_funcall((VALUE)(this), rb_intern("onFuncTypeGenericArgument"), 2,  type, rb_str_new2(name));
}

void * nq_onTypeList (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onTypeList"), 0 );
}

void * nq_onTypeListElement (void* this, void* list, void* elem)
{
  rb_funcall((VALUE)(this), rb_intern("onTypeListElement"), 2,  list, elem);
}

void nq_onTypeNamespace (void* this, void* type, void* ident)
{
  rb_funcall((VALUE)(this), rb_intern("onTypeNamespace"), 2,  type, ident);
}

void * nq_onFuncTypeNew (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onFuncTypeNew"), 0 );
}

void nq_onFuncTypeArgument (void* this, void* funcType, void* argType)
{
  rb_funcall((VALUE)(this), rb_intern("onFuncTypeArgument"), 2,  funcType, argType);
}

void nq_onFuncTypeVarArg (void* this, void* funcType)
{
  rb_funcall((VALUE)(this), rb_intern("onFuncTypeVarArg"), 1,  funcType);
}

void nq_onFuncTypeReturnType (void* this, void* funcType, void* returnType)
{
  rb_funcall((VALUE)(this), rb_intern("onFuncTypeReturnType"), 2,  funcType, returnType);
}

void nq_onOperatorStart (void* this, char* symbol)
{
  rb_funcall((VALUE)(this), rb_intern("onOperatorStart"), 1,  rb_str_new2(symbol));
}

void nq_onOperatorEnd (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onOperatorEnd"), 0 );
}

void nq_onFunctionStart (void* this, char* name, char* doc)
{
  rb_funcall((VALUE)(this), rb_intern("onFunctionStart"), 2,  rb_str_new2(name), rb_str_new2(doc));
}

void nq_onFunctionExtern (void* this, char* externName)
{
  rb_funcall((VALUE)(this), rb_intern("onFunctionExtern"), 1,  rb_str_new2(externName));
}

void nq_onFunctionUnmangled (void* this, char* unmangledName)
{
  rb_funcall((VALUE)(this), rb_intern("onFunctionUnmangled"), 1,  rb_str_new2(unmangledName));
}

void nq_onFunctionAbstract (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onFunctionAbstract"), 0 );
}

void nq_onFunctionThisRef (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onFunctionThisRef"), 0 );
}

void nq_onFunctionArgsStart (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onFunctionArgsStart"), 0 );
}

void nq_onFunctionArgsEnd (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onFunctionArgsEnd"), 0 );
}

void nq_onFunctionReturnType (void* this, void* type)
{
  rb_funcall((VALUE)(this), rb_intern("onFunctionReturnType"), 1,  type);
}

void nq_onFunctionConst (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onFunctionConst"), 0 );
}

void nq_onFunctionStatic (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onFunctionStatic"), 0 );
}

void nq_onFunctionInline (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onFunctionInline"), 0 );
}

void nq_onFunctionFinal (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onFunctionFinal"), 0 );
}

void nq_onFunctionProto (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onFunctionProto"), 0 );
}

void nq_onFunctionSuper (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onFunctionSuper"), 0 );
}

void nq_onFunctionSuffix (void* this, char* name)
{
  rb_funcall((VALUE)(this), rb_intern("onFunctionSuffix"), 1,  rb_str_new2(name));
}

void nq_onFunctionBody (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onFunctionBody"), 0 );
}

void * nq_onFunctionEnd (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onFunctionEnd"), 0 );
}

void nq_onTypeArg (void* this, void* type)
{
  rb_funcall((VALUE)(this), rb_intern("onTypeArg"), 1,  type);
}

void nq_onVarArg (void* this, char* name)
{
  rb_funcall((VALUE)(this), rb_intern("onVarArg"), 1,  rb_str_new2(name));
}

void nq_onDotArg (void* this, char* name)
{
  rb_funcall((VALUE)(this), rb_intern("onDotArg"), 1,  rb_str_new2(name));
}

void nq_onAssArg (void* this, char* name)
{
  rb_funcall((VALUE)(this), rb_intern("onAssArg"), 1,  rb_str_new2(name));
}

void nq_onFunctionCallStart (void* this, char* yytext)
{
  rb_funcall((VALUE)(this), rb_intern("onFunctionCallStart"), 1,  rb_str_new2(yytext));
}

void nq_onFunctionCallSuffix (void* this, char* yytext)
{
  rb_funcall((VALUE)(this), rb_intern("onFunctionCallSuffix"), 1,  rb_str_new2(yytext));
}

void nq_onFunctionCallArg (void* this, void* expr)
{
  rb_funcall((VALUE)(this), rb_intern("onFunctionCallArg"), 1,  expr);
}

void * nq_onFunctionCallEnd (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onFunctionCallEnd"), 0 );
}

void nq_onFunctionCallExpr (void* this, void* call, void* expr)
{
  rb_funcall((VALUE)(this), rb_intern("onFunctionCallExpr"), 2,  call, expr);
}

void * nq_onFunctionCallChain (void* this, void* expr, void* call)
{
  rb_funcall((VALUE)(this), rb_intern("onFunctionCallChain"), 2,  expr, call);
}

void nq_onFunctionCallCombo (void* this, void* call, void* expr)
{
  rb_funcall((VALUE)(this), rb_intern("onFunctionCallCombo"), 2,  call, expr);
}

void nq_onArrayLiteralStart (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onArrayLiteralStart"), 0 );
}

void * nq_onArrayLiteralEnd (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onArrayLiteralEnd"), 0 );
}

void nq_onTupleStart (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onTupleStart"), 0 );
}

void * nq_onTupleEnd (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onTupleEnd"), 0 );
}

void * nq_onStringLiteral (void* this, char* text)
{
  rb_funcall((VALUE)(this), rb_intern("onStringLiteral"), 1,  rb_str_new2(text));
}

void * nq_onCharLiteral (void* this, char* value)
{
  rb_funcall((VALUE)(this), rb_intern("onCharLiteral"), 1,  rb_str_new2(value));
}

void nq_onStatement (void* this, void* statement)
{
  rb_funcall((VALUE)(this), rb_intern("onStatement"), 1,  statement);
}

void * nq_onReturn (void* this, void* expr)
{
  rb_funcall((VALUE)(this), rb_intern("onReturn"), 1,  expr);
}

void * nq_onVarAccess (void* this, void* expr, char* name)
{
  rb_funcall((VALUE)(this), rb_intern("onVarAccess"), 2,  expr, rb_str_new2(name));
}

void nq_onArrayAccessStart (void* this, void* array)
{
  rb_funcall((VALUE)(this), rb_intern("onArrayAccessStart"), 1,  array);
}

void * nq_onArrayAccessEnd (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onArrayAccessEnd"), 0 );
}

void * nq_onCast (void* this, void* expr, void* type)
{
  rb_funcall((VALUE)(this), rb_intern("onCast"), 2,  expr, type);
}

void * nq_onBreak (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onBreak"), 0 );
}

void * nq_onContinue (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onContinue"), 0 );
}

void nq_onBlockStart (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onBlockStart"), 0 );
}

void * nq_onBlockEnd (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onBlockEnd"), 0 );
}

void nq_onIfStart (void* this, void* condition)
{
  rb_funcall((VALUE)(this), rb_intern("onIfStart"), 1,  condition);
}

void * nq_onIfEnd (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onIfEnd"), 0 );
}

void nq_onElseStart (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onElseStart"), 0 );
}

void * nq_onElseEnd (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onElseEnd"), 0 );
}

void nq_onForeachStart (void* this, void* decl, void* collec)
{
  rb_funcall((VALUE)(this), rb_intern("onForeachStart"), 2,  decl, collec);
}

void * nq_onForeachEnd (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onForeachEnd"), 0 );
}

void nq_onWhileStart (void* this, void* condition)
{
  rb_funcall((VALUE)(this), rb_intern("onWhileStart"), 1,  condition);
}

void * nq_onWhileEnd (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onWhileEnd"), 0 );
}

void * nq_onEquals (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onEquals"), 2,  left, right);
}

void * nq_onNotEquals (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onNotEquals"), 2,  left, right);
}

void * nq_onLessThan (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onLessThan"), 2,  left, right);
}

void * nq_onMoreThan (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onMoreThan"), 2,  left, right);
}

void * nq_onCmp (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onCmp"), 2,  left, right);
}

void * nq_onLessThanOrEqual (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onLessThanOrEqual"), 2,  left, right);
}

void * nq_onMoreThanOrEqual (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onMoreThanOrEqual"), 2,  left, right);
}

void * nq_onDecLiteral (void* this, char* value)
{
  rb_funcall((VALUE)(this), rb_intern("onDecLiteral"), 1,  rb_str_new2(value));
}

void * nq_onBinLiteral (void* this, char* value)
{
  rb_funcall((VALUE)(this), rb_intern("onBinLiteral"), 1,  rb_str_new2(value));
}

void * nq_onOctLiteral (void* this, char* value)
{
  rb_funcall((VALUE)(this), rb_intern("onOctLiteral"), 1,  rb_str_new2(value));
}

void * nq_onHexLiteral (void* this, char* value)
{
  rb_funcall((VALUE)(this), rb_intern("onHexLiteral"), 1,  rb_str_new2(value));
}

void * nq_onFloatLiteral (void* this, char* value)
{
  rb_funcall((VALUE)(this), rb_intern("onFloatLiteral"), 1,  rb_str_new2(value));
}

void * nq_onBoolLiteral (void* this, bool value)
{
  rb_funcall((VALUE)(this), rb_intern("onBoolLiteral"), 1,  value);
}

void * nq_onNull (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onNull"), 0 );
}

void * nq_onDoubleArrow (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onDoubleArrow"), 2,  left, right);
}

void * nq_onTernary (void* this, void* condition, void* ifTrue, void* ifFalse)
{
  rb_funcall((VALUE)(this), rb_intern("onTernary"), 3,  condition, ifTrue, ifFalse);
}

void * nq_onAssignAnd (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onAssignAnd"), 2,  left, right);
}

void * nq_onAssignOr (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onAssignOr"), 2,  left, right);
}

void * nq_onAssignXor (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onAssignXor"), 2,  left, right);
}

void * nq_onAssignRightShift (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onAssignRightShift"), 2,  left, right);
}

void * nq_onAssignLeftShift (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onAssignLeftShift"), 2,  left, right);
}

void * nq_onAssignDiv (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onAssignDiv"), 2,  left, right);
}

void * nq_onAssignMul (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onAssignMul"), 2,  left, right);
}

void * nq_onAssignExp (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onAssignExp"), 2,  left, right);
}

void * nq_onAssignSub (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onAssignSub"), 2,  left, right);
}

void * nq_onAssignAdd (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onAssignAdd"), 2,  left, right);
}

void * nq_onAssign (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onAssign"), 2,  left, right);
}

void * nq_onAdd (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onAdd"), 2,  left, right);
}

void * nq_onSub (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onSub"), 2,  left, right);
}

void * nq_onMod (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onMod"), 2,  left, right);
}

void * nq_onMul (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onMul"), 2,  left, right);
}

void * nq_onExp (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onExp"), 2,  left, right);
}

void * nq_onDiv (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onDiv"), 2,  left, right);
}

void * nq_onRangeLiteral (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onRangeLiteral"), 2,  left, right);
}

void * nq_onBinaryLeftShift (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onBinaryLeftShift"), 2,  left, right);
}

void * nq_onBinaryRightShift (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onBinaryRightShift"), 2,  left, right);
}

void * nq_onLogicalOr (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onLogicalOr"), 2,  left, right);
}

void * nq_onLogicalAnd (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onLogicalAnd"), 2,  left, right);
}

void * nq_onBinaryOr (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onBinaryOr"), 2,  left, right);
}

void * nq_onBinaryXor (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onBinaryXor"), 2,  left, right);
}

void * nq_onBinaryAnd (void* this, void* left, void* right)
{
  rb_funcall((VALUE)(this), rb_intern("onBinaryAnd"), 2,  left, right);
}

void * nq_onLogicalNot (void* this, void* inner)
{
  rb_funcall((VALUE)(this), rb_intern("onLogicalNot"), 1,  inner);
}

void * nq_onBinaryNot (void* this, void* inner)
{
  rb_funcall((VALUE)(this), rb_intern("onBinaryNot"), 1,  inner);
}

void * nq_onUnaryMinus (void* this, void* inner)
{
  rb_funcall((VALUE)(this), rb_intern("onUnaryMinus"), 1,  inner);
}

void * nq_onParenthesis (void* this, void* inner)
{
  rb_funcall((VALUE)(this), rb_intern("onParenthesis"), 1,  inner);
}

void nq_onGenericArgument (void* this, char* name)
{
  rb_funcall((VALUE)(this), rb_intern("onGenericArgument"), 1,  rb_str_new2(name));
}

void * nq_onAddressOf (void* this, void* inner)
{
  rb_funcall((VALUE)(this), rb_intern("onAddressOf"), 1,  inner);
}

void * nq_onDereference (void* this, void* inner)
{
  rb_funcall((VALUE)(this), rb_intern("onDereference"), 1,  inner);
}

void nq_onMatchStart (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onMatchStart"), 0 );
}

void nq_onMatchExpr (void* this, void* value)
{
  rb_funcall((VALUE)(this), rb_intern("onMatchExpr"), 1,  value);
}

void * nq_onMatchEnd (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onMatchEnd"), 0 );
}

void nq_onCaseStart (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onCaseStart"), 0 );
}

void nq_onCaseExpr (void* this, void* value)
{
  rb_funcall((VALUE)(this), rb_intern("onCaseExpr"), 1,  value);
}

void nq_onCaseEnd (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onCaseEnd"), 0 );
}

void nq_onTryStart (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onTryStart"), 0 );
}

void * nq_onTryEnd (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onTryEnd"), 0 );
}

void nq_onCatchStart (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onCatchStart"), 0 );
}

void nq_onCatchExpr (void* this, void* value)
{
  rb_funcall((VALUE)(this), rb_intern("onCatchExpr"), 1,  value);
}

void nq_onCatchEnd (void* this)
{
  rb_funcall((VALUE)(this), rb_intern("onCatchEnd"), 0 );
}

void nq_error (void* this, int errorID, char* defaultMessage, int index)
{
  rb_funcall((VALUE)(this), rb_intern("error"), 3,  INT2NUM(errorID), rb_str_new2(defaultMessage), INT2NUM(index));
}

