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
string number;
int num[6];
vector <int> ans;

int sol(int num)
{
	int result = 0;
	while (num != 0)
	{
		int temp = num % 10;
		result += temp;
		num /= 10;
	}
	return result;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> N)
	{
		if (N == 0)
			break;

		while (N >= 10) 
		{
			int temp;
			temp = sol(N);
			N = temp;
		}
		ans.push_back(N);
		
	}
	for (auto elem : ans)
		cout << elem << endl;
	return 0;
}
