#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* x, int* y);
void SelectSort(int* a, int n);
void EasySelectSort(int* a, int n);
#define N 30

int main()
{
	int a[] = { 12, 15, 7, 9, 14, 31, 18, 4, 14 };
	SelectSort(a, sizeof(a) / sizeof(int));
	/*srand((unsigned int)time(0));
	int* a = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a[i] = rand() % 100;
	}
	int begin = clock();
	SelectSort(a, N);
	int end = clock();
	for (int i = 0; i < N; ++i)
	{
		printf("%d ", a[i]);
	}
	int flag = 1;
	for (int i = 1; i < N; ++i)
	{
		if (a[i] < a[i - 1])
		{
			flag = 0;
			break;
		}
	}
	printf("\n");
	if (flag == 1)
	{
		printf("sorting success!\nUsing Time:%dms\n", end - begin);
	}
	else
	{
		printf("sorting failed!\n");
	}*/
	return 0;
}