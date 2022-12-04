#include <iostream>
#include <fstream>
#include <cstring>
#define ll long long

using namespace std;

ifstream fin("inputf/in.txt");

void add(ll& total, char elem, char result)
{
	if (result == 'Z')
	{
		total += 6;
	}
	else if (result == 'Y')
	{
		total += 3;
	}

	if (elem == 'X')
	{
		total += 1;
	}
	else if (elem == 'Y')
	{
		total += 2;
	}
	else
	{
		total += 3;
	}
}

int main()
{
	char s[5];
	char elem;
	ll total = 0;
	while (fin.getline(s, 5))
	{
		if (s[2] == 'X')
		{
			if (s[0] == 'A')
			{
				elem = 'Z';
			}
			else if (s[0] == 'B')
			{
				elem = 'X';
			}
			else
			{
				elem = 'Y';
			}
		}
		else if (s[2] == 'Y')
		{
			if (s[0] == 'A')
			{
				elem = 'X';
			}
			else if (s[0] == 'B')
			{
				elem = 'Y';
			}
			else
			{
				elem = 'Z';
			}
		}
		else
		{
			if (s[0] == 'A')
			{
				elem = 'Y';
			}
			else if (s[0] == 'B')
			{
				elem = 'Z';
			}
			else
			{
				elem = 'X';
			}
		}
		add(total, elem, s[2]);
	}
	cout << total;
	return 0;
}