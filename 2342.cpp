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
#include <set>

using namespace std;
int A, B;
int cnt = 0;
int ans = 2;
int ddr[100001];
int dp[100001][5][5];
int cost[5][5];

int sol(int current, int l, int r)
{
	if (current == cnt -1)
		return 0;

	if (dp[current][l][r] !=  0)
		return dp[current][l][r];
	
	int l_foot = sol(current + 1, ddr[current], r) + cost[l][ddr[current]];
	int r_foot = sol(current + 1, l, ddr[current]) + cost[r][ddr[current]];

	return dp[current][l][r] = min(l_foot, r_foot);
}


int main()
{
	int num = -1;

	while (num != 0) 
	{
		cin >> num;
	
		ddr[cnt] = num;
		cnt++;
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{			
			if (i == 0)
				cost[i][j] = 2;
			else
			{
				if (i == j)
					cost[i][j] = 1;
				else
				{
					if (abs(i - j) == 2)
						cost[i][j] = 4;
					else
						cost[i][j] = 3;
				}

			}			
		}
	}

	cout << sol(0, 0, 0);

	return 0;
}

