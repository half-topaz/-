#include "Sort.h"


//向下调整，建立大堆
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = root * 2 + 1;
	if (child + 1 < n && a[child] < a[child + 1])
	{
		child++;
	}
	if (child < n && a[child] > a[parent])//防止越界
	{
		Swap(&a[child], &a[parent]);
		AdjustDown(a, n, child);
	}
}

//堆排序
void HeapSort(int* a, int n)
{
	assert(a);
	//整理，建立大堆
	for (int i = (n - 1) / 2;i >= 0;i--)
	{
		AdjustDown(a, n, i);
	}
	//堆顶和堆底互换，堆大小减一，重新建大堆
	while (n >0)
	{
		n--;
		Swap(&a[0], &a[n]);
		AdjustDown(a, n, 0);
	}
}
