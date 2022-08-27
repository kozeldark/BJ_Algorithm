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

int N, P;
int arr[1001];
int cnt = 0;
int mod = 0;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> P;

	mod = N;
	while (arr[mod] == 0)
	{
		
		arr[mod] = cnt++;
		mod = mod * N % P;
	}

	cout << cnt - arr[mod] << endl;

	return 0;
}