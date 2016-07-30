# Written by: Joseph Thweatt
# Runtime: 650 ms
# Read from the file file.txt and print its transposed content to stdout.

# Note: the runtime of this code is really not great. Most other's solutions
#		shave 100 ms off the runtime by implementing a bash-like for loop,
# 		as opposed to my C-like loop. The fastest solutions implemented
# 		'awk', but I don't know that and I'm not interested in learning it.

#!/bin/bash
declare -A matrix
declare -i col
declare -i ro

col=0
while read lines; do
    ro=0
    for word in $lines; do
        matrix[$ro, $col]=$word
        ro=$((ro + 1))
    done
    col=$((col + 1))
done < file.txt

for ((x=0; x < $ro; x++)) {
	for ((y=0; y < $col; y++)) {
		if [ $y == $(($col - 1)) ]; then
			echo -n ${matrix[$x, $y]}
		else
			echo -n ${matrix[$x, $y]}" "
		fi
	}
	echo
}  
exit
