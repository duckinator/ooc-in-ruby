class OocParser
  rule(:binaryOperation) { assignment }
  
  rule(:assignment) { ternary >>
                        (ass           >> ws >> ternary |
                        # The following line is actually the only case where AnonymousFunctionDecl makes sense at this level of precedence.
                         ass           >> ws >> anonymousFunctionDecl |
                         ass_add       >> ws >> ternary |
                         ass_sub       >> ws >> ternary |
                         ass_mul       >> ws >> ternary |
                         ass_exp       >> ws >> ternary |
                         ass_div       >> ws >> ternary |
                         ass_b_lshift  >> ws >> ternary |
                         ass_b_rshift  >> ws >> ternary |
                         ass_b_xor     >> ws >> ternary |
                         ass_b_or      >> ws >> ternary |
                         ass_b_and     >> ws >> ternary ).repeat(0) }
  
  rule(:ternary) { logicalOr >> (_ >> quest >> ws >> logicalOr.as(:ifTrue) >> _ >> colon >> ws >> logicalOr.as(:ifFalse)).maybe }
  
  rule(:logicalOr) { logicalAnd >> (l_or >> ws >> logicalAnd).repeat(0) }
  
  rule(:logicalAnd) { binaryOr >> (l_and >> ws >> binaryOr).repeat(0) }
  
  rule(:binaryOr) { binaryXor >> (b_or >> ws >> binaryXor).repeat(0) }
  
  rule(:binaryXor) { binaryAnd >> (b_xor >> ws >> binaryAnd).repeat(0) }
  
  rule(:binaryAnd) { equality >> (b_and >> ws >> equality).repeat(0) }
  
  rule(:equality) { inequality >>
                    (equals      >> ws >> inequality |
                     not_equals  >> ws >> inequality ).repeat(0) }
  
  rule(:inequality) { range >>
                      (lessthan    >> ws >> range |
                       morethan    >> ws >> range |
                       cmp         >> ws >> range |
                       lessthan_eq >> ws >> range |
                       morethan_eq >> ws >> range ).repeat(0) }
  
  rule(:range  ) { shift >> (double_dot >> ws >> shift).repeat(0) }
  
  rule(:shift  ) { sum >> (b_lshift >> ws >> sum | b_rshift >> ws >> sum).repeat(0) }
  
  rule(:sum    ) { product >> 
                        (plus     >> ws >> product |
                         minus    >> ws >> product |
                         percent  >> ws >> product ).repeat(0) }
  
  rule(:product) { productLogicalNot | productBinaryNot | productCore }
  
  rule(:productLogicalNot) { l_not >> _ >> product >> _ }
  rule(:productBinaryNot ) { b_not >> _ >> product >> _ }
  
  rule(:productCore) { access >>
                            (exp      >> ws >> product |
                             star     >> ws >> access  |
                             slash    >> ws >> access  ).repeat(0) }
  
  rule(:access) {  ((ident_core >> str('&') >> !match('[&=]') >> _) | # special case: blah& is always a reference. blah & blih is a binary and.
                       value) >>
                        ((_ >> str('[') >> expr >>
                          (str(',') >> ws >> expr >> _).repeat(0) >> _ >> str(']') >> _)    |
                        _ >> functionCall                                                   |
                        _ >> ident_core                                                     |
                        _ >> as_kw >> _ >> type                                             |
                        str('&') >> (!match('[&=]') >> _ >> match('&([ \t\r\n;,)}]') | ']') |
                        str('@')                                                            |
                        _ >> functionCallNoname                                             ).repeat(0) >> _ }
  
  rule(:functionCall) { ident >> functionCallCore }
  
  rule(:functionCallCore) { (b_not >> _ >> ident).maybe >> str('(') >> ws >> (expr | acs) >> (ws >> str(',') >> ws >> (expr | acs).repeat(0)).maybe >> ws >> str(')') }
  
  rule(:functionCallNoname) { functionCallCore }
  
  rule(:acs) { str('|') >> ws.maybe >> (ident >> (ws >> str(',') >> ws).maybe).repeat(0) >> str('|') >> ws >> (stmt).repeat(0) }

  rule(:variableAccess) { ident_core }

  rule(:value  ) { (str('-') >> _ >> str('(') >> ws >> expr >> ws >> str(')') >> _)                 |
                   (str('-') >> _  >> valueCore)                                                       |
                   (str('(') >> ws >> expr >> ws >> str(')') >> (str('&') >> !match('[&=]')).maybe >> _) |
                   valueCore }
  
  rule(:arrayLiteral) { str('[') >> ws >> (
                                    expr >>
                       ((ws >> str(',') | eol) >> ws >> expr).repeat(0) >>
                       (ws >> str(',') >> ws).maybe
                       ).maybe >> ws >> str(']') }
  
  rule(:tuple       ) { str('(') >> ws >> (expr >> ((ws >> str(',') | eol) >> ws >> expr).repeat(0)).maybe >> ws >> str(')') }
end
