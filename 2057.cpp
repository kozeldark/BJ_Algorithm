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

long long int N;

long long int factorial(long long int num)
{
	if (num == 0)
		return 1;
	else
		return num * factorial(num - 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	if (N == 0)
	{
		cout << "NO";
		return 0;
	}

	for (int i = 20; i >= 0; i--)
	{
		
		if (factorial(i) > N)
			continue;
		else
			N -= factorial(i);		
	}

	if (N == 0)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
