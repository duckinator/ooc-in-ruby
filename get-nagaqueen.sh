#!/bin/bash

DIR=$(dirname $(readlink -f $0))

if [ -z "$ROCK_DIST" ]; then
  if [ -d "../rock" ]; then
    ROCK_DIST="../rock"
  elif [ -d "$DIR/rock" ]; then
    ROCK_DIST="$DIR/rock"
  else
    echo "ERROR: Could not find rock source."
    echo "Try \`ROCK_DIST=/path/to/rock/ $0\`"
    echo "If you don't have rock, see: https://github.com/nddrylliog/rock"
    exit 1
  fi
fi

cd $DIR
cp $ROCK_DIST/source/rock/frontend/NagaQueen.c ./nagaqueen/nagaqueen.h

sed -i -r 's|(void\|char) .*nq_|//\0|g' ./nagaqueen/nagaqueen.h


# Why is it .h? Because I don't want to fight extconf.rb
