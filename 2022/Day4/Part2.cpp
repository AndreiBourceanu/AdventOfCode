#include <iostream>
#include <fstream>
#define ll long long

using namespace std;

ifstream fin("inputf/in.txt");

void get_values(char s[], int &i1, int &i2, int &j1, int &j2)
{
	int p = 0;
	i1 = i2 = j1 = j2 = 0;
	while (s[p] != '-' && s[p] != '\0')
	{
		i1 = i1 * 10 + (s[p] - '0');
		p++;
	}
	p++;
	while (s[p] != ',' && s[p] != '\0')
	{
		i2 = i2 * 10 + (s[p] - '0');
		p++;
	}
	p++;
	while (s[p] != '-' && s[p] != '\0')
	{
		j1 = j1 * 10 + (s[p] - '0');
		p++;
	}
	p++;
	while (s[p] != '\0')
	{
		j2 = j2 * 10 + (s[p] - '0');
		p++;
	}
}

int main()
{
	char s[60];
	ll total = 0;
	while (fin.getline(s, 60))
	{
		int i1, i2, j1, j2;
		get_values(s, i1, i2, j1, j2);
		if (!(i2 < j1 || i1 > j2))
		{
			total++;
		}
	}
	cout << total;
	return 0;
}