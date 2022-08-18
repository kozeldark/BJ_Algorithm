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

int N;
using namespace std;
int arr[10];
int sum = 0;

int main()
{
	
	for (int i = 0; i < 9; i++) 
	{
		cin >> arr[i];
		sum += arr[i];
	}

	sort(arr, arr + 9);

	for (int i = 0; i < 8; i++) 
	{
		for (int j = 1; j < 9; j++) 
		{
			if (sum - (arr[i] + arr[j]) == 100) 
			{
				for (int k = 0; k < 9; k++) 
				{
					if (k == i || k == j) 
						continue;
					cout << arr[k] << endl;
				}
				return 0;
			}
		}
	}
	return 0;
}
