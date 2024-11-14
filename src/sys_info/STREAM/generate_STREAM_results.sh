# With friendly help from ChatGPT o4

#!/bin/bash

# bash setup
set -x
set -e

spack env activate gcc-13

# Define compiler flags
optimizations=("-Ofast")
freestanding=("-ffreestanding" "")
#avx2=("-mavx2" "")
openmp=("") #("-fopenmp" "")
argument_noalias=("-fargument-noalias" "")
march_native=("-march=native" "")
mtune_native=("-mtune=native" "")

# Options to run with or without likwid-pin
pinning_options=("likwid-pin -c 0" "")

# Output directory
output_dir="stream_output"
mkdir -p $output_dir


# Define a function to run the compilation and store the output
compile_and_run() {
    flags="$1"
    pinning_cmd="$2"
    output_file="$3"

    echo "Compiling with flags: $flags"
    gcc $flags stream.c -o stream-test

    if [ $? -eq 0 ]; then
        echo "Running with flags: $flags and pinning: $pinning_cmd"
        $pinning_cmd ./stream-test > "$output_file"

    else
        echo "Compilation failed with flags: $flags"
        echo "0 $output_file"  # If compilation fails, report a triad rate of 0
    fi
}

# Loop through all combinations of flags and pinning options
for opt in "${optimizations[@]}"; do
    for fs in "${freestanding[@]}"; do
        for omp in "${openmp[@]}"; do
            for alias in "${argument_noalias[@]}"; do
                for march in "${march_native[@]}"; do
                    for mtune in "${mtune_native[@]}"; do
                        for pinning in "${pinning_options[@]}"; do
                            # Construct the flag string
                            flags="$opt $fs $omp $alias $march $mtune"
                            # Construct the output file name
                            pin_suffix=$(echo "$pinning" | tr ' ' '_')
                            output_file="${output_dir}/output_$(echo $flags | tr ' ' '_')_${pin_suffix}.txt"
                            # Run the compilation and benchmark
                            compile_and_run "$flags" "$pinning" "$output_file"
                        done
                    done
                done
            done
        done
    done
done


echo "Benchmark runs complete.
