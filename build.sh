#!/usr/bin/env bash

set -e

ID=$1

if [ -z "$ID" ]; then
  echo "Usage: ./build.sh <leetcode_id>"
  exit 1
fi

BUILD_DIR=build/$ID

mkdir -p $BUILD_DIR
cd $BUILD_DIR

cmake ../.. -DPROBLEM_ID=$ID
cmake --build .

GTEST_COLOR=1 ctest --output-on-failure