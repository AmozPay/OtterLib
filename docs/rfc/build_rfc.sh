#!/bin/bash
docker build -t rfc_builder .
container="$(docker run -it --rm -d rfc_builder)"
docker cp "$container:/root/rfc.html" .
docker container stop -t 0 "$container"