#!/bin/bash

# bash setup
set -x
set -e

n_lowerBound="1"

n_upperBound="210"
min_reps="7"
min_time="250" #in ms (was 250 initially)
max_iters="10"
dims=("3")

#ISTL
# implicit row_wise random
buildModes=("implicit")

#GINKGO
# ref 1omp omp cuda
executors=("1omp" "ref")
# md mad dmd
assembly_structures=("md")
# csr coo ell sellp hybrid
mtx_formats=("csr" "ell")


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
                if [ "$executor" == "1omp" ]; then
                    export OMP_NUM_THREADS=1
                fi
                ./../ginkgo/build/ginkgo-evaluation $n_lowerBound $n_upperBound $dim $min_reps $min_time $max_iters $assembly_structure $executor $mtx_format
                unset OMP_NUM_THREADS
                echo "Finished with executor: $executor, matrix format: $mtx_format at      $(date)" >> $log_file

            done
        done
    done
done
# ---------------------------------------------------------------------------------------------------------------------

echo "Script execution ended at: $(date)" >> $log_file
