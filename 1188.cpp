// ConsoleApplication162.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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


