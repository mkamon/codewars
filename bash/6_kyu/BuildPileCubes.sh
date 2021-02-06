#!/bin/bash
#Your task is to construct a building which will be a pile of n cubes. 
#The cube at the bottom will have a volume of n^3, the cube above will have volume of (n-1)^3 and so on until 
#the top which will have a volume of 1^3.
#You are given the total volume m of the building. Being given m can you find the number n of cubes you will have to build?
#The parameter of the function findNb (find_nb, find-nb, findNb) will be an integer m and 
#you have to return the integer n such as n^3 + (n-1)^3 + ... + 1^3 = m if such a n exists or -1 if there is no such n.


find_nb () {
	TARGET_VOLUME=$1
	CURRENT_VOLUME=0
	CUBES_AMOUNT=0
	while [ "$CURRENT_VOLUME" -lt "$TARGET_VOLUME" ]
	do
		((++CUBES_AMOUNT))
		CURRENT_VOLUME=$(( $CURRENT_VOLUME + $CUBES_AMOUNT ** 3 )) 
	done

	if [ $CURRENT_VOLUME -eq $TARGET_VOLUME ]
	then
		echo $CUBES_AMOUNT
	else
		echo "-1"
	fi
}
find_nb "$1"
