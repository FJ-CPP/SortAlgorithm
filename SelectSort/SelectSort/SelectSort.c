#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
/*
* ѡ������˼�룺
* �ҵ�[left,right]�����ڵ����ֵ����Сֵ��Ȼ������left��right�������ﵽ��ǰ��������ֵ�����ߵ�״̬
* left��right�ĳ�ʼֵΪ0��n-1���������������߽���ұ߽�
* ����ѭ���Ľ��У���߽�ÿ��������һλ���ұ߽�ÿ��������һλ���ﵽ��С�����Ŀ�ģ�Ȼ���ٽ���ѡ��ֵ�ͽ���
* 
* ʱ�临�Ӷ�:O(N^2)
*/
void SelectSort(int* a, int n)
{
	int left = 0, right = n - 1;
	while (left < right)
	{
		int maxIndex = left, minIndex = left;
		for (int i = left; i <= right; ++i)//�ҵ�[left,right]�����ֵ����Сֵ���±�
		{
			if (a[i] > a[maxIndex])
			{
				maxIndex = i;
			}
			if (a[i] < a[minIndex])
			{
				minIndex = i;
			}
		}
		swap(&a[left], &a[minIndex]);//����Сֵ��a[left]����
		if (left == maxIndex)//��ֹleft�����ֵ�±������£����ֵ����һ������������minIndex��λ�ã�������һ����������
		{
			maxIndex = minIndex;
		}
		swap(&a[right], &a[maxIndex]);//�����ֵ��a[right]����
		++left;
		--right;
		for (int i = 0; i < n; ++i)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
	}
}

void EasySelectSort(int* a, int n)
{
	int key;
	for (int i = 0; i < n - 1; ++i)
	{
		key = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (a[j] < a[key])
			{
				key = j;
			}
		}
		swap(&a[i], &a[key]);
		for (int i = 0; i < n; ++i)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
	}
}