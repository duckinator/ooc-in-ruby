class OocParser
  rule(:flowControl) { foreach | while_ | break_ | continue }
  
  rule(:break_)      { break_kw }
  rule(:continue)    { continue_kw }
  
  rule(:implicitDecl) { variableDecl | ident }
  
  rule(:foreach) { for_kw >> ws >> str('(') >> ws >> hyphen >> implicitDecl >> hyphen >> in_kw >> expr >> ws >> str(')') >> hyphen >> body >> hyphen }
  
  rule(:while) { while_kw >> ws >> str('(') >> ws >> hyphen >> expr >> str(')') >> hyphen >> body >> hyphen }

  rule(:body) { ('{' >> (ws >> stmt >> ws).repeat(0) >> ws >> str('}')) | stmt }

  rule(:return_) { (return_kw >> expr >> hyphen) | (return_kw >> hyphen) }

  rule(:expr) { (variableDecl >> hyphen) | (doubleArrow >> hyphen) |
                (binaryOperation >> hyphen >> (hyphen >> str('.') >> ws >> functionCall).repeat(0)) |
                anonymousFunctionDecl }

  rule(:caseExpr) { ((variableDec >> hyphen) | (binaryOperation >> hyphen >> (hyphen >> str('.') >> ws >> functionCall).repeat(0)) | anonymousFunctionDecl) |
                    ('(') >> hyphen >> expr >> hyphen >> str(')') }

  rule(:doubleArrow) { assignment >> double_arrow >> ws >> expr }
end
