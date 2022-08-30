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
int ans = 0;

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
		for (int j = 0; j < 100; j++)
			if (arr[i][j] == 1)
			{
				if (arr[i][j-1] == 0)
					ans++;
				if (arr[i][j+1] == 0)
					ans++;
				if (arr[i-1][j] == 0)
					ans++;
				if (arr[i+1][j] == 0)
					ans++;

			}


	cout << ans;

	return 0;

}
