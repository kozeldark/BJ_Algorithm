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
vector <int> v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	
	for (int i = 1; i <= N; i++) 
	{
		vector<int> temp;
		temp.push_back(N);
		temp.push_back(i);

		int cur = 1;
		while(1)
		{		
			if (temp[cur - 1] - temp[cur]<0) 
				break;
			temp.push_back(temp[cur - 1] - temp[cur]);
			cur++;
		}
		if (temp.size() > v.size())
			v = temp;
	}

	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';

	return 0;
}