# ooc-in-ruby: ooc interpreter written primarily in ruby

...and a lot of automagically-generated C. The hell if I'm duplicating all of _that._

The idea is to write as much of it as possible in ruby.

I gave up writing a custom parser for now, so it uses nagaqueen.
Hellooooo, 9,350 SLOC of generated C, tied together with 33 SLOC of hand-written C.

Good news: this means I should be albe to get away with `./get-nagaqueen.sh && ./generate-boilerplate.rb` and coding some ruby any time nagaqueen changes.


# Building it

Here's all the files related to generating the shitton of C and compiling it all.

* `./get-nagaqueen.sh`: tries to find NagaQueen.c, copies it to ./nagaqueen/nagaqueen.c
* `./generate-boilerplate.rb`: generates approximately 960 lines of ruby/C interop boilerplate in ./nagaqueen/boilerplate.h
* `./build.rb`: builds this monstrous thing.


In most cases, all you should need is `./build.rb`.
