#!/bin/bash

DIR=$(dirname $(readlink -f $0))

FILE=$DIR/lib/nagaqueen-methods.rb

echo "
# This is the accompanying module for what's created in
# Init_nagaqueen() in ruby_nagaqueen.c.
#
# Unfortunately, nagaqueen seems biased towards rock (self-hosting ooc compiler),
# and this leads to most functions explicitly passing 'this'/'self',
# so instead of mutilating nagaqueen.c I simply called it _.
#
# I recommend not referencing _ at all. It seems to result in a segfault of the
# ruby interpreter. Yay!
" > $FILE

echo 'module Nagaqueen' >> $FILE
echo '  class << self' >> $FILE

cat nagaqueen/boilerplate.h |grep -E '^[a-z]' | sed 's/ \* /\* /' | cut -d' ' -f2- | sed 's/^ //' | sed 's/void\* self/_/' | sed -r 's/(void\*|char\*|char|int\*|int|bool|_Bool) //g' | sed 's/nq_//' | sed 's/^/    def /' | sed 's/$/\n    end\n/' >> $FILE

echo '  end' >> $FILE
echo 'end' >> $FILE
