class OocParser
  rule(:use) { use_kw >> match('[ \t]') >> _ >> useCore >> (_ >> ',' >> _ >> useCore).repeat(0) }

  rule(:useCore) { (match('[A-Za-z0-9/._]') | str('-')).repeat(1) }
end
