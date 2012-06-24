#!/usr/bin/env ruby

dir = File.expand_path(File.dirname(__FILE__))

require 'pp'
require File.join(File.expand_path(File.dirname(__FILE__)), 'nagaqueen')

class Nagaqueen
  # Insert insanity here.
end

nq = Nagaqueen.new(File.join(dir, '..', 'test', 'test.ooc'))

