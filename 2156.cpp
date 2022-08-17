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
vector<int> v;
vector<int> dp;


int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < 3; i++)
	{
		v.push_back(0);
		dp.push_back(0);
	}

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	for (int i = 3; i < N + 3; i++)
		dp.push_back(max(max(dp[i - 3] + v[i - 1] + v[i], dp[i - 2] + v[i]), dp[i - 1]));

	cout << dp.back();

}