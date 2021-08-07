#include <gtest/gtest.h>
#include <iostream>
#include <map>
#include <vector>



#include "connect_four.h"
TEST(ConnectFour_TEST, test_3){
    std::vector<std::string> input = {"B_Yellow","B_Red","A_Yellow","F_Red","G_Yellow","D_Red","F_Yellow","C_Red","C_Yellow","F_Red","G_Yellow","C_Red","D_Yellow","B_Red","C_Yellow","G_Red","G_Yellow","D_Red","E_Yellow",
                                        "G_Red","F_Yellow","D_Red","F_Yellow","D_Red","E_Yellow","D_Red","C_Yellow","C_Red"};
    std::string expected = "Yellow";
    ASSERT_EQ( ConnecFour::who_is_winner(input) == expected, true);
}
TEST(ConnectFour_TEST, test_2){
    std::vector<std::string> input = {"C_Red","G_Yellow","E_Red","F_Yellow","B_Red","E_Yellow","G_Red","E_Yellow","A_Red","D_Yellow","B_Red","B_Yellow","D_Red","C_Yellow","A_Red","A_Yellow","A_Red","F_Yellow","B_Red","A_Yellow","F_Red","A_Yellow","E_Red","C_Yellow",
    "A_Yellow","F_Red","B_Yellow","B_Red","E_Yellow","F_Red","D_Yellow","F_Red","B_Yellow","A_Red","C_Yellow","B_Red","F_Yellow","D_Red","E_Yellow","B_Red","C_Yellow","G_Red","B_Yellow"};
    std::string expected = "Draw";
    ASSERT_EQ( ConnecFour::who_is_winner(input) == expected, true);

}
TEST(ConnectFour_TEST, test_1){
    std::vector<std::string> input_1 = {"A_Red","B_Yellow","A_Red","B_Yellow","A_Red","B_Yellow","G_Red","B_Yellow"};
    std::string expected_1 = "Yellow";
    ASSERT_EQ( ConnecFour::who_is_winner(input_1) == expected_1, true);
}
TEST(ConnectFour_TEST, quick_test){
    try{
        ConnecFour::Grid(6,7,4);        
    }
    catch( ConnecFour::error_code e){
        std::cout << ConnecFour::err2str[e] << std::endl;
    }
}

#include "sum_by_factors.h"
TEST(SumByFactors_TEST, quick_test){
    std::vector<int> input1 = { 15, 21, 24, 30, 45};
    std::string expected1 = "(2 54)(3 135)(5 90)(7 21)";
    ASSERT_EQ( SumOfDivided::sumOfDivided(input1 ) == expected1, true );

    std::vector<int> input2 = { 107, 158, 204, 100, 118, 123, 126, 110, 116, 100};
    std::string expected2 = "(2 1032)(3 453)(5 310)(7 126)(11 110)(17 204)(29 116)(41 123)(59 118)(79 158)(107 107)";
    ASSERT_EQ( SumOfDivided::sumOfDivided(input2 ) == expected2, true );
}

#include "human_readable_duration_format.h"
TEST(HumanReadableDurationFormat_TEST, quick_test){
    
    ASSERT_EQ( "now" == DurationFormat::format_duration( 0 ), true );
    ASSERT_EQ( "1 second" == DurationFormat::format_duration( 1 ), true );
    ASSERT_EQ( "1 hour and 7 seconds" == DurationFormat::format_duration( 3607 ), true );
    ASSERT_EQ( "4 years, 68 days, 3 hours and 4 minutes" == DurationFormat::format_duration( 132030240 ), true );
}