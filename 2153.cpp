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
int sum = 0;
string str;
bool IsPrime(int num)
{
	int lcnt = 0;
	for (lcnt = 2; lcnt < num; lcnt++)
	{
		if ((num % lcnt) == 0)
			return false;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 97 && str[i] <= 122)
			sum += str[i] - 96;

		else
			sum += str[i] - 38;
	}

	if (IsPrime(sum))
		cout << "It is a prime word.";
	else
		cout << "It is not a prime word.";

	return 0;
}
