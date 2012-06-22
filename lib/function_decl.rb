class OocParser
rule(:functionDecl) { superFunctionDecl | regularFunctionDecl }

rule(:superFunctionDecl) {
            ident.as(:name) >> _ >> colon >> _ >> str('super') >> _ >> func_kw >> _ >>
            # optional suffix
            (_ >> str('~') >> ident.as(:suffix)).maybe
}

rule(:regularFunctionDecl) {
            oocDoc.as(:doc) >>

            ident.as(:name) >>
            _ >> colon >>

            # modifiers
            (_ >> ( externName.as(:externName) >>
                    unmangledName.as(:unmangledName) >>
                    ABSTRACT_KW |
                    STATIC_KW   |
                    INLINE_KW   |
                    FINAL_KW    |
                    PROTO_KW
                  )
            ).repeat(0) >>

            functionDeclCore
}

rule(:anonymousFunctionDecl) { functionDeclCore }

rule(:functionDeclCore) {
            _ >> func_kw >>
            str('@').maybe >>

            # optional suffix
            (_ >> str('~') >> ident.as(:suffix)).maybe >>

            functionDeclBody
}

rule(:FunctionDeclBody) {
          (
            genericArguments.maybe >>

            # arguments are optional
            (
                ws >> str('(') >>
                (          ws >> argument >> ws >>
                    (str(',') >> ws >> argument >> ws).repeat(0)
                ).maybe >>
                ws >> ')'
            ).maybe >>
            
            # optional suffix
            (_ >> str('~') >> ident.as(:suffix)).maybe >>

            # return type is optional
            (
                _ >> r_arrow >>
                _ >> type.as(:t)
            ).maybe >>

            # body is optional (for abstract/extern-named functions)
            (
                ws >> str('{') >> ws >>
                (ws >>
                stmt.as(:s) >>
                ws).repeat(0) >>
                ws >> '}'
            ).maybe
          )
}

rule(:argument) {
              ( (dot >> ident.as(:dotName) >> _) |
                (ass >> ident.as(:assName) >> _) |
                variableDecl.as(:vd)             |
                (ident.as(:vargName) >> _ >> str(':') >> _ >> str("...") >> _) |
                type.as(:type)                   |
                str("...")
              )
}
end
