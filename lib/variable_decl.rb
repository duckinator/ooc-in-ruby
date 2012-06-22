__END__

VarDeclFromExpr = ( doc: OocDoc

                    ( i:IDENT   { tokenPos; nq_onVarDeclStart(core->this); nq_onVarDeclName (core->this, i,   doc); }
                    | tup:Tuple { nq_onVarDeclStart(core->this); nq_onVarDeclTuple(core->this, tup); })
                  - ASS_DECL
                  (-
                    (
                        STATIC_KW { nq_onVarDeclStatic(core->this); }
                      | CONST_KW  { nq_onVarDeclConst (core->this); }
                      | PROTO_KW  { nq_onVarDeclProto (core->this); }
                    ) &[^A-Za-z_0-9]
                  )*
                  - r:Expr { nq_onVarDeclExpr(core->this, r); }
                  - { $$=nq_onVarDeclEnd(core->this); }
                  )

ConventionalVarDecl =
            { nq_onVarDeclStart(core->this); }

            (
            doc: OocDoc
            varDeclName:IDENT { tokenPos; nq_onVarDeclName(core->this, varDeclName, doc); }
            (- ASS - Expr { nq_onVarDeclExpr(core->this, $$); })?

            # multi-decls
            (
            - ','
            doc: OocDoc
            WS nextDeclName:IDENT { nq_onVarDeclName(core->this, nextDeclName, doc); }
            (- ASS - Expr { nq_onVarDeclExpr(core->this, $$); })?
            -
            )*

            WS COLON WS
            (-
              (
                  STATIC_KW { nq_onVarDeclStatic(core->this); }
                | CONST_KW  { nq_onVarDeclConst (core->this); }
                | PROTO_KW  { nq_onVarDeclProto (core->this); }
                | externName:ExternName { nq_onVarDeclExtern(core->this, externName); }
                | unmangledName:UnmangledName { nq_onVarDeclUnmangled(core->this, unmangledName); }
              )
            )*
            WS Type { nq_onVarDeclType(core->this, $$); }
            (- ASS - Expr { nq_onVarDeclExpr(core->this, $$); })?
            )  { $$=nq_onVarDeclEnd(core->this); }

VariableDecl = (v:VarDeclFromExpr     { $$=v })
             | (v:ConventionalVarDecl { $$=v })

