#include <iostream>
#include <fstream>
#include <cstring>
#define ll long long

using namespace std;

ifstream fin("inputf/in.txt");

void add(ll &total, char elem, char result[])
{
	if (strcmp(result, "win") == 0)
	{
		total += 6;
	}
	else if (strcmp(result, "draw") == 0)
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
	char result[6];
	ll total = 0;
	while (fin.getline(s, 5))
	{
		if (s[2] == 'X')
		{
			if (s[0] == 'A')
			{
				strcpy_s(result, "draw");
			}
			else if (s[0] == 'B')
			{
				strcpy_s(result, "lose");
			}
			else
			{
				strcpy_s(result, "win");
			}
		}
		else if (s[2] == 'Y')
		{
			if (s[0] == 'A')
			{
				strcpy_s(result, "win");
			}
			else if (s[0] == 'B')
			{
				strcpy_s(result, "draw");
			}
			else
			{
				strcpy_s(result, "lose");
			}
		}
		else
		{
			if (s[0] == 'A')
			{
				strcpy_s(result, "lose");
			}
			else if (s[0] == 'B')
			{
				strcpy_s(result, "win");
			}
			else
			{
				strcpy_s(result, "draw");
			}
		}
		add(total, s[2], result);
	}
	cout << total;
	return 0;
}