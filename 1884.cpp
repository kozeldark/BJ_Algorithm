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

int K, N, R;
int ans = 10001;
vector<tuple<int, int, int> > vec[101];
int d[101][10001];

void dijkstra() 
{
	priority_queue<tuple<int, int, int>> pq;
	pq.push({ 1, 0, K });

	while (!pq.empty()) 
	{
		int current = get<0>(pq.top());
		int distance = -get<1>(pq.top());
		int transfee = get<2>(pq.top());
		
		pq.pop();
	
		if (d[current][current] < distance)
			continue; 

		for (int i = 0; i < vec[current].size(); i++)
		{
			int next = get<0> (vec[current][i]);
			int nextDistance = distance + get<1>(vec[current][i]);
			int nextFee = get<2>(vec[current][i]);

			if(transfee < nextFee)
				continue;

			if (nextDistance < d[next][transfee - nextFee]) 
			{
				d[next][transfee - nextFee] = nextDistance;
				pq.push({ next, -nextDistance, transfee - nextFee });
			}
		}
	}
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> K;
	cin >> N;
	cin >> R;

	for (int i = 2; i <= N; i++)
		for (int j = 0; j <= K; j++)
			d[i][j] = 10001;

	for (int i = 0; i < R; i++)
	{
		int r1, r2, dis, fee;

		cin >> r1 >> r2 >> dis >> fee;

		vec[r1].push_back(make_tuple(r2, dis, fee));
	}

	dijkstra();


	for (int i = 0; i <= K; i++) 
		ans = min(ans, d[N][i]);

	if (ans == 10001)
		cout << -1;
	else 
		cout << ans;

	return 0;
}