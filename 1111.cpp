// ConsoleApplication162.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int N, M;
int max = 0;
bool find1, find2 = false;
int num[50];

int main() 
{
	int a = 0, b = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> num[i];
	
	if (N == 1)
	{
		cout << "A";
		return 0;
	}
	else if (N == 2)
	{
		if (num[0] == num[1])
		{
			cout << num[0];
			return 0;
		}
		else
		{
			cout << "A";
			return 0;
		}
	}
	if ((num[1] - num[0]) != 0)
		a = (num[2] - num[1]) / (num[1] - num[0]);
	else
		a = 0;

	b = num[1] - num[0] * a;

	for (int i = 0; i < N - 1; i++)
	{
		if (num[i] * a + b != num[i + 1])
		{
			cout << "B";
			return 0;
		}
	}

	cout << num[N - 1] * a + b;

	return 0;

}

