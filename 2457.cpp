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
vector<tuple<int, int, int, int>> fw;
//vector<pair<int, int>> current;
int current_m = 0;
int current_d = 0;
int target_m = 0;
int target_d = 0;
int total = 0;
int ans = 0;
bool finalday = false;
bool startday = false;

bool cmp(tuple<int, int, int, int >a, tuple<int, int, int, int>b)
{

	if (get<2>(a) == get<2>(b))
		return get<3>(a) > get<3>(b);
	else
		return get<2>(a) > get<2>(b);


}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int t1, t2, t3, t4;

		cin >> t1 >> t2 >> t3 >> t4;
		fw.push_back({ t1,t2,t3,t4 });

		if (t3 >= 11)
		{
			if (t3 == 11 && t4 == 30)
				finalday = true;
			else if(t3 == 12)
				finalday = true;
		}
		if (t1 <= 3)
		{
			if (t1 == 3 && t2 == 1)
				startday = true;
			else if (t1 < 3)
				startday = true;
		}

	}

	if (!finalday || !startday)
	{
		cout << 0;
		return 0;
	}

	sort(fw.begin(), fw.end(), cmp);

	current_m = 3;
	current_d = 1;

	while (current_m < 12)
	{
		if (current_m == 11 && current_d == 30)
			break;

		target_m = current_m;
		target_d = current_d;

		for (int i = 0; i < N; i++)
		{
			if ((get<0>(fw[i]) < current_m || get<0>(fw[i]) == current_m && get<1>(fw[i]) <= current_d) &&
				(get<2>(fw[i]) > target_m || get<2>(fw[i]) == target_m && get<3>(fw[i]) > target_d))
			{
				target_m = get<2>(fw[i]);
				target_d = get<3>(fw[i]);
			}
		}

		if (target_m == current_m && target_d == current_d)
		{
			cout << 0;
			return 0;
		}
		current_m = target_m;
		current_d = target_d;
		ans++;
	}
	cout << ans;
	return 0;
}