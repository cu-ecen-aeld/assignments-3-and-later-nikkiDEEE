#!/bin/bash

filesdir="$1"
searchstr="$2"

if [ -z "$filesdir" ] || [ -z "$searchstr" ]; then
    echo "Usage: $0 <directory> <search_string>"
    exit 1
fi

if [ ! -d "$filesdir" ]; then
    echo "Error: Directory $filesdir does not exist."
    exit 1
fi

echo "The number of files are $(find "$filesdir" -type f | wc -l) and the number of matching lines are $(grep -r "$searchstr" "$filesdir" | wc -l)."
exit 0

