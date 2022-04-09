#!/bin/bash
assert() {
  expected="$1"
  input="$2"

  ./acc "$input" > tmp.s
  cc -o tmp tmp.s
  ./tmp
  actual="$?"

  if [ "$actual" = "$expected" ]; then
    echo "$input => $actual"
  else
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

assert 0 0
assert 42 42
assert 21 "5 + 20 - 4"
assert 23 "3 + 4 * 5"
assert 35 "(3+4) * 5"
assert 2 "8 / (2 + 2)"

echo OK
