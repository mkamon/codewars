#include <gtest/gtest.h>
#include <iostream>
#include <map>
#include <vector>


#include "human_readable_duration_format.h"
TEST(HumanReadableDurationFormat_TEST, quick_test){
    
    ASSERT_EQ( "now" == DurationFormat::format_duration( 0 ), true );
    ASSERT_EQ( "1 second" == DurationFormat::format_duration( 1 ), true );
    ASSERT_EQ( "1 hour and 7 seconds" == DurationFormat::format_duration( 3607 ), true );
    ASSERT_EQ( "4 years, 68 days, 3 hours and 4 minutes" == DurationFormat::format_duration( 132030240 ), true );
}