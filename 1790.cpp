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
long long int ans;
long long int K;
long long int num = 1;
long long int cnt = 9;
long long int len = 1;
string anstr;

int main() 
{
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	cin >> N >> K;

	while (K > num * cnt)
	{
		K -= (num * cnt);
		ans += cnt;

		cnt *= 10;
		num++;
	}
	ans += (K - 1) / num + 1;
	anstr = to_string(ans);

	if (ans > N)
		cout << -1;
	else
		cout << anstr[(K - 1) % num];

	return 0;
}
