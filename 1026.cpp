// ConsoleApplication162.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;


int main()
{
	int size;
	int sum = 0;
	scanf_s("%d", &size);

	int* a = (int*)malloc(sizeof(int) * size);
	int* b = (int*)malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++)
		scanf_s("%d", &a[i]);

	for (int i = 0; i < size; i++)
		scanf_s("%d", &b[i]);
	
	sort(a, a+size);
	sort(b, b+size, greater<int>());

	for (int i = 0; i < size; i++)
	{
		sum = sum + a[i] * b[i];
	}

	printf("%d", sum);

    return 0;
}

