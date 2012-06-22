class OocParser
   rule(:dot          ) { !double_dot >> str('.') }
   rule(:colon        ) { !ass_decl >> str(':') }
 
   rule(:r_arrow      ) { str('->') }
   rule(:double_arrow ) { str('=>') }
 
   # operators
 
   rule(:ass_decl     ) { str(':=')  >> hyphen }
   rule(:ass          ) { !double_arrow >> str(':=') >> hyphen }
   rule(:ass_add      ) { str('+=')  >> hyphen }
   rule(:ass_sub      ) { str('-=')  >> hyphen }
   rule(:ass_exp      ) { str('**=')  >> hyphen }
   rule(:ass_mul      ) { str('*=')  >> hyphen }
   rule(:ass_div      ) { str('/=')  >> hyphen }
   rule(:ass_b_rshift ) { str('>>=')  >> hyphen }
   rule(:ass_b_lshift ) { str('<<=')  >> hyphen }
   rule(:ass_b_xor    ) { str('^=')  >> hyphen }
   rule(:ass_b_or     ) { str('|=')  >> hyphen }
   rule(:ass_b_and    ) { str('&=')  >> hyphen }
 
   rule(:quest        ) { str('?')   >> hyphen }
 
   rule(:l_or         ) { str('||')  >> hyphen }
 
   rule(:l_and        ) { str('&&')  >> hyphen }
 
   rule(:b_or         ) { !l_or >> str('|') >> !str('=') >> hyphen }
 
   rule(:b_xor        ) { str('^') >> !str('=') >> hyphen }
 
   rule(:b_and        ) { !l_and >> str('&') >> !str('=') >> hyphen }
 
   rule(:equals       ) { str('==') >> hyphen }
   rule(:not_equals   ) { str('!=') >> hyphen }
 
   rule(:lessthan     ) { str('<')   >> !str('=') >> hyphen }
   rule(:morethan     ) { str('>')   >> !str('=') >> hyphen }
   rule(:cmp          ) { str('<=>') >> hyphen }
   rule(:lessthan_eq  ) { str('<=')  >> hyphen }
   rule(:morethan_eq  ) { str('>=')  >> hyphen }
 
   rule(:b_lshift     ) { str('<<') >> !str('=') >> hyphen }
   rule(:b_rshift     ) { str('>>') >> !str('=') >> hyphen }
 
   rule(:double_dot   ) { str('..') >> hyphen }
 
   rule(:l_not        ) { str('!') >> !str('=')  >> hyphen }
   rule(:b_not        ) { str('~') >> !str('=')  >> hyphen }
   rule(:plus         ) { str('+') >> !str('=')   >> hyphen }
   rule(:minus        ) { str('-') >> !str('=')  >> hyphen }
 
   rule(:percent      ) { str('%')  >> !str('=')  >> hyphen }
   rule(:exp          ) { str('**') >> !str('=')  >> hyphen }
   rule(:star         ) { str('*')  >> !str('=')  >> hyphen }
   rule(:slash        ) { str('/')  >> !str('=')  >> !match('[/*]') >> hyphen }
 
   rule(:clos_brack    ) { str('}') }
   rule(:clos_squar    ) { str(']') }
   rule(:clos_paren    ) { str(')') }
   rule(:clos_comment  ) { str('*/') }
end
