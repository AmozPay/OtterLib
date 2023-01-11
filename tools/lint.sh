#!/bin/sh

set -euf
echo "Linting OtterLib source code"
find OtterLib -iname "*.cpp" -o -iname "*.hpp" | xargs clang-format -i
echo "Linting games source code"
find games -iname "*.cpp" -o -iname "*.hpp" | xargs clang-format -i