#include <gtest/gtest.h>
#include <vector>

#include "sum_by_factors.h"

TEST(SumByFactors_TEST, quick_test){
    std::vector<int> input1 = { 15, 21, 24, 30, 45};
    std::string expected1 = "(2 54)(3 135)(5 90)(7 21)";
    ASSERT_EQ( SumOfDivided::sumOfDivided(input1 ) == expected1, true );

    std::vector<int> input2 = { 107, 158, 204, 100, 118, 123, 126, 110, 116, 100};
    std::string expected2 = "(2 1032)(3 453)(5 310)(7 126)(11 110)(17 204)(29 116)(41 123)(59 118)(79 158)(107 107)";
    ASSERT_EQ( SumOfDivided::sumOfDivided(input2 ) == expected2, true );
}
