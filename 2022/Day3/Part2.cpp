#include <iostream>
#include <fstream>
#define ll long long

using namespace std;

ifstream fin("inputf/in.txt");

int get_lgth(char s[])
{
	int lgth = 0;
	while (s[lgth] != '\0')
	{
		lgth++;
	}
	return lgth;
}

int main()
{
	ll sum = 0;
	int values_lower[26], values_upper[26];
	for (int i = 0; i <= 25; i++)
	{
		values_lower[i] = i + 1;
		values_upper[i] = i + 27;
	}
	char s1[60], s2[60], s3[60];
	while (fin.getline(s1, 60))
	{
		int lgth1 = get_lgth(s1);
		fin.getline(s2, 60);
		int lgth2 = get_lgth(s2);
		fin.getline(s3, 60);
		int lgth3 = get_lgth(s3);
		int ok = 0;
		for (int i = 0; i < lgth1; i++)
		{
			for (int j = 0; j < lgth2; j++)
			{
				if (s1[i] == s2[j])
				{
					for (int k = 0; k < lgth3; k++)
					{
						if (s1[i] == s3[k])
						{
							if (s1[i] >= 'a' && s1[i] <= 'z')
							{
								sum += values_lower[s1[i] - 'a'];
							}
							else
							{
								sum += values_upper[s1[i] - 'A'];
							}
							ok = 1;
							break;
						}
					}
				}
				if (ok == 1)
					break;
			}
			if (ok == 1)
				break;
		}
	}
	cout << sum;
	return 0;
}