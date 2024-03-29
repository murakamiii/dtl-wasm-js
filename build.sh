#!/bin/bash

set -e

export OPTIMIZE="-Os"
export LDFLAGS="${OPTIMIZE}"
export CFLAGS="${OPTIMIZE}"
export CXXFLAGS="${OPTIMIZE}"

echo "============================================="
echo "Compiling wasm bindings"
echo "============================================="
(
  emcc \
    ${OPTIMIZE} \
    --bind \
    -s EXIT_RUNTIME=1 \
    -s STRICT=1 \
    -s ALLOW_MEMORY_GROWTH=1 \
    -o dtl.js \
    src/bind.cpp

  # Create output folder
  mkdir -p dist
  # Move artifacts
  mv dtl.{js,wasm} dist
)
echo "============================================="
echo "Compiling wasm bindings done"
    # -s MODULARIZE=1 \
    # -s EXPORT_ES6=1 \