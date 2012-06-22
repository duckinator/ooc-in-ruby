__END__

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

