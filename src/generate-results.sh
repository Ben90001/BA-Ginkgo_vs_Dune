#!/bin/bash

# bash setup
set -x
set -e
#Notes for current run: yet to generate: all gpu data
n_lowerBound="1"
n_upperBound="400"
rounds="4"
interval="1"

#ISTL
#buildModes=("implicit" "row_wise")
buildModes=("row_wise")

#GINKGO
#devices=("gpu" "cpu")
devices=("cpu")
#executors=("ref" "cuda")
executors=("ref")
mtx_formats=("csr")
#mtx_formats=("csr" "coo" "ell")

rm -rf results
mkdir results
cd results
# Create a log file
log_file="execution_log.txt"
echo "Script execution started at: $(date)" > $log_file

# generate data -------------------------------------------------------------------------------------------------------
for buildMode in "${buildModes[@]}"; do
    ./../../dependencies/DUNE/release-build/dune-evaluation/src/dune-evaluation $n_upperBound $rounds $buildMode
    echo "Finished ISTL with buildMode $buildMode at       $(date)" >> $log_file
done

for executor in "${executors[@]}"; do
    for device in "${devices[@]}"; do
        for mtx_format in "${mtx_formats[@]}"; do
            #./../ginkgo/build/ginkgo-evaluation $n_lowerBound $n_upperBound $rounds $interval $device $executor $mtx_format
            echo "Finished with executor: $executor, matrix format: $mtx_format at      $(date)" >> $log_file
        done
    done
done
# ---------------------------------------------------------------------------------------------------------------------

echo "Script execution ended at: $(date)" >> $log_file
