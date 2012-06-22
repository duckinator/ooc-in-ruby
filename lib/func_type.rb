class OocParser

rule(:funcTypeCore) { str("Func") >> match('[^A-Za-z0-9_]') }

rule(:funcType) {
          funcTypeCore.as(:funcType) >>
            (_ >> str('<') >> _ >> ident.as(:genType) >>
             (_ >> str(',') >> _ >> ident.as(:genType)).repeat(0) >>
             _ >> str('>')
            ).maybe >>
            (
              _ >> str('(') >>
              (
                _ >> type.as(:argType) >>
                (str(',') >> _ >> type.as(:argType)).repeat(0)
              ).maybe >>
              (str("...") >> _).maybe >>
              _ >> str(')')
            ).maybe >>
            (_ >> str('->')
             _ >> type.as(:returnType)
            ).maybe
}

end
