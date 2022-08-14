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

int x, y;
int ans = 0;
int sum = 0;
int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
string day[7] = { "SUN","MON","TUE","WED","THU","FRI","SAT", };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> x >> y;

	for (int i = 0; i< x - 1; i++) 
		sum += month[i];

	ans = (sum + y) % 7;

	cout << day[ans];

	return 0;
}