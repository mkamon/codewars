#include <vector>
#include <string>

class FermatAlg{
private:
	std::vector< long long int > twoDividersOfOddNum (long long int oddNum ); // for odd num only gives two of it's divisers or two zeros if prime
	std::vector< long long int >  fermatAlgorithmForOdd (long long int oddNum ); // main part of alg ONLY FOR ODDS
public:
	std::vector< std::vector< int > > fermatFull( long long int num );
};

class SumOfDivided
{
	static void bubbleSort( std::vector< std::vector< int > > &arrToSort );
public:
    static std::string sumOfDivided(std::vector<int> &lst);
};