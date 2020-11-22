#!/bin/bash

#  The examples below show you how to write function accum:
# Examples:
# accum("abcd") -> "A-Bb-Ccc-Dddd"
# accum("RqaEzty") -> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
# accum("cwAt") -> "C-Ww-Aaa-Tttt"
# The parameter of accum is a string which includes only letters from a..z and A..Z.

accum () {

    input=${1,,}                         # lowercase input
    length=${#input}                     # length of input
    output=''                            # final output
    sep='-'                              # separtor
    
    for (( i=0; i<$length; i++ ))
    do
        char=${input:$i:1}               # character to be repeated
        count=$(($i+1))                  # cout of spaces in seq to be repalced with $char

        lctoken=$(seq -s $char $count | tr -d '[:digit:]')     # lower case token creation: sequnce od digits with $char as separator -> remove digits 
        output+="${char^}${lctoken}${sep}" # append upper case $char with $lctoken and $sep to output
    done

    outLength=$((${#output}-1))          # final length - without last separator occurance
    echo ${output:0:$outLength }

}
accum "$1"
