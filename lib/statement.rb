class OocParser
  rule(:stmt) { (
                  old.as(:old) >> ws >> str('version') >> ws >> str('(') >> hyphen >> versionSpec.as(:spec) >> ws >> str(')') >>
                  ((hyphen >> str('{') >> ws >> stmt.as(:s).repeat(0) >> ws >> hyphen >> str('}')) | (hyphen >> stmt.as(:s))) >>
                  (ws >> str('else') >> hyphen >> str('version') >> ws >> str('(') >>  hyphen >> versionSpec.as(:elseSpec) >> ws >> str(')') >>
                    ((hyphen >> str('{') >> ws >> stmt.repeat(0) >> ws >> hyphen >> str( '}')) | (hyphen >> stmt))
                  ).repeat(0) >>
                  (ws >> str('else') >> ((hyphen >> str('{') >> ws >> stmt.repeat(0) >> ws >> hyphen >> str('}')) | (hyphen >> stmt))).maybe
                ) | stmtCore }

  rule(:stmtCore) { (
                    # some statements need an EOL after them...
                    eoledStatement.as(:e) >>
                    (terminator.repeat(1) | (ws >> &str('}')) | (ws >>  &str(')')) | (ws >> &str(',')) | (&commentLine))
                    ) |
                    # ...but block don't
                    ws >> conditional.as(:c) |
                    ws >> block.as(:b)       |
                    ws >> flowControl.as(:f) >> terminator.repeat(0) |
                    ws >> match.as(:m)       |
                    ws >> try.as(:t) }

  rule(:eoledStatement) {  ( ws >> return_ | ws >> variableDecl | ws >> expr)

  rule(:conditional) { if_ | else_ }

  rule(:block) { (str('{') >>  (ws >> stmt.as(:s) >> ws).repeat(0) >> ws >> str('}')) }

  rule(:if_) { (if_kw >> ws >> str('(') >> ws >> hyphen >> expr.as(:e) >> ws >> str(')') >> hyphen >> body) }

  rule(:else_) { else_kw >> hyphen >> body }

  rule(:case_) { case_kw >> (hyphen >> caseExpr.as(:v)).maybe >> ws >> double_arrow >> (ws >> stmt.as(:s) >> ws).repeat(0) >> ws }

  rule(:match) { match_kw >> (hyphen >> value.as(:v)).maybe >> ws >> str('{') >>
                 (ws >> case_ >> ws).repeat(0) >> ws >> str('}') }

  rule(:try) { try_kw >> hyphen >> body >> (ws >> catch >> ws).repeat(0) }

  rule(:catch) { catch_kw >> (hyphen >> expr.as(:v)).maybe >> ws >> str('{') >> (ws >> stmt.as(:s) >> ws).repeat(0) >> ws >> str('}') }
end
