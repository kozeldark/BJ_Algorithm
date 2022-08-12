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

int N;
int num[101];
string str[101];
//vector <string> str;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str[i];

		num[i] = ((str[i][0] -65) *26*26) + ((str[i][1] - 65) * 26) + (str[i][2] - 65) 
			- (((str[i][4] - 48)*1000) + ((str[i][5] - 48) * 100) + ((str[i][6] - 48) * 10) + ((str[i][7] - 48)));

	}
	for (int i = 0; i < N; i++)
	{

		if (abs(num[i]) <= 100)
			cout << "nice" << endl;
		else
			cout << "not nice"  << endl;
	}

	return 0;
}
