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
long long int point[1501][2];
long long int tri[3][2];
int ans = 0;

void sol(int num, int idx)
{
	if (idx > 2)
	{
		long long int a, b, c;
		a = pow((tri[1][0] - tri[0][0]), 2) + pow((tri[1][1] - tri[0][1]), 2);
		b = pow((tri[1][0] - tri[2][0]), 2) + pow((tri[1][1] - tri[2][1]), 2);
		c = pow((tri[0][0] - tri[2][0]), 2) + pow((tri[0][1] - tri[2][1]), 2);

		if (a < b) 
			swap(a, b);
		if (a < c) 
			swap(a, c);

		if(a==b+c)
			ans++;	

		return;

	}

	if (num > N - 1)
		return;

	tri[idx][0] = point[num][0];
	tri[idx][1] = point[num][1];

	sol(num + 1, idx + 1);
	sol(num + 1, idx);

}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 2; j++)
			cin >> point[i][j];	

	sol(0, 0);

	cout << ans;

	return 0;
}
