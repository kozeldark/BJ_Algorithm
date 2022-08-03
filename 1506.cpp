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

using namespace std;

int N;
int ans;
int cost[100];
int graph[100][100];


int main() 
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> cost[i];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%1d", &graph[i][j]);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				if (graph[j][i] == 1 && graph[i][k] == 1)
					graph[j][k] = 1;

	for (int i = 0; i < N; i++) 
	{
		if (!cost[i]) 
			continue;

		int min = cost[i];
		cost[i] = 0;
		for (int j = 0; j < N; j++) 
		{
			if (graph[i][j] &&graph[j][i] && cost[j]) 
			{
				if (min > cost[j])
					min = cost[j];

				cost[j] = 0;
			}
		}
		ans += min;
	}
	cout << ans;

	return 0;
}