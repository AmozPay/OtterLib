#!/bin/sh
echo "Linting source code"
find . -iname "*.cpp" -o -iname "*.hpp" | xargs clang-format -i