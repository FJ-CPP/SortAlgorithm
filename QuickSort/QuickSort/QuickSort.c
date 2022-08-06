#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"
void swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
/*
* ��������˼�룺
* 1�������㷨��ÿ������ȡһ��keyֵ����С��key��ֵ����key��ߣ�����key������key�ұߣ�Ȼ����keyΪ�ֽ��ߣ��ٶ����ҵ����������ͬ�Ĳ�����
* 
* 2�������㷨�������ڷ��Σ�����ȡ���ǵ����ķ�ʽ����ջ�����´�Ҫ��������ұ߽磬�����ڶ������Ĳ��������
* ʱ�临�Ӷȣ�O(NlogN)
* �ռ临�Ӷȣ�O(logN)
*/

//���������㷨
//1��Hoare�汾������ָ�뷨��
int hoare_partSort(int* a, int left, int right)
{
	int keyIndex = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[keyIndex])//right������С��key����
		{
			--right;
		}
		while (left < right && a[left] <= a[keyIndex])//left�����Ҵ���key����
		{
			++left;
		}
		swap(&a[left], &a[right]);//����a[left]��a[right]
	}
	swap(&a[keyIndex], &a[left]);//����ٽ�key��a[right]����������right���ߣ������ֹʱ��a[right]��ȻС��key��
	return left;//right��Ϊleft��right�������㣬Ҳ��key����λ��
}

//2���ڿӷ�
int digHole_partSort(int* a, int left, int right)
{
	//��key�����ó�������ʱleft��Ϊһ����λ�ȴ��������
	int key = a[left];
	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			--right;
		}
		//�ұ��ҵ�һ����keyС������Ȼ��right���ߵ�left��λ�У���ʱright��Ϊһ����λ�ȴ��������
		a[left] = a[right];
		while (left < right && a[left] <= key)
		{
			++left;
		}
		//����ҵ�һ����key�������Ȼ��left��ұߵ�right��λ�У���ʱleft�ֳ�Ϊһ����λ�ȴ��������
		a[right] = a[left];
	}
	//left��right��������ʱ��key��䵽��λ��(�����㼴Ϊ��λ����Ϊ��λ��Զ��left��right)
	a[right] = key;
	return right;
}

//3��ǰ��ָ�뷨
int partSort(int* a, int left, int right)
{
	int slow = left;
	int fast = left + 1;
	int keyIndex = left;
	while (fast <= right)
	{
		if (a[fast] < a[keyIndex] && ++slow != fast)//�ڶ����жϱ���һ��ʼfast��С��key������slow++���Լ����Լ�����
		{
			swap(&a[slow], &a[fast]);
		}
		++fast;
	}
	swap(&a[keyIndex], &a[slow]);
	return slow;
}

//���������Ż�(����������������ʱ�㷨��ʱ�临�Ӷ��˻���O(N^2))
//����ȡ�з�ȷ��key
int getMid(int* a, int left, int right)
{
	int mid = (left + right) >> 1;
	if (a[left] > a[mid])
	{
		if (a[mid] > a[right])//left>mid>right
			return mid;
		else if (a[left] > a[right])//left>right>mid
			return right;
		else//right>left>mid
			return left;
	}
	else//left <= mid
	{
		if (a[mid] < a[right])//right>mid>left
			return mid;
		else if (a[left] < a[right])//mid>right>left
			return right;
		else//mid>left>right
			return left;
	}
}
int digHole_partSort_plus(int* a, int left, int right)
{
	//��key�����ó�������ʱleft��Ϊһ����λ�ȴ��������
	int keyIndex = getMid(a, left, right);//����ȡ�з�ȷ��key��������left/right/mid��
	swap(&a[left], &a[keyIndex]);//ʼ��������ߵ�����key����˽���a[left]��a[keyIndex]
	while (left < right)
	{
		while (left < right && a[right] >= a[keyIndex])
		{
			--right;
		}
		//�ұ��ҵ�һ����keyС������Ȼ��right���ߵ�left��λ�У���ʱright��Ϊһ����λ�ȴ��������
		a[left] = a[right];
		while (left < right && a[left] <= a[keyIndex])
		{
			++left;
		}
		//����ҵ�һ����key�������Ȼ��left��ұߵ�right��λ�У���ʱleft�ֳ�Ϊһ����λ�ȴ��������
		a[right] = a[left];
	}
	//left��right��������ʱ��key��䵽��λ��(�����㼴Ϊ��λ����Ϊ��λ��Զ��left��right)
	a[right] = a[keyIndex];
	return right;
}


//���������㷨
//1���ݹ鷨
void quickSort(int* a, int begin, int end)
{
	if (begin >= end)//��������ֻ��һ������û������ʱ����������ֱ�ӷ���
	{
		return;
	}
	int keyIndex = partSort(a, begin, end);
	//��ʱ��������Ľ�����key��λ��ȷ����ֻ��Ҫ�ݹ齫key��ߺ��ұߵ����н�������(���ƶ�������ǰ�����)
	quickSort(a, begin, keyIndex - 1);
	quickSort(a, keyIndex + 1, end);
}

//2���ݹ鷨�Ż���С�����Ż������ٵݹ飩
void insertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int insert = a[i + 1];
		int end = i;
		while (end >= 0)
		{
			if (a[end] > insert)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = a[end];
	}
}
void quickSort_plus(int* a, int begin, int end)
{
	if (begin >= end)//��������ֻ��һ������û������ʱ����������ֱ�ӷ���
	{
		return;
	}
	if (end - begin > 10)//���������ݽ϶�ʱ����ѡ��ָ�������ķ�ʽ
	{
		int keyIndex = partSort(a, begin, end);
		//��ʱ��������Ľ�����key��λ��ȷ����ֻ��Ҫ�ݹ齫key��ߺ��ұߵ����н�������(���ƶ�������ǰ�����)
		quickSort(a, begin, keyIndex - 1);
		quickSort(a, keyIndex + 1, end);
	}
	else//���������������٣�������С�ڵ���10�����ٷָ�������ݹ���Եò�ֵ���ˣ�����ѡ���������ֱ�Ӵ���
	{
		insertSort(a + begin, end - begin + 1);
	}
}

//3�������������ƶ������Ĳ��������
void quickSort_iterate(int* a, int left, int right)
{
	Stack s;
	StackInit(&s);
	//����������ұ߽���ջ
	StackPush(&s, left);
	StackPush(&s, right);
	while (!StackEmpty(&s))
	{
		//ȡ�õ�ǰ��Ҫ������������ұ߽�:��ȡright����ȡleft
		right = StackTop(&s);
		StackPop(&s);
		left = StackTop(&s);
		StackPop(&s);
		int midIndex = digHole_partSort_plus(a, left, right);
		//����߽磺����left������right
		//midIndex�������������Ԫ�ظ�������1�����������ջ
		if (left < midIndex - 1)
		{
			StackPush(&s, left);
			StackPush(&s, midIndex - 1);
		}
		if (midIndex + 1 < right)
		{
			StackPush(&s, midIndex + 1);
			StackPush(&s, right);
		}
	}
	StackDestroy(&s);
}
