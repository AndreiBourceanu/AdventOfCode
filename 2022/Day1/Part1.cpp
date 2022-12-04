#include <iostream>
#include <fstream>
#define ll long long

using namespace std;

ifstream fin("inputf/in.txt");

ll array_to_int(char* arr)
{
	if (arr != NULL)
	{
		int i = 0;
		ll nr = 0;
		while (arr[i] != '\0')
		{
			nr = nr * 10 + (arr[i] - '0');
			i++;
		}
		return nr;
	}
	return -1;
}

int main()
{
	char s[256];
	ll maxx = 0;
	ll sum = 0;
	while (fin.getline(s, 256))
	{
		if (s[0] == '\0')
		{
			if (sum > maxx)
			{
				maxx = sum;
			}
			sum = 0;
		}
		else
		{
			sum += array_to_int(s);
		}
	}
	if (sum > maxx)
	{
		maxx = sum;
	}
	cout << maxx;
	return 0;
}