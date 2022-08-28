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
int stu[101];
int cnt = 0;
vector<tuple<int,int,int>> v;

bool cmp(tuple<int, int, int> &a, tuple<int, int, int> &b)
{
	return get<2>(a) > get<2>(b);
}

int main() 
{
	cin >> N;

	for (int i = 0; i < N; i++) 
	{
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;

		v.push_back({ t1, t2, t3 });
		stu[i] = 2;
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++)
	{
		if (cnt == 3)
			break;

		if (stu[get<0>(v[i])] > 0) 
		{
			cout << get<0>(v[i]) << ' ' << get<1>(v[i]) << endl;
			cnt++;
			stu[get<0>(v[i])]--;
		}
	}
}