class OocParser
  rule(:flowControl) { foreach | while_ | break_ | continue }
  
  rule(:break_)      { break_kw }
  rule(:continue)    { continue_kw }
  
  rule(:implicitDecl) { variableDecl | ident }
  
  rule(:foreach) { for_kw >> ws >> str('(') >> ws >> _ >> implicitDecl >> _ >> in_kw >> expr >> ws >> str(')') >> _ >> body >> _ }
  
  rule(:while) { while_kw >> ws >> str('(') >> ws >> _ >> expr >> str(')') >> _ >> body >> _ }

  rule(:body) { ('{' >> (ws >> stmt >> ws).repeat(0) >> ws >> str('}')) | stmt }

  rule(:return_) { (return_kw >> expr >> _) | (return_kw >> _) }

  rule(:expr) { (variableDecl >> _) | (doubleArrow >> _) |
                (binaryOperation >> _ >> (_ >> str('.') >> ws >> functionCall).repeat(0)) |
                anonymousFunctionDecl }

  rule(:caseExpr) { ((variableDec >> _) | (binaryOperation >> _ >> (_ >> str('.') >> ws >> functionCall).repeat(0)) | anonymousFunctionDecl) |
                    ('(') >> _ >> expr >> _ >> str(')') }

  rule(:doubleArrow) { assignment >> double_arrow >> ws >> expr }
end
