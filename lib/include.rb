class OocParser
  rule(:include) { include_kw >> match('[ \t]') >> _ >> includeCore >> (_ >> str(',') >> _ >> includeCore).repeat(0) }

  rule(:includeCore) { (match('[A-Za-z0-9/._]') | str('-')).repeat(1) >>
                       (_ >> str('|') >> _ >> str('(') >>
                        _ >> defineName.as(:defineName) >> defineValue.as(:defineVal) >>
                        (_ >> str(',') >>
                         _ >> defineName.as(:defineName) >> defineValue.as(:defineVal)
                        ).repeat(0) >>
                        _ >> str(')')
                       ).maybe }
end
