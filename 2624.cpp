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

int T, k;
vector <pair<int, int>> coin;
int dp[10002];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	cin >> k;
	
	for (int i = 0; i < k; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;

		coin.push_back(make_pair(t1, t2));
	}

	dp[0] = 1;

	for (int i = 0; i < k; i++)
	{
		for (int j = T; j > 0; j--)
		{
			for (int p = 1; p <= coin[i].second; p++)
			{
				if (j - (p*coin[i].first) >= 0)
					dp[j] += dp[j - (coin[i].first * p)];
			}
		}
	}

	cout << dp[T];

	return 0;
}