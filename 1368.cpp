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

using namespace std;

struct edge
{
	int u, v, w;
};

int N;
int ans;
int idx[307];
int val;
int cnt = 0;

edge non[301 * 301];
bool visited[307][307];

int find(int x) 
{
	if (idx[x] == x) 
		return x;
	else 
		return idx[x] = find(idx[x]);
}

bool cmp(edge a, edge b) 
{
	return a.w < b.w;
}

int main() 
{
	cin >> N;

	for (int i = 1; i <= N; i++) 
	{ 
		cin >> non[++cnt].w;
		non[cnt].u = 0;
		non[cnt].v = i;

		idx[i] = i;
	}
		

	for (int i = 1; i <= N; i++) 
	{
		for (int j = 1; j <= N; j++) 
		{
			cin >> val;

			if (i != j && !visited[i][j] && !visited[j][i]) 
			{
				non[++cnt].u = i;
				non[cnt].v = j;
				non[cnt].w = val;

				visited[i][j] = true;
				visited[j][i] = true;
			}
		}
	}

	sort(non + 1, non + 1 + cnt, cmp);

	for (int i = 1; i <= cnt; i++) 
	{
		int x = find(non[i].u);
		int y = find(non[i].v);
		int load = 0;

		if (load == N)
			break;

		if (x != y) 
		{
			idx[x] = find(y);
			ans += non[i].w;
			load++;
		}
	}
	cout << ans;

	return 0;
}