#!/usr/bin/env ruby

dir = File.expand_path(File.dirname(__FILE__))

require File.join(dir, 'lib', 'ooc')

nq = Nagaqueen.parse(File.join(dir, 'test', 'test.ooc'))
p nq
