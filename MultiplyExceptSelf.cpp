#include <iostream>
#include <sstream>
#include <vector>


using namespace std;

int main()
{
	long N;
	vector<long> numbers;
	vector<long> asending;
	vector<long> desending;
	asending.push_back(1);
	desending.push_back(1);
	while(cin>>N)
		numbers.push_back(N);
	numbers.erase(numbers.begin());
	
	for (long i = 1; i < numbers.size(); ++i )
	{
		asending.push_back(numbers[i-1]*asending[i-1]);
		desending.push_back(numbers[numbers.size()-i]*desending[i-1]);
	}

	for (long i = 0; i < numbers.size(); ++ i)
		cout<<asending[i]*desending[numbers.size()-1-i]<<endl;

	return 0;
}