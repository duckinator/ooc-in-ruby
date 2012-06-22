__END__

Module  =  ModuleCore
          | WS ( !EOL . )*
          EOL { tokenPos; char *message = "Expected include, import, statement or declaration\n";
            if(G->buf[core->token[0]] == _CBRACK) { message = "Unmatched closing bracket"; }
            nq_error(core->this, NQE_EXP_INC_IMP_STMT_OR_DECL, message, core->token[0]);
          }

ModuleCore = (WS 'version' { tokenPos }
              WS '('
              - spec: VersionSpec
              WS ')'
              ((
              - '{' { nq_onVersionStart(core->this, spec) }
              WS ModuleCore* WS
              - '}' { nq_onVersionEnd(core->this) }
              )
              |
              (
              - s:Stmt { nq_onVersionStart(core->this, spec); nq_onStatement(core->this, s); nq_onVersionEnd(core->this) }
              ))
              (
                  WS 'else' - 'version' { tokenPos }
                  WS '('
                  - elseSpec: VersionSpec
                  WS ')'
                  ((
                  - '{' { spec = nq_onVersionElseIfStart(core->this, spec, elseSpec) }
                  WS ModuleCore* WS
                  - '}' { nq_onVersionEnd(core->this) }
                  )
                  |
                  (
                  - s:Stmt { spec = nq_onVersionElseIfStart(core->this, spec, elseSpec); nq_onStatement(core->this, s); nq_onVersionEnd(core->this) }
                  ))
              )*
              (
                  WS 'else' { tokenPos }
                  ((
                  - '{' { nq_onVersionElseStart(core->this, spec) }
                  WS ModuleCore* WS
                  - '}' { nq_onVersionEnd(core->this) }
                  )
                  |
                  (
                  - s:Stmt { nq_onVersionElseStart(core->this, spec); nq_onStatement(core->this, s); nq_onVersionEnd(core->this) }
                  ))
              )?
            )
          |(WS Include WS
          | WS Import WS
          | WS Use WS
          | WS Decl WS
          | WS stmt:Stmt WS { nq_onStatement(core->this, stmt) }
          )
