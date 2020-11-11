#include <string>

class CodeSqStrings
{
public:
    static std::string code(const std::string &strng);
    static std::string decode(const std::string &strng);
private:
    inline static unsigned findArrSize( const std::string& strng);
};
