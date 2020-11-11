#include <gtest/gtest.h>
#include <iostream>
#include <map>
#include <vector>


#include "factorial_decomposition.h"
TEST( FactorialDecomposition, generatePrimeFactorsTableTest_1){
    int inputValue = 20;
    std::vector<int> expected = {2, 3, 5, 7, 11, 13, 17, 19};
    std::vector<int> tstResult = FactorialDecomp::generatePrimeFactorsTable( inputValue );
    ASSERT_EQ( tstResult == expected, true);
}
TEST( FactorialDecomposition, generatePrimeFactorsTableTest_2){
    int inputValue = 100;
    std::vector<int> expected = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    std::vector<int> tstResult = FactorialDecomp::generatePrimeFactorsTable( inputValue );
    ASSERT_EQ( tstResult == expected, true);
}
TEST( FactorialDecomposition, decompTest_1){
    int inputValue = 12;
    std::string expected = "2^10 * 3^5 * 5^2 * 7 * 11";
    std::string tstResult = FactorialDecomp::decomp( inputValue );
    ASSERT_EQ( tstResult == expected, true);
}

///////////////////////////////////////////////////////////
#include "coding_with_squared_strings.h"
TEST( CodingWithSquaredStrings, SimpleTest_1){
    std::string testInput= "abcdefghijklmnop";
    std::string expected = "miea\nnjfb\nokgc\nplhd";
    std::string tstResult= CodeSqStrings::code( testInput );
    ASSERT_EQ( tstResult == expected, true ); 
    tstResult= CodeSqStrings::decode( expected );
    ASSERT_EQ( tstResult == testInput, true );

}
TEST( CodingWithSquaredStrings, SimpleTest_2){
    std::string testInput= "I.was.going.fishing.that.morning.at.ten.o'clock";
    std::string expected = "c.nhsoI\nltiahi.\noentinw\ncng.nga\nk..mg.s\n\voao.f.\n\v'trtig";
    std::string tstResult= CodeSqStrings::code( testInput );
    ASSERT_EQ( tstResult == expected, true ); 
    tstResult= CodeSqStrings::decode( expected );
    ASSERT_EQ( tstResult == testInput, true );
}
///////////////////////////////////////////////////////////
#include "double_cola.h"
TEST( DoubleCola, SimpleTest_1){
    std::vector< std::string > vInput_1 = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    long long iInput_2 = 6;
    std::string sResult = who_is_next(vInput_1, iInput_2 );    
    ASSERT_EQ( sResult == "Sheldon", true);
}
TEST( DoubleCola, SimpleTest_2){
    std::vector< std::string > vInput_1 = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    long long iInput_2 = 15;
    std::string sResult = who_is_next(vInput_1, iInput_2 );    
    ASSERT_EQ( sResult == "Howard", true);
}
TEST( DoubleCola, SimpleTest_3){
    std::vector< std::string > vInput_1 = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    long long iInput_2 = 16;
    std::string sResult = who_is_next(vInput_1, iInput_2 );    
    ASSERT_EQ( sResult == "Sheldon", true);
}
TEST( DoubleCola, SimpleTest_4){
    std::vector< std::string > vInput_1 = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    long long iInput_2 = 1;
    std::string sResult = who_is_next(vInput_1, iInput_2 );    
    ASSERT_EQ( sResult == "Sheldon", true);
}
TEST( DoubleCola, SimpleTest_5){
    std::vector< std::string > vInput_1 = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    long long iInput_2 = 52;
    std::string sResult = who_is_next(vInput_1, iInput_2 );    
    ASSERT_EQ( sResult == "Penny", true);
}


