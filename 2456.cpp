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

int N;
pair<int, int> arr[3];
pair<int, int> cop[3];

bool cmp(pair<int, int>a, pair<int, int>b)
{

	if (a.first == b.first) 
		return a.second > b.second;

	else 
		return a.first > b.first;

}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int temp;
			cin >> temp;

			arr[j].first += temp;
			arr[j].second += temp*temp;
		}
	}
	int s1 = arr[0].first;
	int s2 = arr[1].first;
	int s3 = arr[2].first;

	int sum1 = arr[0].second;
	int sum2 = arr[1].second;
	int sum3 = arr[2].second;

	sort(arr, arr + 3, cmp);

	if (arr[0].first > arr[1].first)
	{
		if (arr[0].first == s1)
			cout << 1 << " " << arr[0].first << endl;
		else if (arr[0].first == s2)
			cout << 2 << " " << arr[0].first << endl;
		else if (arr[0].first == s3)
			cout << 3 << " " << arr[0].first << endl;
	}
	else
	{
		if (arr[0].second == arr[1].second)
			cout << 0 << " " << arr[0].first << endl;
		else if (arr[0].second == sum1)
			cout << 1 << " " << arr[0].first << endl;
		else if (arr[0].second == sum2)
			cout << 2 << " " << arr[0].first << endl;
		else if (arr[0].second == sum3)
			cout << 3 << " " << arr[0].first << endl;
	}




	return 0;
}