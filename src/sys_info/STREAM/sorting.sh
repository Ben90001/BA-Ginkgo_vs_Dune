#!/bin/bash

# Initialize an empty array to hold the filename and triad values.
declare -a file_triads

# Loop over each .txt file in the current directory
for file in stream_output/*.txt; do
    # Extract the Triad value from the file
    triad_value=$(grep "Triad:" "$file" | awk '{print $2}')
    
    # Check if the triad value is non-empty
    if [[ -n "$triad_value" ]]; then
        # Append the filename and triad value to the array
        file_triads+=("$triad_value $file")
    fi
done

# Sort the array by the triad value in descending order and save to sorted_output.txt
printf "%s\n" "${file_triads[@]}" | sort -nr > sorted_output.txt

echo "Sorted output written to sorted_output.txt"
