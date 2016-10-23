#!/bin/bash
while line in file; do 
	if [[ $line == *"([0-9][0-9][0-9]) [0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]"* ]]; 
	then echo "true"; 
	else echo "false";  
	fi 
done < file.txt
