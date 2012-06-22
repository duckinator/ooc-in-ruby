class OocParser
  rule(:break_kw     ) { "break" }
  rule(:continue_kw  ) { "continue" }
  rule(:return_kw    ) { "return" }

  rule(:func_kw      ) { "func" }
  rule(:class_kw     ) { "class" }
  rule(:cover_kw     ) { "cover" }
  rule(:enum_kw      ) { "enum" }
  rule(:interface_kw ) { "interface" }
  rule(:from_kw      ) { "from" }
  rule(:abstract_kw  ) { "abstract" }
  rule(:final_kw     ) { "final" }
  rule(:static_kw    ) { "static" }
  rule(:inline_kw    ) { "inline" }
  rule(:extends_kw   ) { "extends" }
  rule(:extern_kw    ) { "extern" }
  rule(:unmangled_kw ) { "unmangled" }
  rule(:implements_kw) { "implements" }

  rule(:import_kw    ) { "import" }
  rule(:include_kw   ) { "include" }
  rule(:use_kw       ) { "use" }
  rule(:if_kw        ) { "if" }
  rule(:else_kw      ) { "else" }
  rule(:for_kw       ) { "for" }
  rule(:while_kw     ) { "while" }
  rule(:match_kw     ) { "match" }
  rule(:case_kw      ) { "case" }
  rule(:as_kw        ) { "as" }
  rule(:in_kw        ) { "in" }
  rule(:into_kw      ) { "into" }
  rule(:proto_kw     ) { "proto" }
  rule(:try_kw       ) { "try" }
  rule(:catch_kw     ) { "catch" }

  rule(:set_kw       ) { "set" }
  rule(:get_kw       ) { "get" }

  rule(:operator_kw  ) { "operator" }
  rule(:const_kw     ) { "const" }

  rule(:true_kw      ) { "true" }
  rule(:false_kw     ) { "false" }

  rule(:null_kw      ) { "null" }

  rule(:keyword) { break_kw | continue_kw | return_kw | func_kw |
                   covwer_kw | enum_kw | from_kw | abstract_kw | final_kw |
                   static_kw | inline_kw | extends_kw | extern_kw | unmangled_kw |
                   import_kw | include_kw | if_kw | else_kw | for_kw |
                   while_kw | as_kw | operator_kw | const_kw | null_kw | match_kw | case_kw |
                   try_kw | catch_kw }
end
