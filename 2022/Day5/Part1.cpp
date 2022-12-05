#include <iostream>
#include <fstream>
#include <cstring>
#include <stack>
#include <vector>
#define ll long long

using namespace std;

ifstream fin("inputf/in.txt");

void get_values(char s[], int& quant, int& start, int& end)
{
	int i = 0;
	while (!(s[i] >= '0' && s[i] <= '9'))
	{
		i++;
	}
	quant = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		quant = quant * 10 + (s[i] - '0');
		i++;
	}
	while (!(s[i] >= '0' && s[i] <= '9'))
	{
		i++;
	}
	start = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		start = start * 10 + (s[i] - '0');
		i++;
	}

	while (!(s[i] >= '0' && s[i] <= '9'))
	{
		i++;
	}
	end = 0;
	while (s[i] != '\0' && s[i] >= '0' && s[i] <= '9')
	{
		end = end * 10 + (s[i] - '0');
		i++;
	}
}

int main()
{
	int length = 9;
	vector <stack <char>> st(length + 1);
	
	char m[60][100];
	int i = -1;
	do
	{
		i++;
		fin.getline(m[i], 100);
	} while (m[i][1] != '1');


	for (int j = i - 1; j >= 0; j--)
	{
		int poz = -3;
		for (int k = 1; k <= length; k++)
		{
			poz += 4;
			if(m[j][poz] != ' ')
				st[k].push(m[j][poz]);
		}
	}
	
	fin.get();

	char instructions[100];

	while (fin.getline(instructions, 100))
	{
		int quant, start, end;
		get_values(instructions, quant, start, end);
		while (!st[start].empty() && quant)
		{
			quant--;
			st[end].push(st[start].top());
			st[start].pop();
		}
	}
	for (int j = 1; j <= length; j++)
		cout << st[j].top();

	return 0;
}