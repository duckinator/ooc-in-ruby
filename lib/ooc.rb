#!/usr/bin/env ruby

dir = File.expand_path(File.dirname(__FILE__))

require 'pp'
require File.join(File.expand_path(File.dirname(__FILE__)), 'nagaqueen')

# Once all the types in nagaqueen/boilerplate.h are handled properly,
# the following will generate a list of functions to define for the Nagaqueen class:
#   cat nagaqueen/boilerplate.h |grep -E "^[a-z]" | sed 's/ \* /\* /' | cut -d' ' -f2- | sed 's/^ //' | sed 's/VALUE self, //'
class Nagaqueen
  attr_accessor :ast, :filename

  def initialize(filename)
    @ast = nil
    @filename = filename
  end

#  def setTokenPositionPointer(tokenPos)
#    p tokenPos
#  end
end

nq = Nagaqueen.new(File.join(dir, '..', 'test', 'test.ooc'))
nq.parse
