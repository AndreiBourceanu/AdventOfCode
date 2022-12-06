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
	fin.getline(s, 99999);
	int i = 0, rez = -1;
	while (s[i + 3] != '\0')
	{
		if (s[i] != s[i + 1] && s[i] != s[i + 2] && s[i] != s[i + 3] && s[i + 1] != s[i + 2] && s[i + 1] != s[i + 3] && s[i + 2] != s[i + 3])
		{
			rez = i + 4;
			break;
		}
		i++;
	}
	cout << rez;
	return 0;
}