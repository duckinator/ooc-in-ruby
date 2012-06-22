class OocParser
rule(:decl) {
          ( classDecl     |
            coverDecl     |
            extendDecl    |
            enumDecl      |
            interfaceDecl |
            operatorDecl  |
            functionDecl  |
            propertyDecl  |
            variableDecl.as(:vd) >> terminator.repeat(1)
          ) }

rule(:genericArguments) {
            (
            _ >> lessthan >>
            _ >> ident.as(:name) >>
            (_ >> ',' >> _ >> ident.as(:name)).repeat(0) >>
            morethan >> _
            ) }

rule(:operatorDecl) {
            operator_kw >> _ >>
            _ >> ( str("=>")  | str("<=>") | str(">>=") | str("<<=") | str(">>") | str("<<") |
                  str(">=")  | str("<=")  | str("!=")  | str("==")  | str(">")  | str("<")  | str("!") |
                  str("+=")  | str("-=")  | str("*=")  | str("**=") | str("/=") | str("+")  | str("-") | str("**") | str("/") | str("*") | str("=") |
                  str("[]=") | str("[]")  | str("&&")  | str("||")  | str("%")  | str("as") | str("implicit as") |
                  str("&=")  | str("|=")  | str("^=")  | str("&")   | str("|")  | str("^")  | str("~")
                ) >>
            _ >> functionDeclBody }
end
