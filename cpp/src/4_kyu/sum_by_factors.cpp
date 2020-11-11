#include "sum_by_factors.h"

#include <iostream>
#include <cmath>
#include <sstream>
#include <algorithm>


std::vector< long long int > FermatAlg::twoDividersOfOddNum ( long long int oddNum )
{
	long long int num1;
	std::vector< long long int > twoDividers(2);

	num1 = sqrt( oddNum );
	twoDividers[0]=0; 
	twoDividers[1]=0;
	if (num1 * num1 == oddNum ){
		twoDividers[0] = num1;
		twoDividers[1] = num1;
	}
	else{
		num1 ++;
		while(num1 < ( (oddNum + 1) / 2 ))
		{
			long long int tempNum = num1*num1-oddNum;
			long long int num2 = sqrt( tempNum );
			if( tempNum > 0 && num2 * num2 == tempNum ){
				twoDividers[0]=num1 + num2;
				twoDividers[1]=num1 - num2;
				break;
			}
			else num1++;
		}
	}
	return twoDividers;
}


std::vector< long long int > FermatAlg::fermatAlgorithmForOdd ( long long int oddNum )
{
	std::vector< long long int > primeList;

	std::vector< long long int > twoDividers = twoDividersOfOddNum( oddNum );
	if( twoDividers[0] != 0 ){
		std::vector< long long int > tempVec1 = fermatAlgorithmForOdd( twoDividers[0] );
		std::vector< long long int > tempVec2 = fermatAlgorithmForOdd( twoDividers[1] );
		for( unsigned i=0; i<tempVec1.size(); i++ ) primeList.push_back( tempVec1[i] );
		for( unsigned i=0; i<tempVec2.size(); i++ ) primeList.push_back( tempVec2[i] );
	} else{
		primeList.push_back( oddNum );
	}

	return primeList;
}

std::vector< std::vector< int > > FermatAlg::fermatFull( long long int num ){

	std::vector< int > primeList;
	std::vector< int > primesMultipl;
	std::vector< std::vector< int > > result;

	if( num <= 1 ) return result;

	unsigned multiplOfTwo = 0;
	while(num % 2==0){
		num = num /2;
		multiplOfTwo ++;
	}	
	if( num == 1 ){
		std::vector< int > temp(2);
		temp[0] = 2;
		temp[1] = multiplOfTwo;
		result.push_back(temp);
		return result;
	}

	std::vector< long long int > primesWithRepet = fermatAlgorithmForOdd( num );
	for( unsigned i = 0; i < multiplOfTwo; i++ ) primesWithRepet.push_back(2);
	std::sort( primesWithRepet.begin(), primesWithRepet.end() );

	if( primesWithRepet.size() > 0 ){
		primeList.push_back( primesWithRepet[0] );
		primesMultipl.push_back(1);
	}
	for( unsigned i = 1; i < primesWithRepet.size(); i++){
		if( primesWithRepet[i] != primeList[ primeList.size()-1 ] ){
			primeList.push_back( primesWithRepet[i] );
			primesMultipl.push_back( 1 );
		} else{
			primesMultipl[ primesMultipl.size() - 1 ] ++;
		}
	}

	for( unsigned i = 0; i < primeList.size(); i++){

		std::vector< int > temp(2);
		temp[0] = primeList[i];
		temp[1] = primesMultipl[i];
		result.push_back( temp );
	} 
	return result;
}




void SumOfDivided::bubbleSort( std::vector< std::vector< int > > &arrToSort ){
	unsigned iVecSize = arrToSort.size();
	for( unsigned k=1; k<iVecSize-1; k++){
		for( unsigned i=0; i<iVecSize-k; i++){
			if( arrToSort[i][0] > arrToSort[i+1][0] ){
				std::vector< int > vTemp = arrToSort[i+1];
				arrToSort[i+1] = arrToSort[i];
				arrToSort[i] = vTemp;
			}
		}
	}
}

std::string SumOfDivided::sumOfDivided( std::vector<int> &lst ){
	if(lst.size() == 0 )
		return "";
	
	FermatAlg FullDecomp;
	std::vector< std::vector <int> > vPrimesFor_lst;
	std::vector< int > vTempLst;

	for( unsigned i=0; i<lst.size(); i++){
		if( lst[i] < 0 )
			vTempLst.push_back( -lst[i] );
		else 
			vTempLst.push_back( lst[i] );
	}
	for( unsigned i=0; i<vTempLst.size(); i++){
		std::vector< std::vector <int> > vPrimesAndRepeats = FullDecomp.fermatFull( vTempLst[i] );
		for( unsigned j=0; j<vPrimesAndRepeats.size(); j++){
			std::vector< int > vTemp;
			vTemp.push_back( vPrimesAndRepeats[j][0] );
			vTemp.push_back( lst[i] );
			vPrimesFor_lst.push_back( vTemp );
		}
	}

	bubbleSort( vPrimesFor_lst );

	std::vector< std::vector< int > > vResult;
	int iCurrentPrime = 0;
	for( unsigned i=0; i<vPrimesFor_lst.size();i++){
		int iNewPrime = vPrimesFor_lst[i][0];
		if( iCurrentPrime != iNewPrime ){
			std::vector< int > vTemp;
			vTemp.push_back( iNewPrime );
			vTemp.push_back( vPrimesFor_lst[i][1] );
			vResult.push_back( vTemp );
			iCurrentPrime = iNewPrime;
		}
		else{
			vResult[ vResult.size()-1][1] += vPrimesFor_lst[i][1];
		}
	}
	std::string sResult;
	std::stringstream ssTemp;
	for( unsigned i=0; i<vResult.size();i++)
		ssTemp << "(" << vResult[i][0]<< " "<< vResult[i][1] << ")";
	sResult = ssTemp.str();
	return sResult; 
}