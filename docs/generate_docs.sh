#!/bin/sh
export OTTERLIB_VERSION=$(git symbolic-ref -q --short HEAD || git describe --tags --exact-match)
echo $OTTERLIB_VERSION
doxygen Doxyfile