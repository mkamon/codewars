#include "TwiceLinear.hpp"
#include <set>

int DoubleLinear::dblLinear(int n)
{
    std::set<int> allValues { 1 };
     for (int i = 0; i < n; ++i) {
       auto x = *(allValues.begin());
       allValues.erase(allValues.begin());
       auto hint = allValues.insert(2*x + 1);
       allValues.insert(hint.first, 3*x + 1);
     }
     return *(allValues.begin());
}
