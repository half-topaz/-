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
		int flag = 0;//发生交换就进行标记
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
			//未发生交换说明数组已经有序，可以不继续遍历
			break;
		}
		n--;
	}
}