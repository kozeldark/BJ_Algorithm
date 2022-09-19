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

int T;
int n, m;
long long int ans = 0;
long long int dp[2001][11];


long long int sol(int x, int y)
{
	if (x == 1)
		return 1;

	long long int& ret = dp[y][x];

	if (ret != -1)
		return ret;

	ret = 0;
	for (int i = 1; i <= y / 2; i++)
		ret += sol(x - 1, i);

	return ret;
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) 
	{
		cin >> n >> m;

		for (int i = 1; i <= 2000; i++)
			for (int j = 1; j <= 10; j++)
				dp[i][j] = -1;	

		ans = 0;
		for (int i = 1; i <= m; i++)
			ans += sol(n, i);

		cout << ans << endl;

	}


	return 0;
}