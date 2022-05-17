#include "Sort.h"

// 插入排序
void InsertSort(int* a, int n)
{
	assert(a);
	for (int i = 0;i < n;i++)
	{
		int ret = a[i];//i之前的数据已经有序
		int tail = i - 1;//有序数据最后一位
		//升序
		while (tail >= 0 && a[tail] > ret)//当a[i]小于有序数据中某一位时，从这个位置开始的数据全部向后移动一位
		{
			a[tail+1] = a[tail];
			tail--;
		}
		//最后将a[i]插入这个位置
		a[tail + 1] = ret;
	}
}

// 希尔排序
// 区别于插入排序，希尔排序在比较数据大小时会先取一个间隔gap，先使数据局部有序，再缩小gap，循环操作直到gap为1
void ShellSort(int* a, int n)
{
	assert(a);
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap;i < n;i++)
		{
			int ret = a[i];
			int tail = i - gap;
			while (tail >= 0 && a[tail] > ret)
			{
				a[tail + gap] = a[tail];
				tail -= gap;
			}
			a[tail + gap] = ret;
		}
	}
}
