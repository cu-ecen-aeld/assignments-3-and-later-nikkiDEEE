#!/bin/bash

writefile="$1"
writestr="$2"

if [ -z "$writefile" ] || [ -z "$writestr" ]; then
    echo "Usage: $0 <file> <write_string>"
    exit 1
fi

dirpath=$(dirname "$writefile")

mkdir -p "$dirpath"
if [$? -ne 0]; then
    echo "Error: Failed to create directory $dirpath."
    exit 1
fi

echo "$writestr" > "$writefile"

if [ $? -ne 0 ]; then
    echo "Error: Failed to write to file $writefile."
    exit 1
fi

echo "Successfully wrote to $writefile."
exit 0