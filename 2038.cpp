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
int num = 0;
int gol_num = 0;
vector< pair<int, int>> v;
deque<pair<int, int>> q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;


	for (int i = 0; i <= N; i++)
	{
		if (gol_num == 0)
		{
			q.push_back({ 1, 1 });
			num++;
			gol_num++;
		}
		if (num > N)
		{
			cout << gol_num - 1;
			break;
		}

		v.clear();
		v.push_back(q.front());

		num += v[0].second;
		gol_num++;

		q.push_back({ num, gol_num });

		if (gol_num >= q[1].first)
			q.pop_front();
	}

	return 0;
}
