#!/bin/bash

# bash setup
set -x
set -e

n_max="200"
rounds="5"

rm -rf results
mkdir results
cd results
./../../dependencies/DUNE/release-build/dune-evaluation/src/dune-evaluation $n_max $rounds
./../ginkgo/build/gko-evaluate-solvers $n_max $rounds

