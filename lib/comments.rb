class OocParser
  rule(:oocDoc) { oocDocLine | oocDocMultiline }

  rule(:oocDocLine)      { str("///") >> !str('/') >> (!eol).repeat >> eol }
  rule(:oocDocMultiLine) { str("/**") >> !str("*/") >> str("*/") }

  rule(:comment)          { commentLine | commentMultiLine }
  rule(:commentLine)      { str("//") >> !str('/') >> (!eol).repeat >> eol }
  rule(:commentMultiLine) { str("/*") >> !str("*/") >> str("*/") }
end
