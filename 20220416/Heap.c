#include "Sort.h"


//���µ������������
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = root * 2 + 1;
	if (child + 1 < n && a[child] < a[child + 1])
	{
		child++;
	}
	if (child < n && a[child] > a[parent])//��ֹԽ��
	{
		Swap(&a[child], &a[parent]);
		AdjustDown(a, n, child);
	}
}

//������
void HeapSort(int* a, int n)
{
	assert(a);
	//�����������
	for (int i = (n - 1) / 2;i >= 0;i--)
	{
		AdjustDown(a, n, i);
	}
	//�Ѷ��Ͷѵ׻������Ѵ�С��һ�����½����
	while (n >0)
	{
		n--;
		Swap(&a[0], &a[n]);
		AdjustDown(a, n, 0);
	}
}
