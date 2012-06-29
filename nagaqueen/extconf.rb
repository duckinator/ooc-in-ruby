#!/usr/bin/env ruby

require 'mkmf'

$CFLAGS='-std=c99 -ggdb'

create_makefile('nagaqueen')

