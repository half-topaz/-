#include "Sort.h"


void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


void BubbleSort(int* a, int n)
{
	assert(a);
	while (n>1)
	{
		int flag = 0;//���������ͽ��б��
		for (int i = 1;i < n;i++)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			//δ��������˵�������Ѿ����򣬿��Բ���������
			break;
		}
		n--;
	}
}