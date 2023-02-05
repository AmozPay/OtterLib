#!/bin/sh
./generate_docs.sh
cd .retype
npx http-server
