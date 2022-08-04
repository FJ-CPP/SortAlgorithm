#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <string.h>
/*
* ��������ԭ��
* �������������ֵķ�Χ����һ��count���飬��СΪrange��range = ���ֵ-��Сֵ+1��
* ������ÿһ��Ԫ������Сֵ�Ĳ�ֵ������count���ҵ�Ψһ��ӳ�䣬��Ϊ���ӳ��
* ����countĳ��λ�õ�ֵ�Ϳ���ȷ����ӳ������Ƕ��٣��Լ������˶��ٴΡ�
* 
* ʱ�临�Ӷȣ�O(n + range)
* �ռ临�Ӷȣ�O(range)
*/
void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];//�ҵ�����Ԫ�ص����ֵ����Сֵ
	for (int i = 1; i < n; ++i)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int range = max - min + 1;//�������ӳ������Ĵ�С
	int* count = (int*)malloc(sizeof(int) * range);
	if (count == NULL)
		exit(-1);
	memset(count, 0, sizeof(int) * range);
	for (int i = 0; i < n; ++i)
	{
		count[a[i] - min]++;//���ӳ��
	}
	int index = 0;
	for (int i = 0; i < range; ++i)
	{
		while (count[i]--)
		{
			a[index++] = i + min;
		}
	}
	free(count);
}