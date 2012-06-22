__END__

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

