#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void swap(int* x, int* y);
void quickSort(int* a, int begin, int end);
void quickSort_plus(int* a, int begin, int end);
void quickSort_iterate(int* a, int n);
#define N 800000

int main()
{
	srand((unsigned int)time(0));
	int* a = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)//������������
	{
		a[i] = rand() % 100;
	}
	int begin = clock();
	quickSort(a, 0, N - 1);//����
	int end = clock();
	/*
	for (int i = 0; i < N; ++i)//��ӡ����
	{
		printf("%d ", a[i]);
	}
	*/
	printf("\n");
	int flag = 1;
	for (int i = 1; i < N; ++i)//�ж��Ƿ�����
	{
		if (a[i] < a[i - 1])
		{
			flag = 0;
			break;
		}
	}
	
	if (flag == 1)
	{
		printf("sorting success!\nUsing Time:%dms\n", end - begin);
	}
	else
	{
		printf("sorting failed!\n");
	}
	return 0;
}