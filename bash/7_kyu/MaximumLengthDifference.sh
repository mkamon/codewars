#!/bin/bash

# Find max(abs(length(x) − length(y)))

# If a1 and/or a2 are empty return -1 in each language except in Haskell (F#) where you will return Nothing (None).
# Example:

# a1 = ["hoqq", "bbllkw", "oox", "ejjuyyy", "plmiis", "xxxzgpsssa", "xxwwkktt", "znnnnfqknaz", "qqquuhii", "dvvvwz"]
# a2 = ["cccooommaaqqoxii", "gggqaffhhh", "tttoowwwmmww"]
# mxdiflg(a1, a2) --> 13
# Bash note:
#     input : 2 strings with substrings separated by ,
#     output: number as a string


get_max(){
    IFS="," read -ra arr <<< "$1"   # IFS is a delimiter
                                    # -r read the raw input (literal interpretation on characters - not functional)
                                    # -a stores the read word in an array
    max=0
    for i in "${arr[@]}"
    do
        max=$(( max < ${#i} ? ${#i} : max ))
    done
    echo -n $max
}

get_min(){
    IFS="," read -ra arr <<< "$1"
    min=1000
    for i in "${arr[@]}"
    do
        min=$(( min > ${#i} ? ${#i} : min ))
    done
    echo -n $min
}

accum () {
    if [[ ${#1} -eq 0 || ${#2} -eq 0 ]]
    then 
        echo "-1"
        return
    fi
    ARRAY1_MAX=$( get_max $1 ) 
    ARRAY2_MAX=$( get_max $2 )
    ARRAY1_MIN=$( get_min $1 )
    ARRAY2_MIN=$( get_min $2 )

    echo $(( $ARRAY1_MAX-$ARRAY2_MIN > $ARRAY2_MAX-$ARRAY1_MIN ? $ARRAY1_MAX-$ARRAY2_MIN  : $ARRAY2_MAX-$ARRAY1_MIN ))
}
accum "$1" "$2"


#alternative solution from codewars

accum2 () {

[ -z $1 ] || [ -z $2 ] && echo "-1" && exit

mina=$(echo $1 | tr ',' '\n' | awk '{ print length }' | sort -n | head -n1)
maxa=$(echo $1 | tr ',' '\n' | awk '{ print length }' | sort -n | tail -n1)
minb=$(echo $2 | tr ',' '\n' | awk '{ print length }' | sort -n | head -n1)
maxb=$(echo $2 | tr ',' '\n' | awk '{ print length }' | sort -n | tail -n1)

[ $(($maxa-$minb)) -gt $(($maxb-$mina)) ] && echo $(($maxa-$minb)) || echo $(($maxb-$mina))

}
accum2 "$1" "$2"