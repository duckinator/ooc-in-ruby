require 'parslet'

class OocParser < Parslet::Parser
  rule(:_)     { (match('[ \t]') | commentMultiLine).repeat(1) }
  rule(:eol)        { match('\n|\r\n|\r') }
  rule(:terminator) { commentLine | (commentMultiLine.maybe (eol | str(';'))) }
  rule(:ws) { (match('[ \t]') | comment | eol).repeat(0) }

  Dir[File.join(File.dirname(__FILE__), '*.rb')].each do |file|
    load file unless file == __FILE__
  end

  #rule(:expression) {  }
  #root :expression
  rule(:fail) { str('') }
  root :fail
end

