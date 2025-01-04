#!/bin/bash
# bash setup
set -x
set -e

spack env activate gcc-13
cp ../../resources/dune-evaluation.cc ./dune-evaluation/src

ROOT=$(pwd)
BUILDDIR=$ROOT/release-build
OPTSFILE=release.opts
MODULES="common istl evaluation "
for i in $MODULES; do
    echo build $i
    ./dune-common/bin/dunecontrol --builddir=$BUILDDIR  --opts=$OPTSFILE --only=dune-$i all
done

#echo "testing with 3 1 row_wise"
#./release-build/dune-evaluation/src/dune-evaluation 3 1 row_wise

