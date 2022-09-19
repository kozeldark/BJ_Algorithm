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

int N, M;

int ans[201];
int idx[201];
int visit[201];
int cnt = 0;

int lt[201];
int rt[201];
int mn[201];
int mx[201];

vector <int> v[201];

int dfs(int n) 
{	
	if (visit[n]) 
		return 0;

	visit[n] = 1;

	for (int i = 0; i < (int)v[n].size(); i++)
	{
		if (ans[v[n][i]] == -1 || dfs(ans[v[n][i]]))
		{
			ans[v[n][i]] = n;
			idx[n] = i;

			return 1;
		}
	}
	return 0;
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) 
	{
		mn[i] = lt[i] = 0;
		mx[i] = rt[i] = N -1;
	}

	for (int i = 0; i < M; i++) 
	{
		int type, st, fn, val;

		cin >> type >> st >> fn >> val;

		lt[val - 1] = max(lt[val - 1], st);
		rt[val - 1] = min(rt[val - 1], fn);

		for (int j = st - 1; j < fn; j++) 
		{
			if (type == 1) 
				mx[j] = min(mx[j], val);
			else 
				mn[j] = max(mn[j], val);
		}
		
	}

	memset(ans, -1, sizeof ans);
	memset(idx, -1, sizeof idx);

	for (int i = 0; i < N; i++)
		for (int j = lt[i]; j <= rt[i]; j++)
			if (i >= mn[j] && i <= mx[j])
			{
				v[i].push_back(j);
			}

	for (int i = 0; i < N ; i++)
	{
		if (idx[i] == -1) 
		{
			memset(visit, 0, sizeof visit);
			cnt += dfs(i);
		}
	}
	
	if (cnt == N) 
	{
		for (int i = 0; i < N; i++)
			cout << ans[i]+1 << ' ';
	}
	else 
		cout << -1;


	return 0;
}
