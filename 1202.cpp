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

int N, M;

/*
struct jew
{
	long long int m;
	long long int v;
};
jew jewel[1000000];
*/

long long int bag[300000];

pair<int, int> jewel[300000];
priority_queue<int> pq;


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
		cin >> jewel[i].first >> jewel[i].second;

	for (int i = 0; i < M; i++)
		cin >> bag[i];


	//qsort(jewel, N, sizeof(jewel[0]), compare);
	sort(jewel, jewel + N);
	sort(bag, bag + M);

	int select[300000];

	long long int max = 0;
	long long int ans = 0;
	int idx = 0;

	for (int i = 0, j = 0; i < M; ++i) 
	{
		while (j < N && jewel[j].first <= bag[i]) 
		{
			pq.push(jewel[j++].second);
		}
		if (!pq.empty()) 
		{
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans;

	return 0;
}


//파이썬으로 할걸;;