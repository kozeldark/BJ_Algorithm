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

int N;
int A[2001];
int ans = 0;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> A[i];

	sort(A, A + N);

	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			if (i == j) 
				continue;

			auto idx = lower_bound(A, A + N, A[i] - A[j]) - A;

			if (idx == i || idx == j && A[idx] == A[idx + 1])
				idx++;

			if (idx == i || idx == j)
			{
				continue;
			}


			if (A[idx] + A[j] == A[i]) 
			{
				ans++; 
				break;
			}
		}
	}

	cout << ans;

	//system("pause");

	return 0;
}

