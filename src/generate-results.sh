#!/bin/bash

# bash setup
set -x
set -e

n_lowerBound="1"
interval="1"

n_upperBound="110"
min_reps="4"
min_time="250000000"
max_iters="10"
dims=("3")

#ISTL
buildModes=("implicit" "row_wise")
#buildModes=("row_wise")

#GINKGO
assembly_structures=("md" "mad")
#assembly_structures=("md")
#executors=("1omp" "cuda")
executors=("ref" "1omp")
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
    for dim in "${dims[@]}"; do
        ./../../dependencies/DUNE/release-build/dune-evaluation/src/dune-evaluation $n_upperBound $dim $max_iters $min_reps $min_time $buildMode
        echo "Finished ISTL with buildMode $buildMode at       $(date)" >> $log_file
    done
done

for executor in "${executors[@]}"; do
    for assembly_structure in "${assembly_structures[@]}"; do
        for mtx_format in "${mtx_formats[@]}"; do
            for dim in "${dims[@]}"; do
                ./../ginkgo/build/ginkgo-evaluation $n_lowerBound $n_upperBound $dim $min_reps $min_time $interval $max_iters $assembly_structure $executor $mtx_format
                echo "Finished with executor: $executor, matrix format: $mtx_format at      $(date)" >> $log_file
            done
        done
    done
done
# ---------------------------------------------------------------------------------------------------------------------

echo "Script execution ended at: $(date)" >> $log_file
