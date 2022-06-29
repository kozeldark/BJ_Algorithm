// ConsoleApplication162.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

using namespace std;

long long int A, B;

long long int sol(long long int n, long long int div)
{
	long long int cnt = n;

	while (div <= n)
	{
		cnt += (n / div)*(div / 2);
		div *= 2;
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> A >> B;

	cout << sol(B, 2) - sol(A - 1, 2);

	return 0;
}