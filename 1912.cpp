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
int ans = 0;
vector <int> arr;
vector <int> sum;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		arr.push_back(num);
	}

	sum.push_back(arr[0]);

	for (int i = 1; i < N; i++)
	{
		

		if (sum[i - 1] > 0)
			sum.push_back(sum[i - 1] + arr[i]);
		else
			sum.push_back(arr[i]);
	}

	sort(sum.begin(), sum.end(), greater<int>());


	cout << sum[0];

	return 0;
}