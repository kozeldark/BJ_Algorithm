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

using namespace std;

int N;
int ans = 0;
vector<int> arr;
vector<int> sum;
int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	 cin >> N;

	 for (int i = 0; i < N; i++)
	 {
		 int temp;
		 cin >> temp;
		 arr.push_back(temp);
	 }

	sort(arr.begin(), arr.end(), greater<int>());


	for (int i = 0; i<N; i++)
		for (int j = 0; j<N; j++)
			sum.push_back(arr[i] + arr[j]);
	
	sort(sum.begin(), sum.end());


	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) 
		{
			int minus = arr[i] - arr[j];
			ans = binary_search(sum.begin(), sum.end(), minus);

			if (ans) 
			{
				cout << arr[i];
				return 0;
			}
		}
	
}