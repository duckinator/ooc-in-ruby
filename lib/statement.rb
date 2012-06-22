class OocParser
  rule(:stmt) { (
                  ws >> str('version') >> ws >> str('(') >> _ >> versionSpec.as(:spec) >> ws >> str(')') >>
                  ((_ >> str('{') >> ws >> stmt.as(:s).repeat(0) >> ws >> _ >> str('}')) | (_ >> stmt.as(:s))) >>
                  (ws >> str('else') >> _ >> str('version') >> ws >> str('(') >>  _ >> versionSpec.as(:elseSpec) >> ws >> str(')') >>
                    ((_ >> str('{') >> ws >> stmt.repeat(0) >> ws >> _ >> str( '}')) | (_ >> stmt))
                  ).repeat(0) >>
                  (ws >> str('else') >> ((_ >> str('{') >> ws >> stmt.repeat(0) >> ws >> _ >> str('}')) | (_ >> stmt))).maybe
                ) | stmtCore }

  rule(:stmtCore) { (
                    # some statements need an EOL after them...
                    eoledStatement.as(:e) >>
                    (terminator.repeat(1) | (ws >> str('}')) | (ws >>  str(')')) | (ws >> str(',')) | (commentLine))
                    ) |
                    # ...but block don't
                    ws >> conditional.as(:c) |
                    ws >> block.as(:b)       |
                    ws >> flowControl.as(:f) >> terminator.repeat(0) |
                    ws >> match.as(:m)       |
                    ws >> try_.as(:t) }

  rule(:eoledStatement) {  (ws >> return_ | ws >> variableDecl | ws >> expr) }

  rule(:conditional) { if_ | else_ }

  rule(:block) { (str('{') >>  (ws >> stmt.as(:s) >> ws).repeat(0) >> ws >> str('}')) }

  rule(:if_) { (if_kw >> ws >> str('(') >> ws >> _ >> expr.as(:e) >> ws >> str(')') >> _ >> body) }

  rule(:else_) { else_kw >> _ >> body }

  rule(:case_) { case_kw >> (_ >> caseExpr.as(:v)).maybe >> ws >> double_arrow >> (ws >> stmt.as(:s) >> ws).repeat(0) >> ws }

  rule(:match) { match_kw >> (_ >> value.as(:v)).maybe >> ws >> str('{') >>
                 (ws >> case_ >> ws).repeat(0) >> ws >> str('}') }

  rule(:try_) { try_kw >> _ >> body >> (ws >> catch_ >> ws).repeat(0) }

  rule(:catch_) { catch_kw >> (_ >> expr.as(:v)).maybe >> ws >> str('{') >> (ws >> stmt.as(:s) >> ws).repeat(0) >> ws >> str('}') }
end
