class OocParser
rule(:import) { import_kw >> match('[ \t]') >> _ >> importAtom >> (str(',') >> ws >> _ >> importAtom).repeat(0) }

rule(:importAtom) { importPath.as(:path) >>
                    ((importName.as(:name) >>
                      (_ into_kw >> _ >> ident.as(:namespace)).maybe
                     ) | (
                     str('[') >>
                     (importName.as(:name) >> _ >> str(',') >> ws).repeat(0) >>
                     importName.as(:name) >> str(']') >>
                     (_ into_keyword >> ident.as(:namespace)).maybe
                    )) }

rule(:importPath) { ((match('[A-Za-z_0-9]') | str(".") | str("-")).repeat(1) >> str("/")).repeat(0) }
rule(:importName) { (match('[A-Za-z_0-9]') | str("-")).repeat(1) }
end
