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

int A, B;
int ans = 0;
int a_tmp, b_tmp;

 int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
 /*
 int lcm(int a, int b)
 {
	 return a * b / gcd(a, b);
 }
 */

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> A >> B;
	B = B / A;

	for (int i = 1; i <= sqrt(B); i++)
	{
		if (B % i == 0)
		{
			if (gcd(i, B / i) == 1)
			{
				a_tmp = i, b_tmp = B / i;

			}
		}
	}
	cout << a_tmp * A << ' ' << b_tmp * A;

	return 0;
}