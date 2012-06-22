class OocParser
  rule(:dot          ) { !double_dot >> str('.') }
  rule(:colon        ) { !ass_decl   >> str(':') }

  rule(:r_arrow      ) { str('->') }
  rule(:double_arrow ) { str('=>') }

  # operators

  rule(:ass_decl     ) { str(':=')   >> _ }
  rule(:ass          ) { !double_arrow >> str(':=') >> _ }
  rule(:ass_add      ) { str('+=')   >> _ }
  rule(:ass_sub      ) { str('-=')   >> _ }
  rule(:ass_exp      ) { str('**=')  >> _ }
  rule(:ass_mul      ) { str('*=')   >> _ }
  rule(:ass_div      ) { str('/=')   >> _ }
  rule(:ass_b_rshift ) { str('>>=')  >> _ }
  rule(:ass_b_lshift ) { str('<<=')  >> _ }
  rule(:ass_b_xor    ) { str('^=')   >> _ }
  rule(:ass_b_or     ) { str('|=')   >> _ }
  rule(:ass_b_and    ) { str('&=')   >> _ }

  rule(:quest        ) { str('?')   >> _ }

  rule(:l_or         ) { str('||')  >> _ }
  rule(:l_and        ) { str('&&')  >> _ }

  rule(:b_or         ) { !l_or  >> str('|') >> !str('=') >> _ }
  rule(:b_and        ) { !l_and >> str('&') >> !str('=') >> _ }
  rule(:b_xor        ) { str('^') >> !str('=') >> _ }

  rule(:equals       ) { str('==') >> _ }
  rule(:not_equals   ) { str('!=') >> _ }

  rule(:lessthan     ) { str('<')   >> !str('=') >> _ }
  rule(:morethan     ) { str('>')   >> !str('=') >> _ }
  rule(:cmp          ) { str('<=>') >> _ }
  rule(:lessthan_eq  ) { str('<=')  >> _ }
  rule(:morethan_eq  ) { str('>=')  >> _ }

  rule(:b_lshift     ) { str('<<') >> !str('=') >> _ }
  rule(:b_rshift     ) { str('>>') >> !str('=') >> _ }

  rule(:double_dot   ) { str('..') >> _ }

  rule(:l_not        ) { str('!')  >> !str('=')  >> _ }
  rule(:b_not        ) { str('~')  >> !str('=')  >> _ }
  rule(:plus         ) { str('+')  >> !str('=')  >> _ }
  rule(:minus        ) { str('-')  >> !str('=')  >> _ }

  rule(:percent      ) { str('%')  >> !str('=')  >> _ }
  rule(:exp          ) { str('**') >> !str('=')  >> _ }
  rule(:star         ) { str('*')  >> !str('=')  >> _ }
  rule(:slash        ) { str('/')  >> !match('[=/*]') >> _ }

  rule(:clos_brack    ) { str('}')  }
  rule(:clos_squar    ) { str(']')  }
  rule(:clos_paren    ) { str(')')  }
  rule(:clos_comment  ) { str('*/') }
end
