#!/usr/bin/env ruby

require 'mkmf'

$CFLAGS='-std=c99'

create_makefile('nagaqueen')

