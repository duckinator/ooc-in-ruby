#!/usr/bin/env ruby

require 'pp'

require File.join(File.dirname(__FILE__), 'lib', 'parser.rb')

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
