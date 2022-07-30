#define _CRT_SECURE_NO_WARNINGS 1
#include <cstdio>
void swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
/*
* ð������˼�룺
* ����n���������飬Ҫ����n-1�֡�ð�ݡ���ÿһ�ֽ����ֵ���ֵ����������λ��
* ��һ��ð�ݵ����������ٲ�����һ��ð��
* ÿһ�ֲ���ð�ݵ������Կ���һ���飬��ð��������ǽ�ÿһ�����ֵ�ŵ�����λ��
* 
* ʱ�临�Ӷȣ����O(N),�O(N^2)
*/
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int flag = 1;
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (a[j + 1] > a[j])
			{
				swap(&a[j + 1], &a[j]);
				flag = 0;
			}
		}
		for (int i = 0; i < n; ++i)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
		if (flag == 1)
		{
			break;
		}
	}
}