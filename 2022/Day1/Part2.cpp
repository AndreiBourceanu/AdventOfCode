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
	ll max1, max2, max3;
	max1 = max2 = max3 = -1;
	ll sum = 0;
	while (fin.getline(s, 256))
	{
		if (s[0] == '\0')
		{
			if (sum >= max1)
			{
				max3 = max2;
				max2 = max1;
				max1 = sum;
			}
			else if (sum >= max2)
			{
				max3 = max2;
				max2 = sum;
			}
			else if (sum >= max3)
			{
				max3 = sum;
			}
			sum = 0;
		}
		else
		{
			sum += array_to_int(s);
		}
	}
	if (sum >= max1)
	{
		max3 = max2;
		max2 = max1;
		max1 = sum;
	}
	else if (sum >= max2)
	{
		max3 = max2;
		max2 = sum;
	}
	else if (sum >= max3)
	{
		max3 = sum;
	}
	cout << max1 + max2 + max3;
	return 0;
}