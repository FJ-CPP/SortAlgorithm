#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
static void adjustDown(int* a, int parent, int n)//��С�����µ����㷨
{
	int child = 2 * parent + 1;//Ĭ��childΪparent������
	while (child < n)//childʵ��Ϊ����Ԫ�ص��±꣬�������ڣ���child < n
	{
		if (child + 1 < n && a[child + 1] < a[child])
		{
			++child;//����Һ���С�����ӣ���ô���Һ��Ӻ�parent�Ƚ�
		}
		if (a[child] < a[parent])
		{
			swap(&a[parent], &a[child]);//child<parent����ʱ��Ҫ�������ǲ���child��Ϊ��һ�ε�parent
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;//���parent<=child��˵����ʱ������Ҫ������������ǰ����������������С�ѻ��ѣ�
		}
	}
	//ʱ�临�Ӷ�ΪO(logn)
	//����������Ԫ�����µ��������ִ��������ȴ�
}
//int main()
//{
//	int arr[] = { 23,47,16,48,51,17,22 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	adjustDown(arr, 0, sz);//��С��
//	return 0;
//}