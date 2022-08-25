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

int N;
int temp;
int cur_best = 0;
int up = 1;
int down = 1;
int ans = 0;
int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		if (i > 0)
		{
			if (temp >= num)
				up++;
			else
				up = 1;
			if (temp <= num)
				down++;
			else
				down = 1;
		}

		temp = num;
		cur_best = max(up, down);
		ans = max(ans, cur_best);

	}
	cout << ans;

	return 0;
}