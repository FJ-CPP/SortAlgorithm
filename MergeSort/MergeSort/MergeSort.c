#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
/*
* �鲢����˼�룺����
* �鲢�ǽ�����������������ϲ���һ����
* ��Ϊ�˵õ��������飬��Ҫ�����Ƕ��֣�Ȼ���ٺϲ����ǵ�����������������
* �����ڶ������ĺ����������ִ�����������������ִ��ԭ����ĺϲ�����
* �������һ���ܴ��n��Ԫ�ص������顣
* �������������һ���±귶Χ����������������������Ӧ�ķ�Χ�ڽ��У�Ȼ���ٿ�����ԭ��������
* 
* ʱ�临�Ӷȣ�O(NlogN)
* �ռ临�Ӷȣ�O(N)
*/

//�ݹ鷨
void merge(int* a, int* tmp, int begin1, int end1, int begin2, int end2)
{
	int i = begin1;
	int left = begin1;//����鲢��tmp������a�ķ�Χ
	int right = end2;
	while (begin1 <= end1 && begin2 <= end2)//���Ѿ�����õ���������������й鲢(˫ָ�뷨)
	{
		if (a[begin1] < a[begin2])//���ڹ鲢��Ԫ�ط�Χ��[left,right]���������ҲҪ�����tmp�е�[left,right]��Χ��
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	//����ʣ��������е�Ԫ�ؼ���׷�ӵ�tmp��
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	for (int j = left; j <= right; ++j)//��tmp��[left,right]��Χ�ڵ�Ԫ�ؿ�����������
	{
		a[j] = tmp[j];
	}
}
void _mergeSort(int* a, int left, int right, int* tmp)
{
	if (left == right)
	{
		return;//ֻ��һ��Ԫ�أ�������������
	}
	int mid = (left + right) >> 1;//������ֳ�[left,mid]��[mid+1,right]����
	_mergeSort(a, left, mid, tmp);//��[left,mid]����
	_mergeSort(a, mid + 1, right, tmp);//��[mid+1,right]����

	merge(a, tmp, left, mid, mid + 1, right);//��[left,mid]��[mid+1,right]�鲢��a��

}
void mergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		exit(-1);
	}
	else
	{
		_mergeSort(a, 0, n - 1, tmp);
	}
	free(tmp);
}

//������
void mergeSort_iterate(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		exit(-1);
	}
	int gap = 1;//���ƹ鲢ʱÿһ���Ԫ�ظ���
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			//��[i, i + gap - 1]��[i + gap, i + 2 * gap -1]�鲢
			int begin1 = i;
			int end1 = i + gap - 1;
			int begin2 = i + gap;
			int end2 = i + 2 * gap - 1;
			//�����������
			//1��������ֻ��һ���ֻ�����������ȫ�����ڵ����������鲢
			if (i + gap - 1 >= n)
				break;
			//2��������ֻ��һ���֣�������end2
			if (end2 >= n)
				end2 = n - 1;
			merge(a, tmp, begin1, end1, begin2, end2);//�鲢
		}
		gap *= 2;
	}
	free(tmp);
}