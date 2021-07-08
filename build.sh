#!/usr/bin/sh

rm -rf build || true
cd src
make build_dir && make

