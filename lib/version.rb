class OocParser
  rule(:versionSpec) { ((_ >> str('(') >> _ >> versionSpec.as(:l) >> _ >> str(')')) | (versionCore.as(:l))) >>
                       ((_ >> str('&&') >> _ >> versionSpec.as(:r)) |
                       (hyphen >> str('||') >> _ >> versionSpec.as(:r))).repeat(0) }

  rule(:versionCore )    { versionNegation | versionName }
  rule(:versionName)     { match('[a-zA-Z0-9_]').repeat(1) }
  rule(:versionNegation) { _ >> str('!') >> _ >> versionSpec.as(:spec) }
end
