#!/bin/bash

# bash setup
set -x
set -e
#Notes for current run: yet to generate: all gpu data
n_lowerBound="1"
n_upperBound="400"
rounds="4"
interval="1"
devices=("gpu" "cpu")
#executors=("ref" "omp")
executors=("cuda")
mtx_formats=("csr")
#mtx_formats=("csr" "coo" "ell")

rm -rf results
mkdir results
cd results
# Create a log file
log_file="execution_log.txt"
echo "Script execution started at: $(date)" > $log_file

# generate data -------------------------------------------------------------------------------------------------------
#./../../dependencies/DUNE/release-build/dune-evaluation/src/dune-evaluation $n_upperBound $rounds
#echo "Finished ISTL at         $(date)" >> $log_file
for executor in "${executors[@]}"; do
    for device in "${devices[@]}"; do
        for mtx_format in "${mtx_formats[@]}"; do
            ./../ginkgo/build/ginkgo-evaluation $n_lowerBound $n_upperBound $rounds $interval $device $executor $mtx_format
            echo "Finished with executor: $executor, matrix format: $mtx_format at      $(date)" >> $log_file
        done
    done
done
# ---------------------------------------------------------------------------------------------------------------------

echo "Script execution ended at: $(date)" >> $log_file
