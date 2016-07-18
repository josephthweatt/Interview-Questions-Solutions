# Written by: Joseph Thweatt
# Runtime: 16ms
# Read from the file file.txt and output the tenth line to stdout.
#!bin/bash

declare -i index
index=0
while read -r line
do
    if [ $index -eq 9 ]
        then
            echo "$line"
            exit
    fi
    index=$(($index+1))
done < "file.txt"