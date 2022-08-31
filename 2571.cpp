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

int arr[101][101];
int N;
int ans = 100;
int area = 0;

bool chk(int x1, int y1, int x2, int y2)
{
	for (int x = x1; x <= x2; x++)
		for (int y = y1; y <= y2; y++)
			if (arr[x][y] == 0)
				return false;

	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int k = 0; k < N; k++)
	{
		int x, y;
		cin >> x >> y;

		for (int i = y; i < y + 10; i++)
			for (int j = x; j < x + 10; j++)
				arr[i][j] = 1;
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (arr[i][j] == 0)
				continue;

			for (int k = i + 1; k < 100; k++)
			{
				for (int t = j + 1; t < 100; t++)
				{
					if (arr[k][t] == 0)
						break;

					area = (k - i + 1) * (t - j + 1);

					if (chk(i, j, k, t))
						ans = max(ans, area);
				}
			}
		}
	}


	cout << ans;

	return 0;

}