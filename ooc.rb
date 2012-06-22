#!/usr/bin/env ruby

require 'parslet'
require 'pp'

class OocParser < Parslet::Parser
  rule(:hyphen)     { (match('[ \t]') | commentMultiLine).repeat(1) }
  rule(:eol)        { match('\n|\r\n|\r') }
  rule(:terminator) { commentLine | (commentMultiLine.maybe (eol | ';')) }
  rule(:ws) { (match('[ \t]') | comment | eol).repeat(0) }

  %w[symbols keywords comments literals flowcontrol operators statement misc].each do |file|
    load File.join(File.dirname(__FILE__), 'lib', file + '.rb')
  end

  #rule(:expression) {  }
  #root :expression
  rule(:fail) { str('') }
  root :fail
end

def test(str)
  mini = OocParser.new

  pp mini.parse(str)
  puts
rescue Parslet::ParseFailed => failure
  puts failure.cause.ascii_tree
end

test "a 2"
test "a := b"
test "a * 2"

exit

test "puts(1 + 2 + 3)"  # => "1 + 2 + 3"@0
test "1 + 2 + 3"  # => "1 + 2 + 3"@0
test "a + 2"      # fails, see below
