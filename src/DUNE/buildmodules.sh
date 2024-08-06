#!/bin/bash
ROOT=$(pwd)
BUILDDIR=$ROOT/release-build
OPTSFILE=release.opts
MODULES="common istl "
for i in $MODULES; do
    echo build $i
    ./dune-common/bin/dunecontrol --builddir=$BUILDDIR  --opts=$OPTSFILE --only=dune-$i all
done

