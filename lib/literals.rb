class OocParser
  rule(:digit)   { match('[0-9]') }
  rule(:digit_underscore) { match('[0-9_]') }
  rule(:number)  { digit.maybe >> digit_underscore.repeat(0) }
  
  rule(:oct_lit)   { str("0c") >> match('[0-8]') >> match('[0-8_]').repeat(0) }
  rule(:bin_lit)   { str("0b") >> match('[01]')  >> match('[01_]').repeat(0)  }
  rule(:hex_lit)   { str("0x") >> match('[0-9a-fA-F]') >> match('[0-9a-fA-F_]').repeat(0) }
  rule(:float_lit) { str("-").maybe >> number >> dot >> number >> hyphen }
  rule(:dec_lit)   { str("-").maybe >> number >> hyphen }
  
  rule(:ident)      { indent_core >> hyphen }
  rule(:ident_core) { !(kw !match('[A-Za-z0-9_]')) >> match('[a-zA-Z_][0-9a-zA-Z_]').repeat(0) >> (str('?') | str('!')).maybe }
                 
  rule(:single_quote) { str('\'') }
  rule(:double_quote) { str('"')  }
  
  rule(:hex_escape)   { str("\\x") >> match('[0-9A-Za-z][0-9A-Za-z]([0-9A-Za-z][0-9A-Za-z])?') }
  rule(:octal_escape) { str("\\")  >> match('[0-9][0-9]?[0-9]?') }
  rule(:other_escape) { str("\\")  >> match('["\'abtnvfr0\\]')   }
  
  rule(:string_lit) { str('"') >> (!str('"') | (hex_escape | octal_escape | other_escape) | eol).repeat(1) >> str('"') }
  rule(:char_lit)   { str("'") >> (!str("'") | (hex_escape | octal_escape | other_escape) | eol).repeat(1) >> str("'") }
  rule(:bool_lit)   { ((true_kw >> match('[^A-Za-z_]')) | (false_kw >> match('[^A-Za-z_]'))) >> hyphen }

  rule(:intLiteral)  { oct_lit | hex_lit | dec_lit }

  rule(:valueCore) { oct_lit | hex_lit | bin_lit | float_lit | dec_lit | string_lit | char_lit | bool_lit |
                     match | (null_kw >> match('&[^A-Za-z_]') >> hyphen) | arrayLiteral | tuple | functionCall |
                     genericType | variableAccess }
end
