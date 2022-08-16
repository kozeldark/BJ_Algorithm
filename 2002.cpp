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
map<string, int> car;
vector<string> after(1001);
int ans = 0;

int main() 
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		car[temp] = i;
	}
		
	for (int i = 0; i < N; i++)
		cin >> after[i];

	for (int i = 0; i < N; ++i) 
	{
		for (int j = i + 1; j < N; ++j) 
		{
			if (car[after[i]] > car[after[j]]) 
			{
				ans += 1;
				break;
			}
		}
	}
	cout << ans;

	return 0;
}