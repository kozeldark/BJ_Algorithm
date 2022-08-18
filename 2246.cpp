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

int N, D, C;
vector <pair<int, int>> v;
int ans = 0;
bool chk;

int main()
{

	cin >> N;
	vector<pair<int, int> > v;

	for (int i = 0; i < N; i++)
	{
		cin >> D >> C;
		v.push_back(make_pair(D, C));
	}
		

	for (int i = 0; i < N; i++)
	{
		chk = false;
		for (int j = 0; j < N; j++)
		{
			if (i != j)
			{
				if (v[i].first > v[j].first)
				{
					if (v[i].second >= v[j].second)
					{
						chk = true;
						break;
					}
				}
				else if (v[i].second > v[j].second)
				{
					if (v[i].first >= v[j].first)
					{
						chk = true;
						break;
					}
				}
			}
		}
		if (!chk)
			ans++;
	}

	cout << ans;

	return 0;
}
