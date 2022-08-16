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
int cnt = 0;
int a[15001];

int main() 
{
	cin >> N;
	cin >> M;

	for (int i = 0; i<N; i++)
		cin >> a[i];

	sort(a, a + N);

	if (M>200000) 
		cout << 0 << "\n";

	else 
	{
		for (int i = 0; i<N; i++) 
		{
			for (int j = i + 1; j<N; j++) 
			{
				if (M == a[i] + a[j])
					cnt++;
			}
		}
		cout << cnt << endl;
	}

	return 0;
}