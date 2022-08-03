// ConsoleApplication162.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
int ans = 0;
int mintime[21][21];
int time[21][21];


int main() 
{
	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> mintime[i][j];

	copy(&mintime[0][0], &mintime[0][0] + 441, &time[0][0]);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			for (int k = 1; k <= N; k++)
			{
				if (i == j || i == k || j == k)
					continue;
				if (mintime[j][k] == mintime[j][i] + mintime[i][k])
				{
					//printf("%d %d %d\n", j, k, time[j][k]);
					time[j][k] = 0;
				}
				else if (mintime[j][k] > mintime[j][i] + mintime[i][k])
					ans = -1;
			}

	
	if (ans == -1)
		cout << ans;
	else
	{
		for (int i = 1; i <= N; i++)
			for (int j = i; j <= N; j++)
					ans += time[i][j];

		cout << ans;
	}

	return 0;
}