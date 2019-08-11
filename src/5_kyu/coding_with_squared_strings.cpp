#include "coding_with_squared_strings.h"
#include <math.h>

unsigned CodeSqStrings::findArrSize( const std::string& strng){
    unsigned root = sqrt( strng.size() );
    return root*root == strng.size() ?  root :  root+1;
}

std::string CodeSqStrings::code( const std::string& strng){
    const unsigned arrSize = findArrSize( strng );
    const char blankChar = (int) 11;
    std::string sResult;
    for( unsigned i=0; i<arrSize; i++, sResult.push_back('\n')){
        for( unsigned j=arrSize; j>0; j--){
            unsigned indexOld = arrSize*(j-1) + i; 
            if( indexOld < strng.size() )
                sResult.push_back( strng[indexOld] );
            else
                sResult.push_back( blankChar );
        }
    }
    sResult.pop_back();
    return sResult;
}

std::string CodeSqStrings::decode(const std::string &strng){
    const unsigned arrSize = findArrSize( strng ); // includes also '\n'
    const char blankChar = (int) 11; 
    std::string sResult;
    for( unsigned i=arrSize-1; i>0; i--){
        for( unsigned j=0; j<arrSize-1; j++){
            unsigned indexOld = arrSize * j + i - 1; 
            if( strng[ indexOld ] != blankChar )
                sResult.push_back( strng[indexOld] );
        }
    }
    return sResult;
}