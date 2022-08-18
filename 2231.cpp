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

int N;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i < N; i++)
	{
		int sum = i;
		int tmp = i;
		while (tmp)
		{
			sum += tmp % 10;
			tmp /= 10;
		}
		if (sum == N)
		{
			cout << i;
			return 0;
		}
	}
	cout << 0;
	
	return 0;
}