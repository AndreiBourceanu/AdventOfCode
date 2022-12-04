#include <iostream>
#include <fstream>
#define ll long long

using namespace std;

ifstream fin("inputf/in.txt");

int main()
{
	ll sum = 0;
	int values_lower[26], values_upper[26];
	for (int i = 0; i <= 25; i++)
	{
		values_lower[i] = i + 1;
		values_upper[i] = i + 27;
	}
	char s[60];
	while (fin.getline(s, 60))
	{
		int lgth = 1;
		while (s[lgth - 1] != '\0')
		{
			lgth++;
		}
		int ok = 0;
		for (int i = 0; i <= (lgth - 1) / 2; i++)
		{
			for (int j = lgth / 2; j <= lgth - 1; j++)
			{
				if (s[i] == s[j])
				{
					if (s[i] >= 'a' && s[i] <= 'z')
					{
						sum += values_lower[s[i] - 'a'];
					}
					else
					{
						sum += values_upper[s[i] - 'A'];
					}
					ok = 1;
					break;
				}
			}
			if (ok == 1)
			{
				break;
			}
		}
	}
	cout << sum;
	return 0;
}