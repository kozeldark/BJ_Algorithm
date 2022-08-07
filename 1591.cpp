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

using namespace std;

int N, M;
int ans = 0;
//int clear[1001];
//int front[1001];
//int rear[1001];
int cnt = 0, fcnt = 0, rcnt = 0;
int arr[1010][1010];

vector<int> circuit;
vector<vector<int>> adj(1010, vector<int>(1010, 0));
vector<int> indegree(1010, 0);
vector<int> outdegree(1010, 0);

map<vector<int>, int> idx;
map<int, vector<int>> vtx;

void getEulerCircuit(int node, vector<int> &circuit)
{
	for (int i = 0; i < adj[node].size(); i++) {
		while (adj[node][i] > 0) {
			adj[node][i]--;
			getEulerCircuit(i, circuit);
		}
	}
	circuit.push_back(node);
}

vector<int> getEulerTrailOrCircuit()
{
	//  find trail
	for (int i = 0; i < N; i++) {
		if (outdegree[i] == indegree[i] + 1) {
			getEulerCircuit(i, circuit);
			return circuit;
		}
	}
	//  find circuit
	for (int i = 0; i < N; i++) {
		if (outdegree[i]) {
			getEulerCircuit(i, circuit);
			return circuit;
		}
	}
	//  else
	return circuit;
}
//오일러경로 참고 및 공부한 링크 https://hy38.github.io/posts/euilerian-circuit-and-trail/


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N - M + 1; ++i)
		for (int j = 0; j < M; ++j)
			cin >> arr[i][j];

	
	for (int i = 0; i < N - M + 1; i++) 
	{
		vector<int> front(arr[i], arr[i] + M - 1);
		vector<int> rear(arr[i] + 1, arr[i] + M);

		if (idx.count(front) == 0)
		{
			vtx[cnt] = front;
			idx[front] = cnt;	
			cnt++;
		}
		if (idx.count(rear) == 0)
		{
			vtx[cnt] = rear;
			idx[rear] = cnt;
			cnt++;
		}

		fcnt = idx[front];
		rcnt = idx[rear];
		
		adj[fcnt][rcnt]++;
		outdegree[fcnt]++;
		indegree[rcnt]++;

	}

	getEulerTrailOrCircuit();
	reverse(circuit.begin(), circuit.end());

	for (int i = 0; i< circuit.size() - 1; i++) 
		cout << vtx[circuit[i]][0] << ' ';


	for (auto k : vtx[circuit[circuit.size() - 1]]) 
		cout << k << ' ';

	return 0;
}
