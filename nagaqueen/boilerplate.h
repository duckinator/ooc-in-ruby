void nq_setTokenPositionPointer (void* self, int* tokenPosPointer)
{
  rb_funcall(cNagaqueen, rb_intern("setTokenPositionPointer"), 2, (VALUE)(self), INT2NUM(*tokenPosPointer));
}

char * nq_StringClone (char* string)
{
  rb_funcall(cNagaqueen, rb_intern("StringClone"), 1, rb_str_new2(string));
}

char * nq_trailingQuest (char* string)
{
  rb_funcall(cNagaqueen, rb_intern("trailingQuest"), 1, rb_str_new2(string));
}

char * nq_trailingBang (char* string)
{
  rb_funcall(cNagaqueen, rb_intern("trailingBang"), 1, rb_str_new2(string));
}

void nq_onUse (void* self, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onUse"), 2, (VALUE)(self), rb_str_new2(name));
}

void nq_onInclude (void* self, char* path)
{
  rb_funcall(cNagaqueen, rb_intern("onInclude"), 2, (VALUE)(self), rb_str_new2(path));
}

void nq_onIncludeDefine (void* self, char* name, char* value)
{
  rb_funcall(cNagaqueen, rb_intern("onIncludeDefine"), 3, (VALUE)(self), rb_str_new2(name), rb_str_new2(value));
}

void nq_onImport (void* self, char* path, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onImport"), 3, (VALUE)(self), rb_str_new2(path), rb_str_new2(name));
}

void nq_onImportNamespace (void* self, char* namespace, int quantity)
{
  rb_funcall(cNagaqueen, rb_intern("onImportNamespace"), 3, (VALUE)(self), rb_str_new2(namespace), INT2NUM(quantity));
}

void * nq_onVersionName (void* self, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onVersionName"), 2, (VALUE)(self), rb_str_new2(name));
}

void * nq_onVersionNegation (void* self, void* spec)
{
  rb_funcall(cNagaqueen, rb_intern("onVersionNegation"), 2, (VALUE)(self), spec);
}

void * nq_onVersionAnd (void* self, void* specLeft, void* specRight)
{
  rb_funcall(cNagaqueen, rb_intern("onVersionAnd"), 3, (VALUE)(self), specLeft, specRight);
}

void * nq_onVersionOr (void* self, void* specLeft, void* specRight)
{
  rb_funcall(cNagaqueen, rb_intern("onVersionOr"), 3, (VALUE)(self), specLeft, specRight);
}

void nq_onVersionStart (void* self, void* spec)
{
  rb_funcall(cNagaqueen, rb_intern("onVersionStart"), 2, (VALUE)(self), spec);
}

void * nq_onVersionElseIfStart (void* self, void* notSpec, void* elseSpec)
{
  rb_funcall(cNagaqueen, rb_intern("onVersionElseIfStart"), 3, (VALUE)(self), notSpec, elseSpec);
}

void nq_onVersionElseStart (void* self, void* notSpec)
{
  rb_funcall(cNagaqueen, rb_intern("onVersionElseStart"), 2, (VALUE)(self), notSpec);
}

void * nq_onVersionEnd (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onVersionEnd"), 1, (VALUE)(self));
}

void nq_onExtendStart (void* self, void* type, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onExtendStart"), 3, (VALUE)(self), type, rb_str_new2(doc));
}

void nq_onExtendEnd (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onExtendEnd"), 1, (VALUE)(self));
}

void nq_onCoverStart (void* self, char* name, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onCoverStart"), 3, (VALUE)(self), rb_str_new2(name), rb_str_new2(doc));
}

void nq_onCoverExtern (void* self, char* externName)
{
  rb_funcall(cNagaqueen, rb_intern("onCoverExtern"), 2, (VALUE)(self), rb_str_new2(externName));
}

void nq_onCoverFromType (void* self, void* type)
{
  rb_funcall(cNagaqueen, rb_intern("onCoverFromType"), 2, (VALUE)(self), type);
}

void nq_onCoverExtends (void* self, void* type)
{
  rb_funcall(cNagaqueen, rb_intern("onCoverExtends"), 2, (VALUE)(self), type);
}

void nq_onCoverImplements (void* self, void* type)
{
  rb_funcall(cNagaqueen, rb_intern("onCoverImplements"), 2, (VALUE)(self), type);
}

void nq_onCoverEnd (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onCoverEnd"), 1, (VALUE)(self));
}

void nq_onEnumStart (void* self, char* name, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onEnumStart"), 3, (VALUE)(self), rb_str_new2(name), rb_str_new2(doc));
}

void nq_onEnumExtern (void* self, char* externName)
{
  rb_funcall(cNagaqueen, rb_intern("onEnumExtern"), 2, (VALUE)(self), rb_str_new2(externName));
}

void nq_onEnumFromType (void* self, void* fromType)
{
  rb_funcall(cNagaqueen, rb_intern("onEnumFromType"), 2, (VALUE)(self), fromType);
}

void nq_onEnumIncrementExpr (void* self, char oper, void* step)
{
  rb_funcall(cNagaqueen, rb_intern("onEnumIncrementExpr"), 3, (VALUE)(self), oper, step);
}

void nq_onEnumElementStart (void* self, char* name, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onEnumElementStart"), 3, (VALUE)(self), rb_str_new2(name), rb_str_new2(doc));
}

void nq_onEnumElementValue (void* self, void* value)
{
  rb_funcall(cNagaqueen, rb_intern("onEnumElementValue"), 2, (VALUE)(self), value);
}

void nq_onEnumElementExtern (void* self, char* externName)
{
  rb_funcall(cNagaqueen, rb_intern("onEnumElementExtern"), 2, (VALUE)(self), rb_str_new2(externName));
}

void nq_onEnumElementEnd (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onEnumElementEnd"), 1, (VALUE)(self));
}

void nq_onEnumEnd (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onEnumEnd"), 1, (VALUE)(self));
}

void nq_onClassStart (void* self, char* name, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onClassStart"), 3, (VALUE)(self), rb_str_new2(name), rb_str_new2(doc));
}

void nq_onClassAbstract (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onClassAbstract"), 1, (VALUE)(self));
}

void nq_onClassFinal (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onClassFinal"), 1, (VALUE)(self));
}

void nq_onClassExtends (void* self, void* type)
{
  rb_funcall(cNagaqueen, rb_intern("onClassExtends"), 2, (VALUE)(self), type);
}

void nq_onClassImplements (void* self, void* type)
{
  rb_funcall(cNagaqueen, rb_intern("onClassImplements"), 2, (VALUE)(self), type);
}

void nq_onClassBody (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onClassBody"), 1, (VALUE)(self));
}

void nq_onClassEnd (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onClassEnd"), 1, (VALUE)(self));
}

void nq_onInterfaceStart (void* self, char* name, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onInterfaceStart"), 3, (VALUE)(self), rb_str_new2(name), rb_str_new2(doc));
}

void nq_onInterfaceExtends (void* self, void* type)
{
  rb_funcall(cNagaqueen, rb_intern("onInterfaceExtends"), 2, (VALUE)(self), type);
}

void nq_onInterfaceEnd (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onInterfaceEnd"), 1, (VALUE)(self));
}

void nq_onPropertyDeclStart (void* self, char* name, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onPropertyDeclStart"), 3, (VALUE)(self), rb_str_new2(name), rb_str_new2(doc));
}

void nq_onPropertyDeclStatic (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onPropertyDeclStatic"), 1, (VALUE)(self));
}

void nq_onPropertyDeclType (void* self, void* type)
{
  rb_funcall(cNagaqueen, rb_intern("onPropertyDeclType"), 2, (VALUE)(self), type);
}

void * nq_onPropertyDeclEnd (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onPropertyDeclEnd"), 1, (VALUE)(self));
}

void nq_onPropertyDeclGetterStart (void* self, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onPropertyDeclGetterStart"), 2, (VALUE)(self), rb_str_new2(doc));
}

void * nq_onPropertyDeclGetterEnd (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onPropertyDeclGetterEnd"), 1, (VALUE)(self));
}

void nq_onPropertyDeclSetterStart (void* self, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onPropertyDeclSetterStart"), 2, (VALUE)(self), rb_str_new2(doc));
}

void nq_onPropertyDeclSetterArgument (void* self, char* name, _Bool conventional)
{
  rb_funcall(cNagaqueen, rb_intern("onPropertyDeclSetterArgument"), 3, (VALUE)(self), rb_str_new2(name), conventional);
}

void * nq_onPropertyDeclSetterEnd (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onPropertyDeclSetterEnd"), 1, (VALUE)(self));
}

void nq_onVarDeclStart (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclStart"), 1, (VALUE)(self));
}

void nq_onVarDeclName (void* self, char* name, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclName"), 3, (VALUE)(self), rb_str_new2(name), rb_str_new2(doc));
}

void nq_onVarDeclTuple (void* self, void* tuple)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclTuple"), 2, (VALUE)(self), tuple);
}

void nq_onVarDeclExtern (void* self, char* externName)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclExtern"), 2, (VALUE)(self), rb_str_new2(externName));
}

void nq_onVarDeclUnmangled (void* self, char* unmangledName)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclUnmangled"), 2, (VALUE)(self), rb_str_new2(unmangledName));
}

void nq_onVarDeclExpr (void* self, void* expr)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclExpr"), 2, (VALUE)(self), expr);
}

void nq_onVarDeclType (void* self, void* type)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclType"), 2, (VALUE)(self), type);
}

void nq_onVarDeclStatic (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclStatic"), 1, (VALUE)(self));
}

void nq_onVarDeclConst (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclConst"), 1, (VALUE)(self));
}

void nq_onVarDeclProto (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclProto"), 1, (VALUE)(self));
}

void * nq_onVarDeclEnd (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onVarDeclEnd"), 1, (VALUE)(self));
}

void * nq_onTypeAccess (void* self, void* type)
{
  rb_funcall(cNagaqueen, rb_intern("onTypeAccess"), 2, (VALUE)(self), type);
}

void * nq_onTypeNew (void* self, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onTypeNew"), 2, (VALUE)(self), rb_str_new2(name));
}

void * nq_onTypePointer (void* self, void* type)
{
  rb_funcall(cNagaqueen, rb_intern("onTypePointer"), 2, (VALUE)(self), type);
}

void * nq_onTypeReference (void* self, void* type)
{
  rb_funcall(cNagaqueen, rb_intern("onTypeReference"), 2, (VALUE)(self), type);
}

void * nq_onTypeBrackets (void* self, void* type, void* inner)
{
  rb_funcall(cNagaqueen, rb_intern("onTypeBrackets"), 3, (VALUE)(self), type, inner);
}

void nq_onTypeGenericArgument (void* self, void* type, void* genType)
{
  rb_funcall(cNagaqueen, rb_intern("onTypeGenericArgument"), 3, (VALUE)(self), type, genType);
}

void nq_onFuncTypeGenericArgument (void* self, void* type, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onFuncTypeGenericArgument"), 3, (VALUE)(self), type, rb_str_new2(name));
}

void * nq_onTypeList (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onTypeList"), 1, (VALUE)(self));
}

void * nq_onTypeListElement (void* self, void* list, void* elem)
{
  rb_funcall(cNagaqueen, rb_intern("onTypeListElement"), 3, (VALUE)(self), list, elem);
}

void nq_onTypeNamespace (void* self, void* type, void* ident)
{
  rb_funcall(cNagaqueen, rb_intern("onTypeNamespace"), 3, (VALUE)(self), type, ident);
}

void * nq_onFuncTypeNew (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onFuncTypeNew"), 1, (VALUE)(self));
}

void nq_onFuncTypeArgument (void* self, void* funcType, void* argType)
{
  rb_funcall(cNagaqueen, rb_intern("onFuncTypeArgument"), 3, (VALUE)(self), funcType, argType);
}

void nq_onFuncTypeVarArg (void* self, void* funcType)
{
  rb_funcall(cNagaqueen, rb_intern("onFuncTypeVarArg"), 2, (VALUE)(self), funcType);
}

void nq_onFuncTypeReturnType (void* self, void* funcType, void* returnType)
{
  rb_funcall(cNagaqueen, rb_intern("onFuncTypeReturnType"), 3, (VALUE)(self), funcType, returnType);
}

void nq_onOperatorStart (void* self, char* symbol)
{
  rb_funcall(cNagaqueen, rb_intern("onOperatorStart"), 2, (VALUE)(self), rb_str_new2(symbol));
}

void nq_onOperatorEnd (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onOperatorEnd"), 1, (VALUE)(self));
}

void nq_onFunctionStart (void* self, char* name, char* doc)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionStart"), 3, (VALUE)(self), rb_str_new2(name), rb_str_new2(doc));
}

void nq_onFunctionExtern (void* self, char* externName)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionExtern"), 2, (VALUE)(self), rb_str_new2(externName));
}

void nq_onFunctionUnmangled (void* self, char* unmangledName)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionUnmangled"), 2, (VALUE)(self), rb_str_new2(unmangledName));
}

void nq_onFunctionAbstract (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionAbstract"), 1, (VALUE)(self));
}

void nq_onFunctionThisRef (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionThisRef"), 1, (VALUE)(self));
}

void nq_onFunctionArgsStart (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionArgsStart"), 1, (VALUE)(self));
}

void nq_onFunctionArgsEnd (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionArgsEnd"), 1, (VALUE)(self));
}

void nq_onFunctionReturnType (void* self, void* type)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionReturnType"), 2, (VALUE)(self), type);
}

void nq_onFunctionConst (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionConst"), 1, (VALUE)(self));
}

void nq_onFunctionStatic (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionStatic"), 1, (VALUE)(self));
}

void nq_onFunctionInline (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionInline"), 1, (VALUE)(self));
}

void nq_onFunctionFinal (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionFinal"), 1, (VALUE)(self));
}

void nq_onFunctionProto (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionProto"), 1, (VALUE)(self));
}

void nq_onFunctionSuper (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionSuper"), 1, (VALUE)(self));
}

void nq_onFunctionSuffix (void* self, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionSuffix"), 2, (VALUE)(self), rb_str_new2(name));
}

void nq_onFunctionBody (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionBody"), 1, (VALUE)(self));
}

void * nq_onFunctionEnd (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionEnd"), 1, (VALUE)(self));
}

void nq_onTypeArg (void* self, void* type)
{
  rb_funcall(cNagaqueen, rb_intern("onTypeArg"), 2, (VALUE)(self), type);
}

void nq_onVarArg (void* self, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onVarArg"), 2, (VALUE)(self), rb_str_new2(name));
}

void nq_onDotArg (void* self, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onDotArg"), 2, (VALUE)(self), rb_str_new2(name));
}

void nq_onAssArg (void* self, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onAssArg"), 2, (VALUE)(self), rb_str_new2(name));
}

void nq_onFunctionCallStart (void* self, char* yytext)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionCallStart"), 2, (VALUE)(self), rb_str_new2(yytext));
}

void nq_onFunctionCallSuffix (void* self, char* yytext)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionCallSuffix"), 2, (VALUE)(self), rb_str_new2(yytext));
}

void nq_onFunctionCallArg (void* self, void* expr)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionCallArg"), 2, (VALUE)(self), expr);
}

void * nq_onFunctionCallEnd (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionCallEnd"), 1, (VALUE)(self));
}

void nq_onFunctionCallExpr (void* self, void* call, void* expr)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionCallExpr"), 3, (VALUE)(self), call, expr);
}

void * nq_onFunctionCallChain (void* self, void* expr, void* call)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionCallChain"), 3, (VALUE)(self), expr, call);
}

void nq_onFunctionCallCombo (void* self, void* call, void* expr)
{
  rb_funcall(cNagaqueen, rb_intern("onFunctionCallCombo"), 3, (VALUE)(self), call, expr);
}

void nq_onArrayLiteralStart (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onArrayLiteralStart"), 1, (VALUE)(self));
}

void * nq_onArrayLiteralEnd (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onArrayLiteralEnd"), 1, (VALUE)(self));
}

void nq_onTupleStart (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onTupleStart"), 1, (VALUE)(self));
}

void * nq_onTupleEnd (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onTupleEnd"), 1, (VALUE)(self));
}

void * nq_onStringLiteral (void* self, char* text)
{
  rb_funcall(cNagaqueen, rb_intern("onStringLiteral"), 2, (VALUE)(self), rb_str_new2(text));
}

void * nq_onCharLiteral (void* self, char* value)
{
  rb_funcall(cNagaqueen, rb_intern("onCharLiteral"), 2, (VALUE)(self), rb_str_new2(value));
}

void nq_onStatement (void* self, void* statement)
{
  rb_funcall(cNagaqueen, rb_intern("onStatement"), 2, (VALUE)(self), statement);
}

void * nq_onReturn (void* self, void* expr)
{
  rb_funcall(cNagaqueen, rb_intern("onReturn"), 2, (VALUE)(self), expr);
}

void * nq_onVarAccess (void* self, void* expr, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onVarAccess"), 3, (VALUE)(self), expr, rb_str_new2(name));
}

void nq_onArrayAccessStart (void* self, void* array)
{
  rb_funcall(cNagaqueen, rb_intern("onArrayAccessStart"), 2, (VALUE)(self), array);
}

void * nq_onArrayAccessEnd (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onArrayAccessEnd"), 1, (VALUE)(self));
}

void * nq_onCast (void* self, void* expr, void* type)
{
  rb_funcall(cNagaqueen, rb_intern("onCast"), 3, (VALUE)(self), expr, type);
}

void * nq_onBreak (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onBreak"), 1, (VALUE)(self));
}

void * nq_onContinue (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onContinue"), 1, (VALUE)(self));
}

void nq_onBlockStart (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onBlockStart"), 1, (VALUE)(self));
}

void * nq_onBlockEnd (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onBlockEnd"), 1, (VALUE)(self));
}

void nq_onIfStart (void* self, void* condition)
{
  rb_funcall(cNagaqueen, rb_intern("onIfStart"), 2, (VALUE)(self), condition);
}

void * nq_onIfEnd (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onIfEnd"), 1, (VALUE)(self));
}

void nq_onElseStart (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onElseStart"), 1, (VALUE)(self));
}

void * nq_onElseEnd (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onElseEnd"), 1, (VALUE)(self));
}

void nq_onForeachStart (void* self, void* decl, void* collec)
{
  rb_funcall(cNagaqueen, rb_intern("onForeachStart"), 3, (VALUE)(self), decl, collec);
}

void * nq_onForeachEnd (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onForeachEnd"), 1, (VALUE)(self));
}

void nq_onWhileStart (void* self, void* condition)
{
  rb_funcall(cNagaqueen, rb_intern("onWhileStart"), 2, (VALUE)(self), condition);
}

void * nq_onWhileEnd (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onWhileEnd"), 1, (VALUE)(self));
}

void * nq_onEquals (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onEquals"), 3, (VALUE)(self), left, right);
}

void * nq_onNotEquals (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onNotEquals"), 3, (VALUE)(self), left, right);
}

void * nq_onLessThan (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onLessThan"), 3, (VALUE)(self), left, right);
}

void * nq_onMoreThan (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onMoreThan"), 3, (VALUE)(self), left, right);
}

void * nq_onCmp (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onCmp"), 3, (VALUE)(self), left, right);
}

void * nq_onLessThanOrEqual (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onLessThanOrEqual"), 3, (VALUE)(self), left, right);
}

void * nq_onMoreThanOrEqual (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onMoreThanOrEqual"), 3, (VALUE)(self), left, right);
}

void * nq_onDecLiteral (void* self, char* value)
{
  rb_funcall(cNagaqueen, rb_intern("onDecLiteral"), 2, (VALUE)(self), rb_str_new2(value));
}

void * nq_onBinLiteral (void* self, char* value)
{
  rb_funcall(cNagaqueen, rb_intern("onBinLiteral"), 2, (VALUE)(self), rb_str_new2(value));
}

void * nq_onOctLiteral (void* self, char* value)
{
  rb_funcall(cNagaqueen, rb_intern("onOctLiteral"), 2, (VALUE)(self), rb_str_new2(value));
}

void * nq_onHexLiteral (void* self, char* value)
{
  rb_funcall(cNagaqueen, rb_intern("onHexLiteral"), 2, (VALUE)(self), rb_str_new2(value));
}

void * nq_onFloatLiteral (void* self, char* value)
{
  rb_funcall(cNagaqueen, rb_intern("onFloatLiteral"), 2, (VALUE)(self), rb_str_new2(value));
}

void * nq_onBoolLiteral (void* self, bool value)
{
  rb_funcall(cNagaqueen, rb_intern("onBoolLiteral"), 2, (VALUE)(self), value);
}

void * nq_onNull (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onNull"), 1, (VALUE)(self));
}

void * nq_onDoubleArrow (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onDoubleArrow"), 3, (VALUE)(self), left, right);
}

void * nq_onTernary (void* self, void* condition, void* ifTrue, void* ifFalse)
{
  rb_funcall(cNagaqueen, rb_intern("onTernary"), 4, (VALUE)(self), condition, ifTrue, ifFalse);
}

void * nq_onAssignAnd (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignAnd"), 3, (VALUE)(self), left, right);
}

void * nq_onAssignOr (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignOr"), 3, (VALUE)(self), left, right);
}

void * nq_onAssignXor (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignXor"), 3, (VALUE)(self), left, right);
}

void * nq_onAssignRightShift (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignRightShift"), 3, (VALUE)(self), left, right);
}

void * nq_onAssignLeftShift (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignLeftShift"), 3, (VALUE)(self), left, right);
}

void * nq_onAssignDiv (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignDiv"), 3, (VALUE)(self), left, right);
}

void * nq_onAssignMul (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignMul"), 3, (VALUE)(self), left, right);
}

void * nq_onAssignExp (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignExp"), 3, (VALUE)(self), left, right);
}

void * nq_onAssignSub (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignSub"), 3, (VALUE)(self), left, right);
}

void * nq_onAssignAdd (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssignAdd"), 3, (VALUE)(self), left, right);
}

void * nq_onAssign (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onAssign"), 3, (VALUE)(self), left, right);
}

void * nq_onAdd (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onAdd"), 3, (VALUE)(self), left, right);
}

void * nq_onSub (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onSub"), 3, (VALUE)(self), left, right);
}

void * nq_onMod (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onMod"), 3, (VALUE)(self), left, right);
}

void * nq_onMul (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onMul"), 3, (VALUE)(self), left, right);
}

void * nq_onExp (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onExp"), 3, (VALUE)(self), left, right);
}

void * nq_onDiv (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onDiv"), 3, (VALUE)(self), left, right);
}

void * nq_onRangeLiteral (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onRangeLiteral"), 3, (VALUE)(self), left, right);
}

void * nq_onBinaryLeftShift (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onBinaryLeftShift"), 3, (VALUE)(self), left, right);
}

void * nq_onBinaryRightShift (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onBinaryRightShift"), 3, (VALUE)(self), left, right);
}

void * nq_onLogicalOr (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onLogicalOr"), 3, (VALUE)(self), left, right);
}

void * nq_onLogicalAnd (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onLogicalAnd"), 3, (VALUE)(self), left, right);
}

void * nq_onBinaryOr (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onBinaryOr"), 3, (VALUE)(self), left, right);
}

void * nq_onBinaryXor (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onBinaryXor"), 3, (VALUE)(self), left, right);
}

void * nq_onBinaryAnd (void* self, void* left, void* right)
{
  rb_funcall(cNagaqueen, rb_intern("onBinaryAnd"), 3, (VALUE)(self), left, right);
}

void * nq_onLogicalNot (void* self, void* inner)
{
  rb_funcall(cNagaqueen, rb_intern("onLogicalNot"), 2, (VALUE)(self), inner);
}

void * nq_onBinaryNot (void* self, void* inner)
{
  rb_funcall(cNagaqueen, rb_intern("onBinaryNot"), 2, (VALUE)(self), inner);
}

void * nq_onUnaryMinus (void* self, void* inner)
{
  rb_funcall(cNagaqueen, rb_intern("onUnaryMinus"), 2, (VALUE)(self), inner);
}

void * nq_onParenthesis (void* self, void* inner)
{
  rb_funcall(cNagaqueen, rb_intern("onParenthesis"), 2, (VALUE)(self), inner);
}

void nq_onGenericArgument (void* self, char* name)
{
  rb_funcall(cNagaqueen, rb_intern("onGenericArgument"), 2, (VALUE)(self), rb_str_new2(name));
}

void * nq_onAddressOf (void* self, void* inner)
{
  rb_funcall(cNagaqueen, rb_intern("onAddressOf"), 2, (VALUE)(self), inner);
}

void * nq_onDereference (void* self, void* inner)
{
  rb_funcall(cNagaqueen, rb_intern("onDereference"), 2, (VALUE)(self), inner);
}

void nq_onMatchStart (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onMatchStart"), 1, (VALUE)(self));
}

void nq_onMatchExpr (void* self, void* value)
{
  rb_funcall(cNagaqueen, rb_intern("onMatchExpr"), 2, (VALUE)(self), value);
}

void * nq_onMatchEnd (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onMatchEnd"), 1, (VALUE)(self));
}

void nq_onCaseStart (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onCaseStart"), 1, (VALUE)(self));
}

void nq_onCaseExpr (void* self, void* value)
{
  rb_funcall(cNagaqueen, rb_intern("onCaseExpr"), 2, (VALUE)(self), value);
}

void nq_onCaseEnd (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onCaseEnd"), 1, (VALUE)(self));
}

void nq_onTryStart (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onTryStart"), 1, (VALUE)(self));
}

void * nq_onTryEnd (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onTryEnd"), 1, (VALUE)(self));
}

void nq_onCatchStart (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onCatchStart"), 1, (VALUE)(self));
}

void nq_onCatchExpr (void* self, void* value)
{
  rb_funcall(cNagaqueen, rb_intern("onCatchExpr"), 2, (VALUE)(self), value);
}

void nq_onCatchEnd (void* self)
{
  rb_funcall(cNagaqueen, rb_intern("onCatchEnd"), 1, (VALUE)(self));
}

void nq_error (void* self, int errorID, char* defaultMessage, int index)
{
  rb_funcall(cNagaqueen, rb_intern("error"), 4, (VALUE)(self), INT2NUM(errorID), rb_str_new2(defaultMessage), INT2NUM(index));
}

