class OocParser
rule(:externName) {
             extern_kw >>
              (
              _ >> str('(') >>
              _ >> match('[A-Za-z_]') >> match('[A-Za-z0-9_]').repeat(0) >>
              _ >> str(')')
              ).maybe
}

rule(:unmangledName) {
            unmangled_kw >>
             (
             _ >> str('(') >>
             _ >> ident.as(:unmangledName) >>
             _ >> str(')')
             ).maybe
}
end
