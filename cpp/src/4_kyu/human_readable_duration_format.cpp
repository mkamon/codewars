#include "human_readable_duration_format.h"
#include <sstream>
#include <iostream>
using namespace DurationFormat;

std::map<time_period_t, std::string> DurationFormat::timePeriod2str{
    {TIME_NOW,      "now"},
    {TIME_SECOND,   "second"},
    {TIME_MINUTE,   "minute"},
    {TIME_HOUR,     "hour"},    
    {TIME_DAY,      "day"},
    {TIME_YEAR,     "year"}
};   
std::map<time_period_t, unsigned> DurationFormat::wrapCounter{
    {TIME_NOW,      0},
    {TIME_SECOND,   60},
    {TIME_MINUTE,   60},
    {TIME_HOUR,     24},    
    {TIME_DAY,      365},
    {TIME_YEAR,     100}
};

std::string DurationFormat::format_duration(int seconds){
    if( seconds == 0)
        return timePeriod2str[ TIME_NOW ];

    std::map< time_period_t, unsigned > timePeriodCounter;
    unsigned periodCounter = 0;
    for( int i=TIME_SECOND; i<=TIME_YEAR; i++){
        if(  seconds % wrapCounter[ (time_period_t)i ] ){
            timePeriodCounter[ (time_period_t)i ] = seconds % wrapCounter[ (time_period_t)i ];
            periodCounter ++;
        }
        seconds = seconds / wrapCounter[ (time_period_t)i ];
    }    
    std::string sResult = "";

    for( std::map< time_period_t, unsigned >::iterator it=timePeriodCounter.begin(); it != timePeriodCounter.end(); it++  ){       
        std::stringstream ss;
        ss << it->second << " " << timePeriod2str[ it->first ];
        if( it->second > 1 )
            ss << "s";

        if( it==timePeriodCounter.begin() && periodCounter > 1 )
            sResult = " and " + ss.str();
        else if( it!=timePeriodCounter.begin() && periodCounter > 1 )
            sResult = ", " + ss.str() + sResult;
        else 
            sResult = ss.str() + sResult;
        periodCounter--;
    }
    return sResult;
}
    