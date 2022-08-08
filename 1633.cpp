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

int cost[1001][2];
int team[1001][16][16];
int ans = 0;
int siz = 0;

int sol(int idx, int wcnt, int bcnt) 
{
	if (idx == siz) 
		return 0;

	if (team[idx][wcnt][bcnt] != -1) 
		return team[idx][wcnt][bcnt];

	if (wcnt <15) 
		team[idx][wcnt][bcnt] = max(team[idx][wcnt][bcnt], cost[idx][0] + sol(idx + 1, wcnt + 1, bcnt));

	if (bcnt <15) 
		team[idx][wcnt][bcnt] = max(team[idx][wcnt][bcnt], cost[idx][1] + sol(idx + 1, wcnt, bcnt + 1));

	team[idx][wcnt][bcnt] = max(team[idx][wcnt][bcnt], sol(idx + 1, wcnt, bcnt));

	return team[idx][wcnt][bcnt];
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> cost[siz][0] >> cost[siz][1])
		siz++;

	memset(team, -1, sizeof(team));

	cout << sol(0, 0, 0) << endl;

	return 0;
}
