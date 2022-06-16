// ConsoleApplication162.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

typedef struct cocktail {
	int val = 1;
	int idx = -1;
};

cocktail ct[11];

long gcd(long  a, long  b)
{
	return b == 0 ? a : gcd(b, a % b);
}


void dfs(int root, int val, int line, int level, int size) 
{
	int branch = ct[root].idx;

	ct[root].val *= val;
	ct[root].idx = line;

	if (level == 1 && branch != -1)
	{
		for (int i = 0; i < size; i++) 
		{
			if (ct[i].idx == branch && i != root)
				dfs(i, val, line, 2, size);
		}
	}
}


int main()
{
	int size;
	//int sum = 0;
	//int ans = 0;
	int a, b, p, q;
	int i, j, k = 0;
	int g;
	int a_after, b_after;

	scanf("%d", &size);

	for (int i = 0; i < size; i++) {
		ct[i].val = 1;
		ct[i].idx = -1;
	}


	for (i = 0; i < size - 1; i++)
	{
		scanf("%d %d %d %d", &a, &b, &p, &q);

		g = gcd(p, q);
		a_after = ct[b].val *p / g ;
		b_after = ct[a].val *q / g ;

		g = gcd(a_after, b_after);

		//printf("%d %d %d\n", a_after, b_after, g);

		dfs(a, (a_after / g), i, 1, size);
		dfs(b, (b_after / g), i, 1, size);
	}

	for (i = 0; i < size; i++)
		printf("%d ", ct[i].val);

	//system("pause");

	return 0;

}



