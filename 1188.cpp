// ConsoleApplication162.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

double N, M;

int GCD(int a, int b)
{
	if (a%b == 0)
		return b;

	return GCD(b, a%b);
}



int main(void)
{
	cin >> N >> M;
	if ((N /M) - int(N / M) == 0)
		cout << '0';
	else
		cout << M - GCD(N, M);

	return 0;
}


