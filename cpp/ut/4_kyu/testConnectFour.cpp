
#include <gtest/gtest.h>

#include <vector>
#include <string>

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
