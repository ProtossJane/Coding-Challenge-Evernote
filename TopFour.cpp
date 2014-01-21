#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()	{
	string str;
	getline(cin, str);
	int N;
	int min;
	vector<int> rank;
	for (; getline(cin, str);)	
	{
		stringstream(str)>>N;
		if ( rank.size() < 4 )
		{
			if (rank.empty())	min = N;
			rank.push_back(N);
			if (N < min)	min = N;
			
		}
		else if (N > min)
		{
			rank.push_back(N);
			sort(rank.begin(), rank.end());
			rank.erase(rank.begin());
			min = rank[0];
		}
	}
	for (int i = rank.size()-1; i>=0; --i)
		cout<<rank[i]<<endl;
	return 0;
}