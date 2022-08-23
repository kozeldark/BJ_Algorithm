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

int n, m, c;
vector<int> v;
vector<int> ans;
priority_queue <int> pq;
multiset<int> ms;
//bool ans = false;
int mx = 0;
int mn = 10001;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> c;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	for (int i = 0; i < n; i++)
	{
		ms.insert(v[i]);

		if (i > m - 1)
			ms.erase(ms.find(v[i - m]));

		if (i >= m - 1)
		{
			//int max = *max_element(v.begin() + i, v.end() + i + m);
			//int min = *min_element(v.begin() + i, v.end() + i + m);

			mx = *(--ms.end());
			mn = (*ms.begin());

			if (mx - mn <= c)
			{
				//cout << i << "\n";
				ans.push_back(i - m + 2);
			}
		}
	}

	if (ans.size() != 0)
	{
		for(int i=0; i < ans.size(); i++)
			cout << ans[i] << "\n";
	}
	else
		cout << "NONE" << "\n";


	return 0;
}