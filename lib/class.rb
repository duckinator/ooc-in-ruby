class OocParser
rule(:classDecl) {
          (
            oocDoc.as(:doc) >>

            ident.as(:className) >>
            _ >> colon >>

            # modifiers
            (_ >> ( externName  |
                    abstract_kw |
                    final_kw
                  )
            ).repeat(0) >>

            _ >> class_kw >>

            genericArguments.maybe >>

            # subclassing
            (_ >> extends_Kw >> _ >> type.as(:t)).maybe >>

            # interface subclassing
            (
              _ >> implements_kw >>
                     _ >> type.as(:t) >>
              (_ >> str(',') >> _ >> type.as(:t)).repeat(0)
            ).maybe >>

            (
                ws >> str('{') >> ws >>

                # classdecl contents
                (ws >>
                    ( variableDecl.as(:vd) >> terminator.repeat(1)  |
                      propertyDecl.as(:pd) |
                      functionDecl.as(:fd) |
                      stmt.as(:stmt)
                    ) >>
                ws).repeat(0) >>

                ws >> str('}')
            )
          )
}
end
