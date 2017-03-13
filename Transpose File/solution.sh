#!/bin/bash

readarray a < file.txt # a becomes 2d array of text file

for i in ${!a[@]}; do
	for j in ${a[$i]}; do
		echo $j
	done
done
