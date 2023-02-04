#!/bin/sh
export OTTERLIB_VERSION=$(git symbolic-ref -q --short HEAD || git describe --tags --exact-match)
echo $OTTERLIB_VERSION
doxygen Doxyfile
rm -rf .retype
mkdir .retype
mv html .retype/api-reference
yarn && yarn retype build