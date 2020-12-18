#!/bin/bash

    # You are given a string of n lines, each substring being n characters long: For example:
    #     s = "abcd\nefgh\nijkl\nmnop"
    # We will study some transformations of this square of strings.
    #     Clock rotation 180 degrees: rot
    #         rot(s) => "ponm\nlkji\nhgfe\ndcba"
    #     selfie_and_rot(s) (or selfieAndRot or selfie-and-rot) It is initial string + string obtained by clock rotation 180 degrees with dots interspersed in order (hopefully) to better show the rotation when printed.
    #         s = "abcd\nefgh\nijkl\nmnop" --> "abcd....\nefgh....\nijkl....\nmnop....\n....ponm\n....lkji\n....hgfe\n....dcba"
    # Task:
    #     Write these two functions rotand selfie_and_rot
    #     and high-order function oper(fct, s) where
    #     fct is the function of one variable f to apply to the string s (fct will be one of rot, selfie_and_rot)
    # Bash Note:
    #   The input strings are separated by , instead of \n. The ouput strings should be separated by \r instead of \n. See "Sample Tests".

strindex() { 
  x="${1%%$2*}"
  [[ "$x" = "$1" ]] && echo -1 || echo "${#x}"
}

rot() {
    echo -n $1 | rev 
}
selfieAndRot() {
    LINES=$1

    DOT_COUNT=$(strindex $LINES ',')
    DOT_TOKEN=$(seq -s '.' $(($DOT_COUNT+1)) | tr -d '[:digit:]')
  
    LINES="${LINES//","/${DOT_TOKEN}","}${DOT_TOKEN}"
    LINES="${LINES}","$(rot $LINES)"	
    echo -n $LINES
}
oper() {
	echo "$($@)" | tr "," "\r"
}

oper "$@"

#selfieAndRot $1
