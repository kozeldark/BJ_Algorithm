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
	int ans = 0;
	double max = -2147483467;
	double min = 2147483467;
	double g = 0;
	int x[51];
	double y[51];
	int i, j, k = 0;

	scanf("%d", &size);

	for (i = 1; i <= size; i++)
	{
		x[i] = i;
		scanf("%lf", &y[i]);
	}

	for (int i = 1; i <= size; i++)
	{
		//printf("----- i : %d---------------------------------\n", i);
		sum = 0;

		max = -2147483467;
		min = 2147483467;

		for (int j = i - 1; j >= 1; j--)
		{
			//printf("-----<<< j : %d----------\n", j);
			g = ((double)(y[i] - y[j]) / (double)(x[i] - x[j]));
			//printf("%f\n", g);
			if (g < min)
			{
				min = g;
				sum = sum + 1;
				//printf("%d\n", sum);
			}
		}


		for (int j = i + 1; j <= size; j++)
		{
			//printf("----->>> j : %d----------\n", j);
			g = ((double)(y[i] - y[j]) / (double)(x[i] - x[j]));
			//printf("%f\n", g);
			if (g > max)
			{
				max = g;
				sum = sum + 1;
				//printf("%d\n", sum);
			}
		}

		if (ans < sum)
			ans = sum;
	   }

	printf("%d", ans);

	//system("pause");

	return 0;

}





