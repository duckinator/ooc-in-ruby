class OocParser
rule(:interfaceDecl) {
         (
            oocDoc.as(:doc) >>

            ident.as(:interfaceName) >>
            _ >> colon >>

            _ >> interface_kw >>

            genericArguments.maybe >>

            # extending another interface
            (_ >> extends_kw >> _ >> type.as(:t)).maybe >>

            # interface subclassing
            (
              _ >> implements_kw >>
                       _ >> type.as(:t)
              (_ >> str(',') >> _ >> type.as(:t)).repeat(0)
            ).maybe >>

            # body is required for interfaces
            (
                ws >> str('{') >> ws >>

                # interface content
                (ws >>
                    functionDecl.as(:fd) >>
                ws).repeat(0) >>

                ws >> '}'
            )
          )
}

end
