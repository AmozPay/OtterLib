#!/bin/sh
export OTTERLIB_VERSION=$(git symbolic-ref -q --short HEAD || git describe --tags --exact-match)
echo $OTTERLIB_VERSION
(
    cd doxygen/doxygen-awesome-css
    git checkout v2.1.0
)
(
    cd doxygen
    doxygen Doxyfile
)
(
    cd rfc
    ./build_rfc.sh
)
rm -rf .retype
mkdir -p .retype/rfc
mv html .retype/api-reference
mv rfc/rfc.html .retype/rfc/index.html

yarn && yarn retype build retype.prod.yml
