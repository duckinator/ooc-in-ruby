#!/usr/bin/env ruby

if ARGV.include?('--help') || ARGV.include?('-h')
  puts "Usage: ./build.rb [MAKE_EXECUTABLE]"
  exit
end


dir = File.expand_path(File.dirname(__FILE__))

Dir.chdir(File.join(dir, 'nagaqueen'))

require './extconf.rb'

make = ARGV[0] || 'make'

`#{make} nagaqueen.so`

