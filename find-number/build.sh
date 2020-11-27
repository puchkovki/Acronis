#!/bin/bash
FULLDIR=$(dirname "$0")
g++ -Wall -Wextra -pedantic -std=c++17 -O3 -Wshadow -Wformat=2 -Wfloat-equal \
-Wconversion -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC \
-fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fstack-protector \
-o $FULLDIR/test $FULLDIR/solution.cpp || exit 1
$FULLDIR/test
exit $?