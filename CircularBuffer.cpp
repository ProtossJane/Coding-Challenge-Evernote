#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(vector<string>& buffer, int head, int tail)
{
	if (head ==-1)
	{
		return;
	}
	int size = tail - head;
	if (size < 0)
		size = buffer.size() + size;
	for (int i = 0; i<= size; ++i)
		cout<<buffer[(head+i)%buffer.size()]<<endl;
}

void remove(vector<string>& buffer, int n, int& head, int& tail)
{
	int size = tail - head ;
	if (size < 0)
		size = buffer.size() + size ;
	if (n >= size + 1)
	{
		head = -1;
		tail = 0;
		return;
	}
	head = (head + n)%buffer.size();
}

void append(vector<string>& buffer, string str, int& head, int& tail)
{
	if (head == -1)
	{
		buffer[++head] = str;
		return;
	}
	tail = ++tail%buffer.size();
	buffer[tail] = str;
	
	if (tail == head)
		head = ++head%buffer.size();
}

int main ()	{

	int N;
	cin >> N;
	vector<string> buffer(N);
	vector<string> command;
	int head = -1;
	int tail = 0;
	int cIdx = 0;
	for ( string line; getline( cin, line); )
		command.push_back(line);
	while (cIdx < command.size())
	{
		if (command[cIdx] == "Q")
			return 0;
		else if (command[cIdx] == "L")
			print(buffer, head, tail);
		else if (command[cIdx][0] == 'R')
		{
			int size = stoi( command[cIdx].substr(command[cIdx].find_last_of(' ')) );
			remove(buffer, size, head, tail);
		}
		else if (command[cIdx][0] == 'A')
		{
			int size = stoi( command[cIdx].substr(command[cIdx].find_last_of(' ')) );
			while ( size > 0)
			{
				append(buffer, command[++cIdx], head, tail);
				--size;
			}
		}
		++cIdx;
	}

	return 0;
}