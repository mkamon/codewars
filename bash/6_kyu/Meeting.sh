#!/bin/bash

# John has invited some friends. His list is:
#     s = "Fred:Corwill;Wilfred:Corwill;Barney:Tornbull;Betty:Tornbull;Bjon:Tornbull;Raphael:Corwill;Alfred:Corwill";
# Could you make a program that
#     makes this string uppercase
#     gives it sorted in alphabetical order by last name.
# When the last names are the same, sort them by first name. Last name and first name of a guest come in the result between parentheses separated by a comma.
# So the result of function meeting(s) will be:
#     "(CORWILL, ALFRED)(CORWILL, FRED)(CORWILL, RAPHAEL)(CORWILL, WILFRED)(TORNBULL, BARNEY)(TORNBULL, BETTY)(TORNBULL, BJON)"
# It can happen that in two distinct families with the same family name two people have the same first name too.
# Notes
#     You can see another examples in the "Sample tests".

meeting(){
	IFS=';' read -r -a GUEST_LIST <<< ${1^^}

	for i in `seq 0 $(( ${#GUEST_LIST[@]} - 1))` 
	do
		GUEST=${GUEST_LIST[$i]}		
		GUEST_LIST[$i]=$( sed -E 's/(.+):(.+)/(\2, \1)/' <<< $GUEST)
	done

	IFS=$'\n' SORTED_LIST=($(sort <<< "${GUEST_LIST[*]}")); unset IFS
	OUTPUT=$(IFS=''; echo "${SORTED_LIST[*]}")
	echo $OUTPUT 

}	

meeting $1
#meeting  "Fred:Corwill;Wilfred:Corwill;Barney:Tornbull;Betty:Tornbull;Bjon:Tornbull;Raphael:Corwill;Alfred:Corwill"
#another solution
#echo "$1" | sed -E 's/(\w+):(\w+)/(\U\2, \U\1)/g' | tr ";" "\n" | sort | tr -d "\n"
