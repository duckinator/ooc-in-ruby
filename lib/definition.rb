class OocParser
  rule(:defineName) { (match('[A-Za-z0-9_/._]') | str('-')).repeat(1) }

  rule(:defineValue) { str('=') >> (match('[A-Za-z0-9_/._]') | str('-')).repeat(1) }
end
