// ConsoleApplication162.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

using namespace std;

long long int A = 1, B = 1;
int G;
int ans;
int cnt = 0;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> G;


	while (1)
	{
		if (A - B == 1 && pow(A, 2) - pow(B, 2) > G)
			break;
		else if (pow(A, 2) - pow(B, 2) < G)
			A++;
		else if (pow(A, 2) - pow(B, 2) > G)
			B++;
		else
		{
			cout << A << endl;
			B++;
			cnt++;	
		}
	}

	if(cnt ==0)
		cout << -1 << endl;

	return 0;
}