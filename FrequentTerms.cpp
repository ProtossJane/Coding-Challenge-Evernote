#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;


bool comparator(unordered_map<string, int>::iterator it1,  unordered_map<string, int>::iterator it2)
{
	if ( it1->second == it2->second )
		return it1->first.compare(it2->first)>0 ;
	return it1->second < it2->second;
}

int main()	
{
	unordered_map<string, int> table;
	vector<unordered_map<string, int>::iterator> rank;
	int N;
	int K;
	bool sorted = false;
	unordered_map<string, int>::iterator min;
	string str;
	getline(cin, str);
	stringstream(str) >> N; 
	while(N > 0)
	{
		getline(cin,str);
		if ( table.find(str) == table.end())	table[str] = 0;
		table[str]++;
		--N;
	}
	getline(cin, str);
	stringstream(str) >> K;
	for (auto it = table.begin(); it!=table.end(); ++it)
	{
		if (rank.size() < K)
		{
			if (rank.empty())	min = it;
			if (comparator(it, min))	min = it;
			rank.push_back(it);
		}
		else if ( comparator(min, it) )
		{
			if (!sorted)
			{
				sort(rank.begin(), rank.end(), comparator);
				sorted = true;
			}
			int insertIdx = 0;
			for (; insertIdx < K; ++insertIdx )
				if( comparator(it, rank[insertIdx]))					
					break;
			rank.insert(rank.begin()+insertIdx, it);
			rank.erase(rank.begin());
			min = rank[0];
		}
	}
	for ( int i = rank.size()-1; i>=0; --i )
		cout<<rank[i]->first<<endl;

	return 0;
}