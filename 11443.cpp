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

long long N;
long long ans = 0;
//long long arr[] = { 0, 1, 1, };
//f[2n] = f[n]*(2f[n-1] + f[n])
//f[2n+1] = f[n]^2 + f[n+1]^2
map<long long, long long> m;

long long sol(long long n)
{
	if (m.count(n) > 0)
		return m[n];

	if (n % 2 == 0)
	{
		long long cur = n / 2;
		m[n] = (sol(cur) * (2 * sol(cur - 1) + sol(cur))) % 1000000007;
		return m[n];
	}
	else
	{
		long long cur = (n + 1) / 2;
		m[n] = (sol(cur) * sol(cur) + sol(cur - 1) * sol(cur - 1)) % 1000000007;
		return m[n];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	m.insert({ 0, 0 });
	m.insert({ 1, 1 });
	m.insert({ 2, 1 });

	if (N % 2 == 1)
		cout << sol(N) - 1;
	else
		cout << sol(N + 1) - 1;

	return 0;
}