require 'parslet'

class OocParser < Parslet::Parser
  rule(:hyphen)     { (match('[ \t]') | commentMultiLine).repeat(1) }
  rule(:eol)        { match('\n|\r\n|\r') }
  rule(:terminator) { commentLine | (commentMultiLine.maybe (eol | ';')) }
  rule(:ws) { (match('[ \t]') | comment | eol).repeat(0) }

  %w[symbols keywords comments literals flowcontrol operators statement misc].each do |file|
    load File.join(File.dirname(__FILE__), file + '.rb')
  end

  #rule(:expression) {  }
  #root :expression
  rule(:fail) { str('') }
  root :fail
end
