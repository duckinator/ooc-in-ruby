class OocParser
rule(:coverDecl) {
          (
            oocDoc.as(:doc).maybe >>

            ident.as(:coverName) >>
            ws >> colon >>

            # modifiers
            (_ >> externName.as(:externName)).maybe >>

            _ >> cover_kw >>

            genericArguments.maybe >>

            # covering another type
            (_ >> from_kw >> _ >> type.as(:t)).maybe >>

            # extending another type
            (_ >> extends_kw >> _ >> type.as(:t)).maybe >>

            # interface subclassing
            (
              _ >> implements_kw >>
                     _ >> type.as(:t)
              (_ >> str(',') >> _ >> type.as(:t)).repeat(0)
            ).maybe >>

            # body is optional for covers
            (
                ws >> str('{') >> ws >>

                # coverdecl content
                (ws >>
                    ( variableDecl.as(:vd) >> terminator.repeat(1) |
                      propertyDecl.as(:pd) |
                      functionDecl.as(:fd)
                    ) >>
                ws).repeat(0) >>

                ws >> '}'
            ).maybe
          )
}
end
