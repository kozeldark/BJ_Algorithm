// ConsoleApplication162.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include<memory.h>

using namespace std;

int R, C;
char cross[21][21];
vector <string> word;
//string word[441];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> cross[i][j];
	

	for (int i = 0; i < R; i++)
	{
		string temp;
		for (int j = 0; j < C; j++)
		{
			if (cross[i][j] != '#')
				temp += cross[i][j];

			else
			{
				if (temp.length() <= 1)
					temp.clear();
				else
				{
					word.push_back(temp);
					temp.clear();
				}
			}
			if(j == C-1 && temp.length() >= 2)
				word.push_back(temp);

		}
	}

	for (int i = 0; i < C; i++)
	{
		string temp;
		for (int j = 0; j < R; j++)
		{
			if (cross[j][i] != '#')
				temp += cross[j][i];

			else
			{
				if (temp.length() <= 1)
					temp.clear();
				else
				{
					word.push_back(temp);
					temp.clear();
				}
			}
			if (j == R - 1 && temp.length() >= 2)
				word.push_back(temp);
		}
	}

	sort(word.begin(), word.end());

	cout << word[0];

	return 0;
}
