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

int D, K;
int arr[31][2];
int ans = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> D >> K;

	arr[1][0] = 1;
	arr[2][1] = 1;

	for (int i = 3; i < 31; i++) 
	{
		arr[i][0] = arr[i - 2][0] + arr[i - 1][0];
		arr[i][1] = arr[i - 2][1] + arr[i - 1][1];
	}

	for (int i = 1; i < 1000000; i++) 
	{
		for (int j = 1; j < 1000000; j++) 
		{
			if ((i * arr[D][0]) + (j * arr[D][1]) == K) 
			{
				cout << i << endl << j;
				return 0;
			}
		}
	}

	return 0;
}