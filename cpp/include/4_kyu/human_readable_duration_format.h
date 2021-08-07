#include <map>
#include <string>

namespace DurationFormat{

    enum time_period_t{
        TIME_NOW    = 0,
        TIME_SECOND = 1,
        TIME_MINUTE = 2,
        TIME_HOUR   = 3,
        TIME_DAY    = 4,
        TIME_YEAR   = 5
    };

    extern std::map<time_period_t, std::string> timePeriod2str;    // converts time_period_t to string with its name 
    extern std::map<time_period_t, unsigned> wrapCounter;          // assign upperlimit for each time_period_t

    std::string format_duration(int seconds);

}