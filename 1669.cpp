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

int mon, dog;
int ans = 0;
int sq = 0;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> mon >> dog;

	if (mon == dog)
	{
		cout << '0';
		return 0;
	}
	

	sq = sqrt(dog - mon);
	

	mon += sq*sq;
	ans = 2 * sq - 1;

	while (mon != dog) 
	{
		if (dog - mon > sq)
			mon += sq;
		else
			mon += dog - mon;
		ans++;
	}

	cout << ans;

	return 0;
}
