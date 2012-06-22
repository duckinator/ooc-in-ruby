__END__

# TODO

Stmt     = (
                old:Old
                WS 'version' { tokenPos; }
                WS '('
                - spec:VersionSpec
                WS ')'
                ((
                - '{' { nq_onVersionStart(core->this, spec); }
                WS (s:Stmt { nq_onStatement(core->this, s); })* WS
                - '}' { old=$$=nq_onVersionEnd(core->this); }
                )
                |
                (
                - s:Stmt { nq_onVersionStart(core->this, spec); nq_onStatement(core->this, s); old=$$=nq_onVersionEnd(core->this); }
                ))
                (
                  WS 'else' - 'version' { tokenPos }
                  WS '('
                  - elseSpec: VersionSpec
                  WS ')'
                  ((
                  - '{' { spec = nq_onVersionElseIfStart(core->this, spec, elseSpec) }
                  WS (s:Stmt { nq_onStatement(core->this, s); })* WS
                  - '}' { $$=nq_onVersionEnd(core->this); nq_onStatement(core->this, old); old=$$ }
                  )
                  |
                  (
                  - s:Stmt { spec = nq_onVersionElseIfStart(core->this, spec, elseSpec); nq_onStatement(core->this, s); $$=nq_onVersionEnd(core->this); nq_onStatement(core->this, old); old=$$ }
                  ))
                )*
                (
                  WS 'else' { tokenPos }
                  ((
                  - '{' { nq_onVersionElseStart(core->this, spec) }
                  WS (s:Stmt { nq_onStatement(core->this, s); })* WS
                  - '}' { $$=nq_onVersionEnd(core->this); nq_onStatement(core->this, old); old=$$ }
                  )
                  |
                  (
                  - s:Stmt { nq_onVersionElseStart(core->this, spec); nq_onStatement(core->this, s); $$=nq_onVersionEnd(core->this); nq_onStatement(core->this, old); old=$$ }
                  ))
                )?
            )
         | StmtCore

StmtCore = (
              # some statements need an EOL after them...
              e:EoledStatement
              (Terminator+ | (WS &'}') | (WS &')') | (WS &',') | (&CommentLine))
           )
          | # ...but block don't
          ( WS c:Conditional
          | WS b:Block
          | WS f:FlowControl (Terminator*)
          | WS m:Match
          | WS t:Try
          )

EoledStatement =  ( WS Return
                  | WS VariableDecl
                  | WS Expr
                  )

Conditional = (If | Else)

Block   = (
           '{' { tokenPos; nq_onBlockStart(core->this); }
          (WS s:Stmt { tokenPos; nq_onStatement(core->this, s) } WS)*
           WS '}' { $$=nq_onBlockEnd(core->this); }
          )

If      = (
          IF_KW { tokenPos; }
          WS '(' WS
          - e:Expr       { nq_onIfStart(core->this, e); }
          WS ')'
          - Body
          )              { $$=nq_onIfEnd(core->this); }

Else    = (
          ELSE_KW  { tokenPos; }
                         { nq_onElseStart(core->this); }
          - Body
          )              { $$=nq_onElseEnd(core->this); }

Case    = CASE_KW  { tokenPos; nq_onCaseStart(core->this); }
        (- v:CaseExpr { nq_onCaseExpr(core->this, v); })?
        WS DOUBLE_ARROW
         (WS
          (s:Stmt  { nq_onStatement(core->this, s) })
          WS)*
          WS
          { nq_onCaseEnd(core->this); }

Match   = MATCH_KW { tokenPos; nq_onMatchStart(core->this); }
            (- v: Value { nq_onMatchExpr(core->this, v); })?
          WS '{'
          (WS Case WS)*
          WS CLOS_BRACK ~{ nq_error(core->this, NQE_EXP_CASE_IN_MATCH, "Expected case in match", G->pos + G->offset) }
          { $$=nq_onMatchEnd(core->this); }

Try     = TRY_KW { tokenPos; nq_onTryStart(core->this); }
          - Body
          (WS Catch WS)*
          { $$=nq_onTryEnd(core->this); }

Catch   = CATCH_KW { tokenPos; nq_onCatchStart(core->this); }
          (- v:Expr { nq_onCatchExpr(core->this, v); })?
          WS '{'
          (WS s:Stmt WS { nq_onStatement(core->this, s); })*
          WS '}'
          { nq_onCatchEnd(core->this); }
