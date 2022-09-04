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

int N, M;
int ans = 0;
int arr[101][101];
int visited[101];

void dfs(int n)
{
	visited[n] = 1;

	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == 0 && arr[n][i] == 1)
		{
			ans++;
			dfs(i);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	cin >> M;
	
	for (int i = 0; i < M; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		arr[t1][t2] = 1;
		arr[t2][t1] = 1;
	}

	dfs(1);

	cout << ans;

	return 0;
}