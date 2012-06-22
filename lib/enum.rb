class OocParser
rule(:enumDecl) {
          (
            oocDoc.as(:doc) >>

            ident.as(:enumName) >>
            _ >> colon >>

            # modifiers (extern)
            (_ >> externName.as(:externName)).maybe >>

            _ >> enum_kw >>

            # optional from-type
            (_ >> from_kw >> _ >> type.as(:fromType)).maybe >>

            # increment expression (ex: *2 or +1)
            (
            _ >> str('(') >>
            _ >> enumIncrementOper.as(:op) >> ws >> intLiteral.as(:step) >>
            _ >> str(')')
            ).maybe >>

            (
                ws >> str('{') >> ws >>

                # enumeration elements
                (enumElement >>
                (
                    (terminator.repeat(1) >> ws >> functionDecl) |
                    ((str(',') | terminator.repeat(1)) >> ws >> enumElement)
                ).repeat(0)
                ).maybe >>

                ws >> str('}')
            )

          )
}

rule(:enumElement) {
            (
                oocDoc.as(:doc) >>

                ident.as(:i) >>
                _ >> ( ass >> expr.as(:value) |
                       colon >>
                     _ >> externName.as(:externName)
                  ).maybe
            )
}

rule(:enumIncrementOper) { star | plus }

end
