#!/bin/bash
# Given two arrays a and b write a function comp(a, b) (orcompSame(a, b)) that checks whether the two arrays have the "same" elements, with the same multiplicities. "Same" means, here, that the elements in b are the elements in a squared, regardless of the order.
# Examples
# Valid arrays
#     a = [121, 144, 19, 161, 19, 144, 19, 11]  
#     b = [121, 14641, 20736, 361, 25921, 361, 20736, 361]

comp() {
	IFS=' ' read -r -a BASE_ARR <<< $1
	IFS=' ' read -r -a SQUARED_ARR <<< $2

	for i in `seq 0 $(( ${#BASE_ARR[@]}-1 ))` 
	do
		BASE_ARR[$i]=$(( ${BASE_ARR[$i]} * ${BASE_ARR[$i]} ))	 	
	done

	IFS=$'\n' BASE_ARR=($(sort -n <<<"${BASE_ARR[*]}")); unset IFS
	IFS=$'\n' SQUARED_ARR=($(sort -n <<<"${SQUARED_ARR[*]}")); unset IFS

	if [[ "${BASE_ARR[@]}" == "${SQUARED_ARR[@]}" ]]
	then 
		echo "true"
	else 
		echo "false"
	fi	
}
comp "$1" "$2"
