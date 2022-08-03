#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void swap(int* x, int* y);
void adjustDown(int* a, int parent, int n)//��������µ����㷨
{
	int child = 2 * parent + 1;//Ĭ��childΪparent������
	while (child < n)//childʵ��Ϊ����Ԫ�ص��±꣬�������ڣ���child < n
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;//����Һ��Ӵ������ӣ���ô���Һ��Ӻ�parent�Ƚ�
		}
		if (a[child] > a[parent])
		{
			swap(&a[parent], &a[child]);//child>parent����ʱ��Ҫ�������ǲ���child��Ϊ��һ�ε�parent
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;//���parent>=child��˵����ʱ������Ҫ������������ǰ����������������С�ѻ��ѣ�
		}
	}
	//ʱ�临�Ӷ�ΪO(logn)
	//����������Ԫ�����µ��������ִ��������ȴ�
}
void heapSort(int* a, int n)//��������ж�����
{
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)//���ѣ������һ��Ҷ�ӽڵ�ĸ��ڵ㿪ʼ������ֱ������������������
	{
		adjustDown(a, i, n);
		//���ѵ�ʱ�临�Ӷ�ΪO(n)
		/*
		������
		������������������Ϊ�����������߶�Ϊh��
		�������Ϊi(i��[1,h])�����i��ڵ���Ϊ2^(i-1��
		�������������Ǵ����һ����Ҷ�ӽڵ㿪ʼ����
		���ȵ�����h-1�㣬�ٵ�����h-2��...��������1��
		ÿһ��Ľڵ㣬�����»����µ���h-i��
		��ˣ�ʱ�临�Ӷ� T = 2^0*(h-1) + 2^1*(h-2) + ... + 2^(h-2)*1
		              2*T = 2^1*(h-1) + 2^2*(h-2) + ... + 2^(h-1)*1
		ͨ����λ�������õ�T = 2^1 + 2^2 + ... + 2^(h-2) +2^(h-1)*1 - 2^0*(h-1) = 2^h - h - 1
		���ڵ�����n = 2^h - 1,h = log(n+1)
		���T = n - log(n+1)
		�ô�O������ʾ��ΪO(n)
		*/
	}
	int end = n;
	while (end > 0)
	{
		swap(&a[0], &a[end - 1]);//������Ԫ�غ����һ��Ԫ�أ�ʹ��ǰ������������������
		--end;//����һ�ε���������-1���������������Ԫ�ز��ٲ�����һ�ε����µ���
		adjustDown(a, 0, end);
	}
}
int main()
{
	//int arr[] = { 23,47,55,16,8,31,25,66,48,51,14,73,81,99 };
	int arr[] = { 5,2,3,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	heapSort(arr, sz);
	for (size_t i = 0; i < sz; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}