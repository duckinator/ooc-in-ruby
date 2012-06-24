#!/usr/bin/env ruby

dir = File.expand_path(File.dirname(__FILE__))

require File.join(File.expand_path(File.dirname(__FILE__)), 'nagaqueen')

# Once all the types in nagaqueen/boilerplate.h are handled properly,
# the following will generate a list of functions to define for the Nagaqueen class:
#   cat nagaqueen/boilerplate.h |grep -E "^[a-z]" | sed 's/ \* /\* /' | cut -d' ' -f2- | sed 's/^ //' | sed 's/VALUE self, //'

# This is the accompanying module for what's created in
# Init_nagaqueen() in ruby_nagaqueen.c.
#
# Unfortunately, nagaqueen seems biased towards rock (self-hosting ooc compiler),
# and this leads to most functions explicitly passing 'this'/'self',
# so instead of mutilating nagaqueen.c I simply called it _.
#
# I recommend not referencing _ at all. It seems to result in a segfault of the
# ruby interpreter. Yay!
module Nagaqueen
  class << self
    def ast
      @@ast
    end

    def filename
      @@filename
    end

    def parse(filename)
      @@ast = nil
      @@filename = filename
      _parse
    end
  end
end

require File.join(File.expand_path(File.dirname(__FILE__)), 'nagaqueen-methods')

