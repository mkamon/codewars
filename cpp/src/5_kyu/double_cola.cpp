#include <string>
#include <vector>
#include "double_cola.h"

#include <iostream>

std::string who_is_next(std::vector<std::string> names, long long n){
    const unsigned queueSize  = names.size();
    long long cannsToTake = 1;
    n -= 1;
    while(  cannsToTake * queueSize <= n ){
            n -= cannsToTake * queueSize;
            cannsToTake *= 2;
    }
    n /= cannsToTake;
    return names[ n ];
}


