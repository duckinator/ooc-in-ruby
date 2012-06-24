void nq_setTokenPositionPointer (void* self, int* tokenPosPointer)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("setTokenPositionPointer"))) {
    rb_funcall((VALUE)(self), rb_intern("setTokenPositionPointer"), 2, (VALUE)(self), INT2NUM(*tokenPosPointer));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `setTokenPositionPointer' for ", STR2CSTR(tmp));
  }
}

char * nq_StringClone (char* string)
{
  if(rb_funcall(cNagaqueen, rb_intern("respond_to?"), 1, rb_str_new2("StringClone"))) {
    rb_funcall(cNagaqueen, rb_intern("StringClone"), 1, rb_str_new2(string));
  } else {
    VALUE tmp = rb_funcall(cNagaqueen, rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `StringClone' for ", STR2CSTR("cNagaqueen:Class"));
  }
}

char * nq_trailingQuest (char* string)
{
  if(rb_funcall(cNagaqueen, rb_intern("respond_to?"), 1, rb_str_new2("trailingQuest"))) {
    rb_funcall(cNagaqueen, rb_intern("trailingQuest"), 1, rb_str_new2(string));
  } else {
    VALUE tmp = rb_funcall(cNagaqueen, rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `trailingQuest' for ", STR2CSTR("cNagaqueen:Class"));
  }
}

char * nq_trailingBang (char* string)
{
  if(rb_funcall(cNagaqueen, rb_intern("respond_to?"), 1, rb_str_new2("trailingBang"))) {
    rb_funcall(cNagaqueen, rb_intern("trailingBang"), 1, rb_str_new2(string));
  } else {
    VALUE tmp = rb_funcall(cNagaqueen, rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `trailingBang' for ", STR2CSTR("cNagaqueen:Class"));
  }
}

void nq_onUse (void* self, char* name)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onUse"))) {
    rb_funcall((VALUE)(self), rb_intern("onUse"), 2, (VALUE)(self), rb_str_new2(name));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onUse' for ", STR2CSTR(tmp));
  }
}

void nq_onInclude (void* self, char* path)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onInclude"))) {
    rb_funcall((VALUE)(self), rb_intern("onInclude"), 2, (VALUE)(self), rb_str_new2(path));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onInclude' for ", STR2CSTR(tmp));
  }
}

void nq_onIncludeDefine (void* self, char* name, char* value)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onIncludeDefine"))) {
    rb_funcall((VALUE)(self), rb_intern("onIncludeDefine"), 3, (VALUE)(self), rb_str_new2(name), rb_str_new2(value));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onIncludeDefine' for ", STR2CSTR(tmp));
  }
}

void nq_onImport (void* self, char* path, char* name)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onImport"))) {
    rb_funcall((VALUE)(self), rb_intern("onImport"), 3, (VALUE)(self), rb_str_new2(path), rb_str_new2(name));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onImport' for ", STR2CSTR(tmp));
  }
}

void nq_onImportNamespace (void* self, char* namespace, int quantity)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onImportNamespace"))) {
    rb_funcall((VALUE)(self), rb_intern("onImportNamespace"), 3, (VALUE)(self), rb_str_new2(namespace), INT2NUM(quantity));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onImportNamespace' for ", STR2CSTR(tmp));
  }
}

void * nq_onVersionName (void* self, char* name)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onVersionName"))) {
    rb_funcall((VALUE)(self), rb_intern("onVersionName"), 2, (VALUE)(self), rb_str_new2(name));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onVersionName' for ", STR2CSTR(tmp));
  }
}

void * nq_onVersionNegation (void* self, void* spec)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onVersionNegation"))) {
    rb_funcall((VALUE)(self), rb_intern("onVersionNegation"), 2, (VALUE)(self), spec);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onVersionNegation' for ", STR2CSTR(tmp));
  }
}

void * nq_onVersionAnd (void* self, void* specLeft, void* specRight)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onVersionAnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onVersionAnd"), 3, (VALUE)(self), specLeft, specRight);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onVersionAnd' for ", STR2CSTR(tmp));
  }
}

void * nq_onVersionOr (void* self, void* specLeft, void* specRight)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onVersionOr"))) {
    rb_funcall((VALUE)(self), rb_intern("onVersionOr"), 3, (VALUE)(self), specLeft, specRight);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onVersionOr' for ", STR2CSTR(tmp));
  }
}

void nq_onVersionStart (void* self, void* spec)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onVersionStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onVersionStart"), 2, (VALUE)(self), spec);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onVersionStart' for ", STR2CSTR(tmp));
  }
}

void * nq_onVersionElseIfStart (void* self, void* notSpec, void* elseSpec)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onVersionElseIfStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onVersionElseIfStart"), 3, (VALUE)(self), notSpec, elseSpec);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onVersionElseIfStart' for ", STR2CSTR(tmp));
  }
}

void nq_onVersionElseStart (void* self, void* notSpec)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onVersionElseStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onVersionElseStart"), 2, (VALUE)(self), notSpec);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onVersionElseStart' for ", STR2CSTR(tmp));
  }
}

void * nq_onVersionEnd (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onVersionEnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onVersionEnd"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onVersionEnd' for ", STR2CSTR(tmp));
  }
}

void nq_onExtendStart (void* self, void* type, char* doc)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onExtendStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onExtendStart"), 3, (VALUE)(self), type, rb_str_new2(doc));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onExtendStart' for ", STR2CSTR(tmp));
  }
}

void nq_onExtendEnd (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onExtendEnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onExtendEnd"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onExtendEnd' for ", STR2CSTR(tmp));
  }
}

void nq_onCoverStart (void* self, char* name, char* doc)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onCoverStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onCoverStart"), 3, (VALUE)(self), rb_str_new2(name), rb_str_new2(doc));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onCoverStart' for ", STR2CSTR(tmp));
  }
}

void nq_onCoverExtern (void* self, char* externName)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onCoverExtern"))) {
    rb_funcall((VALUE)(self), rb_intern("onCoverExtern"), 2, (VALUE)(self), rb_str_new2(externName));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onCoverExtern' for ", STR2CSTR(tmp));
  }
}

void nq_onCoverFromType (void* self, void* type)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onCoverFromType"))) {
    rb_funcall((VALUE)(self), rb_intern("onCoverFromType"), 2, (VALUE)(self), type);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onCoverFromType' for ", STR2CSTR(tmp));
  }
}

void nq_onCoverExtends (void* self, void* type)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onCoverExtends"))) {
    rb_funcall((VALUE)(self), rb_intern("onCoverExtends"), 2, (VALUE)(self), type);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onCoverExtends' for ", STR2CSTR(tmp));
  }
}

void nq_onCoverImplements (void* self, void* type)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onCoverImplements"))) {
    rb_funcall((VALUE)(self), rb_intern("onCoverImplements"), 2, (VALUE)(self), type);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onCoverImplements' for ", STR2CSTR(tmp));
  }
}

void nq_onCoverEnd (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onCoverEnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onCoverEnd"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onCoverEnd' for ", STR2CSTR(tmp));
  }
}

void nq_onEnumStart (void* self, char* name, char* doc)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onEnumStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onEnumStart"), 3, (VALUE)(self), rb_str_new2(name), rb_str_new2(doc));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onEnumStart' for ", STR2CSTR(tmp));
  }
}

void nq_onEnumExtern (void* self, char* externName)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onEnumExtern"))) {
    rb_funcall((VALUE)(self), rb_intern("onEnumExtern"), 2, (VALUE)(self), rb_str_new2(externName));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onEnumExtern' for ", STR2CSTR(tmp));
  }
}

void nq_onEnumFromType (void* self, void* fromType)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onEnumFromType"))) {
    rb_funcall((VALUE)(self), rb_intern("onEnumFromType"), 2, (VALUE)(self), fromType);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onEnumFromType' for ", STR2CSTR(tmp));
  }
}

void nq_onEnumIncrementExpr (void* self, char oper, void* step)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onEnumIncrementExpr"))) {
    rb_funcall((VALUE)(self), rb_intern("onEnumIncrementExpr"), 3, (VALUE)(self), oper, step);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onEnumIncrementExpr' for ", STR2CSTR(tmp));
  }
}

void nq_onEnumElementStart (void* self, char* name, char* doc)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onEnumElementStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onEnumElementStart"), 3, (VALUE)(self), rb_str_new2(name), rb_str_new2(doc));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onEnumElementStart' for ", STR2CSTR(tmp));
  }
}

void nq_onEnumElementValue (void* self, void* value)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onEnumElementValue"))) {
    rb_funcall((VALUE)(self), rb_intern("onEnumElementValue"), 2, (VALUE)(self), value);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onEnumElementValue' for ", STR2CSTR(tmp));
  }
}

void nq_onEnumElementExtern (void* self, char* externName)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onEnumElementExtern"))) {
    rb_funcall((VALUE)(self), rb_intern("onEnumElementExtern"), 2, (VALUE)(self), rb_str_new2(externName));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onEnumElementExtern' for ", STR2CSTR(tmp));
  }
}

void nq_onEnumElementEnd (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onEnumElementEnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onEnumElementEnd"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onEnumElementEnd' for ", STR2CSTR(tmp));
  }
}

void nq_onEnumEnd (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onEnumEnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onEnumEnd"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onEnumEnd' for ", STR2CSTR(tmp));
  }
}

void nq_onClassStart (void* self, char* name, char* doc)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onClassStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onClassStart"), 3, (VALUE)(self), rb_str_new2(name), rb_str_new2(doc));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onClassStart' for ", STR2CSTR(tmp));
  }
}

void nq_onClassAbstract (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onClassAbstract"))) {
    rb_funcall((VALUE)(self), rb_intern("onClassAbstract"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onClassAbstract' for ", STR2CSTR(tmp));
  }
}

void nq_onClassFinal (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onClassFinal"))) {
    rb_funcall((VALUE)(self), rb_intern("onClassFinal"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onClassFinal' for ", STR2CSTR(tmp));
  }
}

void nq_onClassExtends (void* self, void* type)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onClassExtends"))) {
    rb_funcall((VALUE)(self), rb_intern("onClassExtends"), 2, (VALUE)(self), type);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onClassExtends' for ", STR2CSTR(tmp));
  }
}

void nq_onClassImplements (void* self, void* type)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onClassImplements"))) {
    rb_funcall((VALUE)(self), rb_intern("onClassImplements"), 2, (VALUE)(self), type);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onClassImplements' for ", STR2CSTR(tmp));
  }
}

void nq_onClassBody (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onClassBody"))) {
    rb_funcall((VALUE)(self), rb_intern("onClassBody"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onClassBody' for ", STR2CSTR(tmp));
  }
}

void nq_onClassEnd (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onClassEnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onClassEnd"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onClassEnd' for ", STR2CSTR(tmp));
  }
}

void nq_onInterfaceStart (void* self, char* name, char* doc)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onInterfaceStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onInterfaceStart"), 3, (VALUE)(self), rb_str_new2(name), rb_str_new2(doc));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onInterfaceStart' for ", STR2CSTR(tmp));
  }
}

void nq_onInterfaceExtends (void* self, void* type)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onInterfaceExtends"))) {
    rb_funcall((VALUE)(self), rb_intern("onInterfaceExtends"), 2, (VALUE)(self), type);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onInterfaceExtends' for ", STR2CSTR(tmp));
  }
}

void nq_onInterfaceEnd (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onInterfaceEnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onInterfaceEnd"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onInterfaceEnd' for ", STR2CSTR(tmp));
  }
}

void nq_onPropertyDeclStart (void* self, char* name, char* doc)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onPropertyDeclStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onPropertyDeclStart"), 3, (VALUE)(self), rb_str_new2(name), rb_str_new2(doc));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onPropertyDeclStart' for ", STR2CSTR(tmp));
  }
}

void nq_onPropertyDeclStatic (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onPropertyDeclStatic"))) {
    rb_funcall((VALUE)(self), rb_intern("onPropertyDeclStatic"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onPropertyDeclStatic' for ", STR2CSTR(tmp));
  }
}

void nq_onPropertyDeclType (void* self, void* type)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onPropertyDeclType"))) {
    rb_funcall((VALUE)(self), rb_intern("onPropertyDeclType"), 2, (VALUE)(self), type);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onPropertyDeclType' for ", STR2CSTR(tmp));
  }
}

void * nq_onPropertyDeclEnd (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onPropertyDeclEnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onPropertyDeclEnd"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onPropertyDeclEnd' for ", STR2CSTR(tmp));
  }
}

void nq_onPropertyDeclGetterStart (void* self, char* doc)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onPropertyDeclGetterStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onPropertyDeclGetterStart"), 2, (VALUE)(self), rb_str_new2(doc));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onPropertyDeclGetterStart' for ", STR2CSTR(tmp));
  }
}

void * nq_onPropertyDeclGetterEnd (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onPropertyDeclGetterEnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onPropertyDeclGetterEnd"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onPropertyDeclGetterEnd' for ", STR2CSTR(tmp));
  }
}

void nq_onPropertyDeclSetterStart (void* self, char* doc)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onPropertyDeclSetterStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onPropertyDeclSetterStart"), 2, (VALUE)(self), rb_str_new2(doc));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onPropertyDeclSetterStart' for ", STR2CSTR(tmp));
  }
}

void nq_onPropertyDeclSetterArgument (void* self, char* name, _Bool conventional)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onPropertyDeclSetterArgument"))) {
    rb_funcall((VALUE)(self), rb_intern("onPropertyDeclSetterArgument"), 3, (VALUE)(self), rb_str_new2(name), conventional);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onPropertyDeclSetterArgument' for ", STR2CSTR(tmp));
  }
}

void * nq_onPropertyDeclSetterEnd (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onPropertyDeclSetterEnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onPropertyDeclSetterEnd"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onPropertyDeclSetterEnd' for ", STR2CSTR(tmp));
  }
}

void nq_onVarDeclStart (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onVarDeclStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onVarDeclStart"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onVarDeclStart' for ", STR2CSTR(tmp));
  }
}

void nq_onVarDeclName (void* self, char* name, char* doc)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onVarDeclName"))) {
    rb_funcall((VALUE)(self), rb_intern("onVarDeclName"), 3, (VALUE)(self), rb_str_new2(name), rb_str_new2(doc));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onVarDeclName' for ", STR2CSTR(tmp));
  }
}

void nq_onVarDeclTuple (void* self, void* tuple)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onVarDeclTuple"))) {
    rb_funcall((VALUE)(self), rb_intern("onVarDeclTuple"), 2, (VALUE)(self), tuple);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onVarDeclTuple' for ", STR2CSTR(tmp));
  }
}

void nq_onVarDeclExtern (void* self, char* externName)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onVarDeclExtern"))) {
    rb_funcall((VALUE)(self), rb_intern("onVarDeclExtern"), 2, (VALUE)(self), rb_str_new2(externName));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onVarDeclExtern' for ", STR2CSTR(tmp));
  }
}

void nq_onVarDeclUnmangled (void* self, char* unmangledName)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onVarDeclUnmangled"))) {
    rb_funcall((VALUE)(self), rb_intern("onVarDeclUnmangled"), 2, (VALUE)(self), rb_str_new2(unmangledName));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onVarDeclUnmangled' for ", STR2CSTR(tmp));
  }
}

void nq_onVarDeclExpr (void* self, void* expr)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onVarDeclExpr"))) {
    rb_funcall((VALUE)(self), rb_intern("onVarDeclExpr"), 2, (VALUE)(self), expr);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onVarDeclExpr' for ", STR2CSTR(tmp));
  }
}

void nq_onVarDeclType (void* self, void* type)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onVarDeclType"))) {
    rb_funcall((VALUE)(self), rb_intern("onVarDeclType"), 2, (VALUE)(self), type);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onVarDeclType' for ", STR2CSTR(tmp));
  }
}

void nq_onVarDeclStatic (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onVarDeclStatic"))) {
    rb_funcall((VALUE)(self), rb_intern("onVarDeclStatic"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onVarDeclStatic' for ", STR2CSTR(tmp));
  }
}

void nq_onVarDeclConst (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onVarDeclConst"))) {
    rb_funcall((VALUE)(self), rb_intern("onVarDeclConst"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onVarDeclConst' for ", STR2CSTR(tmp));
  }
}

void nq_onVarDeclProto (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onVarDeclProto"))) {
    rb_funcall((VALUE)(self), rb_intern("onVarDeclProto"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onVarDeclProto' for ", STR2CSTR(tmp));
  }
}

void * nq_onVarDeclEnd (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onVarDeclEnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onVarDeclEnd"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onVarDeclEnd' for ", STR2CSTR(tmp));
  }
}

void * nq_onTypeAccess (void* self, void* type)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onTypeAccess"))) {
    rb_funcall((VALUE)(self), rb_intern("onTypeAccess"), 2, (VALUE)(self), type);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onTypeAccess' for ", STR2CSTR(tmp));
  }
}

void * nq_onTypeNew (void* self, char* name)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onTypeNew"))) {
    rb_funcall((VALUE)(self), rb_intern("onTypeNew"), 2, (VALUE)(self), rb_str_new2(name));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onTypeNew' for ", STR2CSTR(tmp));
  }
}

void * nq_onTypePointer (void* self, void* type)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onTypePointer"))) {
    rb_funcall((VALUE)(self), rb_intern("onTypePointer"), 2, (VALUE)(self), type);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onTypePointer' for ", STR2CSTR(tmp));
  }
}

void * nq_onTypeReference (void* self, void* type)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onTypeReference"))) {
    rb_funcall((VALUE)(self), rb_intern("onTypeReference"), 2, (VALUE)(self), type);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onTypeReference' for ", STR2CSTR(tmp));
  }
}

void * nq_onTypeBrackets (void* self, void* type, void* inner)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onTypeBrackets"))) {
    rb_funcall((VALUE)(self), rb_intern("onTypeBrackets"), 3, (VALUE)(self), type, inner);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onTypeBrackets' for ", STR2CSTR(tmp));
  }
}

void nq_onTypeGenericArgument (void* self, void* type, void* genType)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onTypeGenericArgument"))) {
    rb_funcall((VALUE)(self), rb_intern("onTypeGenericArgument"), 3, (VALUE)(self), type, genType);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onTypeGenericArgument' for ", STR2CSTR(tmp));
  }
}

void nq_onFuncTypeGenericArgument (void* self, void* type, char* name)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFuncTypeGenericArgument"))) {
    rb_funcall((VALUE)(self), rb_intern("onFuncTypeGenericArgument"), 3, (VALUE)(self), type, rb_str_new2(name));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFuncTypeGenericArgument' for ", STR2CSTR(tmp));
  }
}

void * nq_onTypeList (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onTypeList"))) {
    rb_funcall((VALUE)(self), rb_intern("onTypeList"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onTypeList' for ", STR2CSTR(tmp));
  }
}

void * nq_onTypeListElement (void* self, void* list, void* elem)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onTypeListElement"))) {
    rb_funcall((VALUE)(self), rb_intern("onTypeListElement"), 3, (VALUE)(self), list, elem);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onTypeListElement' for ", STR2CSTR(tmp));
  }
}

void nq_onTypeNamespace (void* self, void* type, void* ident)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onTypeNamespace"))) {
    rb_funcall((VALUE)(self), rb_intern("onTypeNamespace"), 3, (VALUE)(self), type, ident);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onTypeNamespace' for ", STR2CSTR(tmp));
  }
}

void * nq_onFuncTypeNew (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFuncTypeNew"))) {
    rb_funcall((VALUE)(self), rb_intern("onFuncTypeNew"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFuncTypeNew' for ", STR2CSTR(tmp));
  }
}

void nq_onFuncTypeArgument (void* self, void* funcType, void* argType)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFuncTypeArgument"))) {
    rb_funcall((VALUE)(self), rb_intern("onFuncTypeArgument"), 3, (VALUE)(self), funcType, argType);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFuncTypeArgument' for ", STR2CSTR(tmp));
  }
}

void nq_onFuncTypeVarArg (void* self, void* funcType)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFuncTypeVarArg"))) {
    rb_funcall((VALUE)(self), rb_intern("onFuncTypeVarArg"), 2, (VALUE)(self), funcType);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFuncTypeVarArg' for ", STR2CSTR(tmp));
  }
}

void nq_onFuncTypeReturnType (void* self, void* funcType, void* returnType)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFuncTypeReturnType"))) {
    rb_funcall((VALUE)(self), rb_intern("onFuncTypeReturnType"), 3, (VALUE)(self), funcType, returnType);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFuncTypeReturnType' for ", STR2CSTR(tmp));
  }
}

void nq_onOperatorStart (void* self, char* symbol)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onOperatorStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onOperatorStart"), 2, (VALUE)(self), rb_str_new2(symbol));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onOperatorStart' for ", STR2CSTR(tmp));
  }
}

void nq_onOperatorEnd (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onOperatorEnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onOperatorEnd"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onOperatorEnd' for ", STR2CSTR(tmp));
  }
}

void nq_onFunctionStart (void* self, char* name, char* doc)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFunctionStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onFunctionStart"), 3, (VALUE)(self), rb_str_new2(name), rb_str_new2(doc));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFunctionStart' for ", STR2CSTR(tmp));
  }
}

void nq_onFunctionExtern (void* self, char* externName)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFunctionExtern"))) {
    rb_funcall((VALUE)(self), rb_intern("onFunctionExtern"), 2, (VALUE)(self), rb_str_new2(externName));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFunctionExtern' for ", STR2CSTR(tmp));
  }
}

void nq_onFunctionUnmangled (void* self, char* unmangledName)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFunctionUnmangled"))) {
    rb_funcall((VALUE)(self), rb_intern("onFunctionUnmangled"), 2, (VALUE)(self), rb_str_new2(unmangledName));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFunctionUnmangled' for ", STR2CSTR(tmp));
  }
}

void nq_onFunctionAbstract (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFunctionAbstract"))) {
    rb_funcall((VALUE)(self), rb_intern("onFunctionAbstract"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFunctionAbstract' for ", STR2CSTR(tmp));
  }
}

void nq_onFunctionThisRef (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFunctionThisRef"))) {
    rb_funcall((VALUE)(self), rb_intern("onFunctionThisRef"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFunctionThisRef' for ", STR2CSTR(tmp));
  }
}

void nq_onFunctionArgsStart (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFunctionArgsStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onFunctionArgsStart"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFunctionArgsStart' for ", STR2CSTR(tmp));
  }
}

void nq_onFunctionArgsEnd (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFunctionArgsEnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onFunctionArgsEnd"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFunctionArgsEnd' for ", STR2CSTR(tmp));
  }
}

void nq_onFunctionReturnType (void* self, void* type)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFunctionReturnType"))) {
    rb_funcall((VALUE)(self), rb_intern("onFunctionReturnType"), 2, (VALUE)(self), type);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFunctionReturnType' for ", STR2CSTR(tmp));
  }
}

void nq_onFunctionConst (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFunctionConst"))) {
    rb_funcall((VALUE)(self), rb_intern("onFunctionConst"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFunctionConst' for ", STR2CSTR(tmp));
  }
}

void nq_onFunctionStatic (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFunctionStatic"))) {
    rb_funcall((VALUE)(self), rb_intern("onFunctionStatic"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFunctionStatic' for ", STR2CSTR(tmp));
  }
}

void nq_onFunctionInline (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFunctionInline"))) {
    rb_funcall((VALUE)(self), rb_intern("onFunctionInline"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFunctionInline' for ", STR2CSTR(tmp));
  }
}

void nq_onFunctionFinal (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFunctionFinal"))) {
    rb_funcall((VALUE)(self), rb_intern("onFunctionFinal"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFunctionFinal' for ", STR2CSTR(tmp));
  }
}

void nq_onFunctionProto (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFunctionProto"))) {
    rb_funcall((VALUE)(self), rb_intern("onFunctionProto"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFunctionProto' for ", STR2CSTR(tmp));
  }
}

void nq_onFunctionSuper (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFunctionSuper"))) {
    rb_funcall((VALUE)(self), rb_intern("onFunctionSuper"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFunctionSuper' for ", STR2CSTR(tmp));
  }
}

void nq_onFunctionSuffix (void* self, char* name)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFunctionSuffix"))) {
    rb_funcall((VALUE)(self), rb_intern("onFunctionSuffix"), 2, (VALUE)(self), rb_str_new2(name));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFunctionSuffix' for ", STR2CSTR(tmp));
  }
}

void nq_onFunctionBody (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFunctionBody"))) {
    rb_funcall((VALUE)(self), rb_intern("onFunctionBody"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFunctionBody' for ", STR2CSTR(tmp));
  }
}

void * nq_onFunctionEnd (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFunctionEnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onFunctionEnd"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFunctionEnd' for ", STR2CSTR(tmp));
  }
}

void nq_onTypeArg (void* self, void* type)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onTypeArg"))) {
    rb_funcall((VALUE)(self), rb_intern("onTypeArg"), 2, (VALUE)(self), type);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onTypeArg' for ", STR2CSTR(tmp));
  }
}

void nq_onVarArg (void* self, char* name)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onVarArg"))) {
    rb_funcall((VALUE)(self), rb_intern("onVarArg"), 2, (VALUE)(self), rb_str_new2(name));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onVarArg' for ", STR2CSTR(tmp));
  }
}

void nq_onDotArg (void* self, char* name)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onDotArg"))) {
    rb_funcall((VALUE)(self), rb_intern("onDotArg"), 2, (VALUE)(self), rb_str_new2(name));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onDotArg' for ", STR2CSTR(tmp));
  }
}

void nq_onAssArg (void* self, char* name)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onAssArg"))) {
    rb_funcall((VALUE)(self), rb_intern("onAssArg"), 2, (VALUE)(self), rb_str_new2(name));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onAssArg' for ", STR2CSTR(tmp));
  }
}

void nq_onFunctionCallStart (void* self, char* yytext)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFunctionCallStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onFunctionCallStart"), 2, (VALUE)(self), rb_str_new2(yytext));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFunctionCallStart' for ", STR2CSTR(tmp));
  }
}

void nq_onFunctionCallSuffix (void* self, char* yytext)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFunctionCallSuffix"))) {
    rb_funcall((VALUE)(self), rb_intern("onFunctionCallSuffix"), 2, (VALUE)(self), rb_str_new2(yytext));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFunctionCallSuffix' for ", STR2CSTR(tmp));
  }
}

void nq_onFunctionCallArg (void* self, void* expr)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFunctionCallArg"))) {
    rb_funcall((VALUE)(self), rb_intern("onFunctionCallArg"), 2, (VALUE)(self), expr);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFunctionCallArg' for ", STR2CSTR(tmp));
  }
}

void * nq_onFunctionCallEnd (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFunctionCallEnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onFunctionCallEnd"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFunctionCallEnd' for ", STR2CSTR(tmp));
  }
}

void nq_onFunctionCallExpr (void* self, void* call, void* expr)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFunctionCallExpr"))) {
    rb_funcall((VALUE)(self), rb_intern("onFunctionCallExpr"), 3, (VALUE)(self), call, expr);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFunctionCallExpr' for ", STR2CSTR(tmp));
  }
}

void * nq_onFunctionCallChain (void* self, void* expr, void* call)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFunctionCallChain"))) {
    rb_funcall((VALUE)(self), rb_intern("onFunctionCallChain"), 3, (VALUE)(self), expr, call);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFunctionCallChain' for ", STR2CSTR(tmp));
  }
}

void nq_onFunctionCallCombo (void* self, void* call, void* expr)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFunctionCallCombo"))) {
    rb_funcall((VALUE)(self), rb_intern("onFunctionCallCombo"), 3, (VALUE)(self), call, expr);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFunctionCallCombo' for ", STR2CSTR(tmp));
  }
}

void nq_onArrayLiteralStart (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onArrayLiteralStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onArrayLiteralStart"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onArrayLiteralStart' for ", STR2CSTR(tmp));
  }
}

void * nq_onArrayLiteralEnd (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onArrayLiteralEnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onArrayLiteralEnd"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onArrayLiteralEnd' for ", STR2CSTR(tmp));
  }
}

void nq_onTupleStart (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onTupleStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onTupleStart"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onTupleStart' for ", STR2CSTR(tmp));
  }
}

void * nq_onTupleEnd (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onTupleEnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onTupleEnd"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onTupleEnd' for ", STR2CSTR(tmp));
  }
}

void * nq_onStringLiteral (void* self, char* text)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onStringLiteral"))) {
    rb_funcall((VALUE)(self), rb_intern("onStringLiteral"), 2, (VALUE)(self), rb_str_new2(text));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onStringLiteral' for ", STR2CSTR(tmp));
  }
}

void * nq_onCharLiteral (void* self, char* value)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onCharLiteral"))) {
    rb_funcall((VALUE)(self), rb_intern("onCharLiteral"), 2, (VALUE)(self), rb_str_new2(value));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onCharLiteral' for ", STR2CSTR(tmp));
  }
}

void nq_onStatement (void* self, void* statement)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onStatement"))) {
    rb_funcall((VALUE)(self), rb_intern("onStatement"), 2, (VALUE)(self), statement);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onStatement' for ", STR2CSTR(tmp));
  }
}

void * nq_onReturn (void* self, void* expr)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onReturn"))) {
    rb_funcall((VALUE)(self), rb_intern("onReturn"), 2, (VALUE)(self), expr);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onReturn' for ", STR2CSTR(tmp));
  }
}

void * nq_onVarAccess (void* self, void* expr, char* name)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onVarAccess"))) {
    rb_funcall((VALUE)(self), rb_intern("onVarAccess"), 3, (VALUE)(self), expr, rb_str_new2(name));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onVarAccess' for ", STR2CSTR(tmp));
  }
}

void nq_onArrayAccessStart (void* self, void* array)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onArrayAccessStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onArrayAccessStart"), 2, (VALUE)(self), array);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onArrayAccessStart' for ", STR2CSTR(tmp));
  }
}

void * nq_onArrayAccessEnd (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onArrayAccessEnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onArrayAccessEnd"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onArrayAccessEnd' for ", STR2CSTR(tmp));
  }
}

void * nq_onCast (void* self, void* expr, void* type)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onCast"))) {
    rb_funcall((VALUE)(self), rb_intern("onCast"), 3, (VALUE)(self), expr, type);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onCast' for ", STR2CSTR(tmp));
  }
}

void * nq_onBreak (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onBreak"))) {
    rb_funcall((VALUE)(self), rb_intern("onBreak"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onBreak' for ", STR2CSTR(tmp));
  }
}

void * nq_onContinue (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onContinue"))) {
    rb_funcall((VALUE)(self), rb_intern("onContinue"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onContinue' for ", STR2CSTR(tmp));
  }
}

void nq_onBlockStart (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onBlockStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onBlockStart"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onBlockStart' for ", STR2CSTR(tmp));
  }
}

void * nq_onBlockEnd (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onBlockEnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onBlockEnd"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onBlockEnd' for ", STR2CSTR(tmp));
  }
}

void nq_onIfStart (void* self, void* condition)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onIfStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onIfStart"), 2, (VALUE)(self), condition);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onIfStart' for ", STR2CSTR(tmp));
  }
}

void * nq_onIfEnd (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onIfEnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onIfEnd"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onIfEnd' for ", STR2CSTR(tmp));
  }
}

void nq_onElseStart (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onElseStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onElseStart"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onElseStart' for ", STR2CSTR(tmp));
  }
}

void * nq_onElseEnd (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onElseEnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onElseEnd"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onElseEnd' for ", STR2CSTR(tmp));
  }
}

void nq_onForeachStart (void* self, void* decl, void* collec)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onForeachStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onForeachStart"), 3, (VALUE)(self), decl, collec);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onForeachStart' for ", STR2CSTR(tmp));
  }
}

void * nq_onForeachEnd (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onForeachEnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onForeachEnd"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onForeachEnd' for ", STR2CSTR(tmp));
  }
}

void nq_onWhileStart (void* self, void* condition)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onWhileStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onWhileStart"), 2, (VALUE)(self), condition);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onWhileStart' for ", STR2CSTR(tmp));
  }
}

void * nq_onWhileEnd (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onWhileEnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onWhileEnd"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onWhileEnd' for ", STR2CSTR(tmp));
  }
}

void * nq_onEquals (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onEquals"))) {
    rb_funcall((VALUE)(self), rb_intern("onEquals"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onEquals' for ", STR2CSTR(tmp));
  }
}

void * nq_onNotEquals (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onNotEquals"))) {
    rb_funcall((VALUE)(self), rb_intern("onNotEquals"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onNotEquals' for ", STR2CSTR(tmp));
  }
}

void * nq_onLessThan (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onLessThan"))) {
    rb_funcall((VALUE)(self), rb_intern("onLessThan"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onLessThan' for ", STR2CSTR(tmp));
  }
}

void * nq_onMoreThan (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onMoreThan"))) {
    rb_funcall((VALUE)(self), rb_intern("onMoreThan"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onMoreThan' for ", STR2CSTR(tmp));
  }
}

void * nq_onCmp (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onCmp"))) {
    rb_funcall((VALUE)(self), rb_intern("onCmp"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onCmp' for ", STR2CSTR(tmp));
  }
}

void * nq_onLessThanOrEqual (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onLessThanOrEqual"))) {
    rb_funcall((VALUE)(self), rb_intern("onLessThanOrEqual"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onLessThanOrEqual' for ", STR2CSTR(tmp));
  }
}

void * nq_onMoreThanOrEqual (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onMoreThanOrEqual"))) {
    rb_funcall((VALUE)(self), rb_intern("onMoreThanOrEqual"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onMoreThanOrEqual' for ", STR2CSTR(tmp));
  }
}

void * nq_onDecLiteral (void* self, char* value)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onDecLiteral"))) {
    rb_funcall((VALUE)(self), rb_intern("onDecLiteral"), 2, (VALUE)(self), rb_str_new2(value));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onDecLiteral' for ", STR2CSTR(tmp));
  }
}

void * nq_onBinLiteral (void* self, char* value)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onBinLiteral"))) {
    rb_funcall((VALUE)(self), rb_intern("onBinLiteral"), 2, (VALUE)(self), rb_str_new2(value));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onBinLiteral' for ", STR2CSTR(tmp));
  }
}

void * nq_onOctLiteral (void* self, char* value)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onOctLiteral"))) {
    rb_funcall((VALUE)(self), rb_intern("onOctLiteral"), 2, (VALUE)(self), rb_str_new2(value));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onOctLiteral' for ", STR2CSTR(tmp));
  }
}

void * nq_onHexLiteral (void* self, char* value)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onHexLiteral"))) {
    rb_funcall((VALUE)(self), rb_intern("onHexLiteral"), 2, (VALUE)(self), rb_str_new2(value));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onHexLiteral' for ", STR2CSTR(tmp));
  }
}

void * nq_onFloatLiteral (void* self, char* value)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onFloatLiteral"))) {
    rb_funcall((VALUE)(self), rb_intern("onFloatLiteral"), 2, (VALUE)(self), rb_str_new2(value));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onFloatLiteral' for ", STR2CSTR(tmp));
  }
}

void * nq_onBoolLiteral (void* self, bool value)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onBoolLiteral"))) {
    rb_funcall((VALUE)(self), rb_intern("onBoolLiteral"), 2, (VALUE)(self), value);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onBoolLiteral' for ", STR2CSTR(tmp));
  }
}

void * nq_onNull (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onNull"))) {
    rb_funcall((VALUE)(self), rb_intern("onNull"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onNull' for ", STR2CSTR(tmp));
  }
}

void * nq_onDoubleArrow (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onDoubleArrow"))) {
    rb_funcall((VALUE)(self), rb_intern("onDoubleArrow"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onDoubleArrow' for ", STR2CSTR(tmp));
  }
}

void * nq_onTernary (void* self, void* condition, void* ifTrue, void* ifFalse)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onTernary"))) {
    rb_funcall((VALUE)(self), rb_intern("onTernary"), 4, (VALUE)(self), condition, ifTrue, ifFalse);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onTernary' for ", STR2CSTR(tmp));
  }
}

void * nq_onAssignAnd (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onAssignAnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onAssignAnd"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onAssignAnd' for ", STR2CSTR(tmp));
  }
}

void * nq_onAssignOr (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onAssignOr"))) {
    rb_funcall((VALUE)(self), rb_intern("onAssignOr"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onAssignOr' for ", STR2CSTR(tmp));
  }
}

void * nq_onAssignXor (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onAssignXor"))) {
    rb_funcall((VALUE)(self), rb_intern("onAssignXor"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onAssignXor' for ", STR2CSTR(tmp));
  }
}

void * nq_onAssignRightShift (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onAssignRightShift"))) {
    rb_funcall((VALUE)(self), rb_intern("onAssignRightShift"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onAssignRightShift' for ", STR2CSTR(tmp));
  }
}

void * nq_onAssignLeftShift (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onAssignLeftShift"))) {
    rb_funcall((VALUE)(self), rb_intern("onAssignLeftShift"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onAssignLeftShift' for ", STR2CSTR(tmp));
  }
}

void * nq_onAssignDiv (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onAssignDiv"))) {
    rb_funcall((VALUE)(self), rb_intern("onAssignDiv"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onAssignDiv' for ", STR2CSTR(tmp));
  }
}

void * nq_onAssignMul (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onAssignMul"))) {
    rb_funcall((VALUE)(self), rb_intern("onAssignMul"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onAssignMul' for ", STR2CSTR(tmp));
  }
}

void * nq_onAssignExp (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onAssignExp"))) {
    rb_funcall((VALUE)(self), rb_intern("onAssignExp"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onAssignExp' for ", STR2CSTR(tmp));
  }
}

void * nq_onAssignSub (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onAssignSub"))) {
    rb_funcall((VALUE)(self), rb_intern("onAssignSub"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onAssignSub' for ", STR2CSTR(tmp));
  }
}

void * nq_onAssignAdd (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onAssignAdd"))) {
    rb_funcall((VALUE)(self), rb_intern("onAssignAdd"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onAssignAdd' for ", STR2CSTR(tmp));
  }
}

void * nq_onAssign (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onAssign"))) {
    rb_funcall((VALUE)(self), rb_intern("onAssign"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onAssign' for ", STR2CSTR(tmp));
  }
}

void * nq_onAdd (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onAdd"))) {
    rb_funcall((VALUE)(self), rb_intern("onAdd"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onAdd' for ", STR2CSTR(tmp));
  }
}

void * nq_onSub (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onSub"))) {
    rb_funcall((VALUE)(self), rb_intern("onSub"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onSub' for ", STR2CSTR(tmp));
  }
}

void * nq_onMod (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onMod"))) {
    rb_funcall((VALUE)(self), rb_intern("onMod"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onMod' for ", STR2CSTR(tmp));
  }
}

void * nq_onMul (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onMul"))) {
    rb_funcall((VALUE)(self), rb_intern("onMul"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onMul' for ", STR2CSTR(tmp));
  }
}

void * nq_onExp (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onExp"))) {
    rb_funcall((VALUE)(self), rb_intern("onExp"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onExp' for ", STR2CSTR(tmp));
  }
}

void * nq_onDiv (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onDiv"))) {
    rb_funcall((VALUE)(self), rb_intern("onDiv"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onDiv' for ", STR2CSTR(tmp));
  }
}

void * nq_onRangeLiteral (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onRangeLiteral"))) {
    rb_funcall((VALUE)(self), rb_intern("onRangeLiteral"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onRangeLiteral' for ", STR2CSTR(tmp));
  }
}

void * nq_onBinaryLeftShift (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onBinaryLeftShift"))) {
    rb_funcall((VALUE)(self), rb_intern("onBinaryLeftShift"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onBinaryLeftShift' for ", STR2CSTR(tmp));
  }
}

void * nq_onBinaryRightShift (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onBinaryRightShift"))) {
    rb_funcall((VALUE)(self), rb_intern("onBinaryRightShift"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onBinaryRightShift' for ", STR2CSTR(tmp));
  }
}

void * nq_onLogicalOr (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onLogicalOr"))) {
    rb_funcall((VALUE)(self), rb_intern("onLogicalOr"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onLogicalOr' for ", STR2CSTR(tmp));
  }
}

void * nq_onLogicalAnd (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onLogicalAnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onLogicalAnd"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onLogicalAnd' for ", STR2CSTR(tmp));
  }
}

void * nq_onBinaryOr (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onBinaryOr"))) {
    rb_funcall((VALUE)(self), rb_intern("onBinaryOr"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onBinaryOr' for ", STR2CSTR(tmp));
  }
}

void * nq_onBinaryXor (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onBinaryXor"))) {
    rb_funcall((VALUE)(self), rb_intern("onBinaryXor"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onBinaryXor' for ", STR2CSTR(tmp));
  }
}

void * nq_onBinaryAnd (void* self, void* left, void* right)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onBinaryAnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onBinaryAnd"), 3, (VALUE)(self), left, right);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onBinaryAnd' for ", STR2CSTR(tmp));
  }
}

void * nq_onLogicalNot (void* self, void* inner)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onLogicalNot"))) {
    rb_funcall((VALUE)(self), rb_intern("onLogicalNot"), 2, (VALUE)(self), inner);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onLogicalNot' for ", STR2CSTR(tmp));
  }
}

void * nq_onBinaryNot (void* self, void* inner)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onBinaryNot"))) {
    rb_funcall((VALUE)(self), rb_intern("onBinaryNot"), 2, (VALUE)(self), inner);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onBinaryNot' for ", STR2CSTR(tmp));
  }
}

void * nq_onUnaryMinus (void* self, void* inner)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onUnaryMinus"))) {
    rb_funcall((VALUE)(self), rb_intern("onUnaryMinus"), 2, (VALUE)(self), inner);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onUnaryMinus' for ", STR2CSTR(tmp));
  }
}

void * nq_onParenthesis (void* self, void* inner)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onParenthesis"))) {
    rb_funcall((VALUE)(self), rb_intern("onParenthesis"), 2, (VALUE)(self), inner);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onParenthesis' for ", STR2CSTR(tmp));
  }
}

void nq_onGenericArgument (void* self, char* name)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onGenericArgument"))) {
    rb_funcall((VALUE)(self), rb_intern("onGenericArgument"), 2, (VALUE)(self), rb_str_new2(name));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onGenericArgument' for ", STR2CSTR(tmp));
  }
}

void * nq_onAddressOf (void* self, void* inner)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onAddressOf"))) {
    rb_funcall((VALUE)(self), rb_intern("onAddressOf"), 2, (VALUE)(self), inner);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onAddressOf' for ", STR2CSTR(tmp));
  }
}

void * nq_onDereference (void* self, void* inner)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onDereference"))) {
    rb_funcall((VALUE)(self), rb_intern("onDereference"), 2, (VALUE)(self), inner);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onDereference' for ", STR2CSTR(tmp));
  }
}

void nq_onMatchStart (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onMatchStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onMatchStart"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onMatchStart' for ", STR2CSTR(tmp));
  }
}

void nq_onMatchExpr (void* self, void* value)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onMatchExpr"))) {
    rb_funcall((VALUE)(self), rb_intern("onMatchExpr"), 2, (VALUE)(self), value);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onMatchExpr' for ", STR2CSTR(tmp));
  }
}

void * nq_onMatchEnd (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onMatchEnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onMatchEnd"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onMatchEnd' for ", STR2CSTR(tmp));
  }
}

void nq_onCaseStart (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onCaseStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onCaseStart"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onCaseStart' for ", STR2CSTR(tmp));
  }
}

void nq_onCaseExpr (void* self, void* value)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onCaseExpr"))) {
    rb_funcall((VALUE)(self), rb_intern("onCaseExpr"), 2, (VALUE)(self), value);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onCaseExpr' for ", STR2CSTR(tmp));
  }
}

void nq_onCaseEnd (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onCaseEnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onCaseEnd"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onCaseEnd' for ", STR2CSTR(tmp));
  }
}

void nq_onTryStart (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onTryStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onTryStart"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onTryStart' for ", STR2CSTR(tmp));
  }
}

void * nq_onTryEnd (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onTryEnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onTryEnd"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onTryEnd' for ", STR2CSTR(tmp));
  }
}

void nq_onCatchStart (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onCatchStart"))) {
    rb_funcall((VALUE)(self), rb_intern("onCatchStart"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onCatchStart' for ", STR2CSTR(tmp));
  }
}

void nq_onCatchExpr (void* self, void* value)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onCatchExpr"))) {
    rb_funcall((VALUE)(self), rb_intern("onCatchExpr"), 2, (VALUE)(self), value);
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onCatchExpr' for ", STR2CSTR(tmp));
  }
}

void nq_onCatchEnd (void* self)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("onCatchEnd"))) {
    rb_funcall((VALUE)(self), rb_intern("onCatchEnd"), 1, (VALUE)(self));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `onCatchEnd' for ", STR2CSTR(tmp));
  }
}

void nq_error (void* self, int errorID, char* defaultMessage, int index)
{
  if(rb_funcall((VALUE)(self), rb_intern("respond_to?"), 1, rb_str_new2("error"))) {
    rb_funcall((VALUE)(self), rb_intern("error"), 4, (VALUE)(self), INT2NUM(errorID), rb_str_new2(defaultMessage), INT2NUM(index));
  } else {
    VALUE tmp = rb_funcall((VALUE)(self), rb_intern("inspect"), 0);
    rb_raise(rb_intern("NameError"), "undefined method `error' for ", STR2CSTR(tmp));
  }
}

