#include <iostream>
#include <fstream>
#include <cstring>
#include <stack>
#include <vector>
#define ll long long

using namespace std;

ifstream fin("inputf/in.txt");

int main()
{
	char s[99999];
	int freq[26] = { 0 };
	fin.getline(s, 99999);
	int i = 14, rez = -1, ok = 1;
	for (int j = 0; j <= 13; j++)
	{
		freq[s[j] - 'a']++;
		if (freq[s[j] - 'a'] > 1)
		{
			ok = 0;
		}
	}
	if (ok)
	{
		cout << 14;
		return 0;
	}
	int last = s[0];
	while (s[i] != '\0')
	{
		freq[last - 'a']--;
		last = s[i - 13];
		freq[s[i] - 'a']++;
		ok = 1;
		for (int j = 0; j <= 25; j++)
		{
			if (freq[j] > 1)
			{
				ok = 0;
				break;
			}
		}
		if (ok)
		{
			cout << i + 1;
			return 0;
		}
		i++;
	}
	cout << rez;
	return 0;
}