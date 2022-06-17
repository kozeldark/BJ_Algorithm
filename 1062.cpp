// ConsoleApplication162.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int result = 0;
int sum = 0;
string word[50];
bool can[26];
int ans;

int N;
int k;

void comb(int idx, int cnt) 
{
	if (k - 5 == cnt) 
	{
		int sum = 0;
		for (int i = 0; i < N; i++) 
		{
			bool check = true;
			for (int j = 0; j < word[i].size(); j++)
			{
				if (!can[word[i][j] - 97]) 
				{
					check = false;
					break;
				}
			}
			if (check)
				sum++;
		}
		if (sum > ans)
			ans = sum;
		return;
	}

	for (int i = idx; i < 26; i++) 
	{
		if (!can[i])
		{
			can[i] = true;
			comb(i, cnt + 1);
			can[i] = false;
		}
	}
}
int main() 
{
	cin >> N >> k;

	for (int i = 0; i < N; i++)
		cin >> word[i];

	for (int i = 0; i < sizeof(can); i++)
		can[i] = 0;

	// a n t i c 고정
	can[0] = 1, can[13] = 1, can[19] = 1, can[8] = 1, can[2] = true;


	if (k < 5) 
	{
		printf("0");
	}
	else 
	{
		comb(0, 0);
		printf("%d", ans);
	}
	
	return 0;

}