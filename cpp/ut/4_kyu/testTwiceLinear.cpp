#include <gtest/gtest.h>
#include <tuple>
#include "TwiceLinear.hpp"

class DoubleLinearTestParametrization
    : public ::testing::TestWithParam<std::tuple<int, int>>
{
};

TEST_P(DoubleLinearTestParametrization, ShouldReturnCorrectValueGivenElement)
{
    //given
    const auto element = std::get<0>(GetParam());
    const auto expected = std::get<1>(GetParam());
    //when 
    const auto result = DoubleLinear::dblLinear(element);
    //then
    ASSERT_EQ(result, expected);
}

TEST(TestDoubleLinear, shouldReturnOneOnFirstElement)
{
    //given 
    constexpr auto element = 0;
    constexpr auto expected = 1;
    //when 
    const auto result = DoubleLinear::dblLinear(element);
    //then
    ASSERT_EQ(result, expected);
}

INSTANTIATE_TEST_CASE_P(
    TestDoubleLinear, 
    DoubleLinearTestParametrization,
    ::testing::Values(
        std::make_tuple(1,3),
        std::make_tuple(2,4),
        std::make_tuple(4,9),
        std::make_tuple(6,13),
        std::make_tuple(10,22),
        std::make_tuple(20,57),
        std::make_tuple(30,91)
    )
);
