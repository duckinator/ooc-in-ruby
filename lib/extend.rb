class OocParser
rule(:extendDecl) {
           (
            oocDoc.as(:doc).maybe >>

            str("extend") >> ws >>
            type.as(:extendedType)

            # body
              (
                ws >> str('{') >> ws >>
                # coverdecl content
                (ws >> :FunctionDecl.as(:fd) >> ws).repeat(0)
                ws >> str('}')
              )
           )
}
end
