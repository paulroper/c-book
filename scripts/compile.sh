#!/usr/bin/sh
set -e

mkdir ./bin 2> /dev/null || true
echo "Compiling C files into separate executables..."

for f in $(find . -name '*.c')
do
  echo ""
  echo "Compiling $f..."
  echo ""

  binary_name="./bin/$(basename $f | sed -e 's/\.c//g')"
  clang $f -Weverything -o $binary_name

  echo ""
  echo "$f done! Executable can be found at $binary_name"
done

