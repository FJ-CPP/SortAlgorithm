#define _CRT_SECURE_NO_WARNINGS 1
/*
* ϣ������˼�룺
* ���Ʋ������򣬵��ڲ�������Ļ����Ͻ����˸Ľ�
* ϣ�����������м��Ϊgap������Ϊһ�飬Ȼ������ǽ��в���������һ������Ԥ����
* ������gapΪ1ʱ�����Ǵ���Ĳ������򣬵���Ч�ʺܸ�
* ��Ϊ��������Ԥ�����������鼸������С����ǰ������ں��״̬��������һ��ֻ��Ҫ�ӽ�O(N)��ʱ�临�Ӷ�
* 
* ϣ�������ʱ�临�Ӷȣ�nΪĳһ�ض���Χʱ��ΪO(n^1.3)����������n��ΪO(n^1.3)~O(n^2)
*/
void ShellSort(int* a, int n)
{
	int gap = n;
	int end = 0;
	while (gap > 1)//��һ��ѭ������gap�Ĵ�С
	{
		gap = (gap / 3) + 1;
		for (int i = gap; i < n; ++i)//�ڶ���ѭ������Ԥ����(����i�������뵽ǰ�������������)
		{
			int end = i;
			int insert = a[end];//��������
			while (end >= gap)
			{
				if (a[end - gap] > insert)
				{
					a[end] = a[end - gap];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end] = insert;
		}
	}
	//while (gap > 1)//��һ��ѭ������gap�Ĵ�С
	//{
	//	gap = (gap / 3) + 1;
	//	for (int i = 0; i < n - gap; ++i)//�ڶ���ѭ������Ԥ����
	//	{
	//		int end = i;
	//		int insert = a[end + gap];//��end+gapλ�õ�Ԫ�ز��뵽end֮ǰ�ġ����Ϊgap��һ���������У���������
	//		while (end >= 0)
	//		{
	//			if (a[end] > insert)
	//			{
	//				a[end + gap] = a[end];
	//				end -= gap;
	//			}
	//			else
	//			{
	//				break;
	//			}
	//		}
	//		a[end + gap] = insert;
	//	}
	//}
}