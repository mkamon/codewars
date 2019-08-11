#include "factorial_decomposition.h"

#include <sstream>

std::vector<int> FactorialDecomp::generatePrimeFactorsTable( int n ){
    std::vector<int> vResult;
    if( n<2)
        return vResult;
    for( int i=2; i<=n; i++)
        vResult.push_back(i);

    for( int i=0; ; i++){
        if( vResult[i] > n/2 )
            break;
        std::vector<int> vTemp( vResult.begin(), vResult.begin()+i+1 );
        for( unsigned j=i+1; j<vResult.size(); j++){
            if( vResult[j] % vResult[i] != 0)
                vTemp.push_back(vResult[j]);
        }
        vResult = vTemp;
    }
    return vResult;
}

std::string FactorialDecomp::decomp(int n){
    const std::vector<int> allPrimes = generatePrimeFactorsTable( n );
    std::vector<int> factorCounters( allPrimes.size(), 0);

    for( int i=2; i<=n; i++){
        int value = i;
        unsigned primeIdx = 0;
        while( primeIdx < allPrimes.size() ){
            if( value == 1)
                break;
            if( value % allPrimes[ primeIdx ] == 0){
                value /= allPrimes[ primeIdx ];
                factorCounters[ primeIdx ] ++;
            }
            else
                primeIdx++;            
        }
    }
    std::string sResult;
    for( unsigned i=0; i<allPrimes.size(); i++){
        std::stringstream ss;
        ss << allPrimes[i]; 
        if( factorCounters[i] != 1)
            ss << "^" << factorCounters[i];
        sResult += ss.str();
        if( i != allPrimes.size() -1 )
            sResult += " * ";
    }
    return sResult;
}