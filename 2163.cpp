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

int N, M;


int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	cout << (N*M)-1;
}