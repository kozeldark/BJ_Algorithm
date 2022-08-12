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

long long int A, B;
long long int ans = 0;

long long int gcd(long long int a, long long int b) 
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	cin >> A >> B;

	long long answer = gcd(A, B);

	for (int i = 0; i < answer; i++)
		cout << 1;

	return 0;
}
