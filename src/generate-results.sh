#!/bin/bash

# bash setup
set -x
set -e
#Notes for current run: yet to generate: all gpu data
n_lowerBound="1"
n_upperBound="400"
rounds="4"
interval="1"
device="cpu"
executors="ref omp"
mtx_formats="csr coo ell"

rm -rf results
mkdir results
cd results
# Create a log file
log_file="execution_log.txt"
echo "Script execution started at: $(date)" > $log_file

# generate data -------------------------------------------------------------------------------------------------------
./../../dependencies/DUNE/release-build/dune-evaluation/src/dune-evaluation $n_max $rounds
for executor in "${executors[@]}"; do
    for mtx_format in "${mtx_formats[@]}"; do
    ./../ginkgo/build/ginkgo-evaluation $n_lowerBound $n_upperBound $rounds $interval $device $executor $mtx_format
    done
done
# ---------------------------------------------------------------------------------------------------------------------

echo "Script execution ended at: $(date)" >> $log_file