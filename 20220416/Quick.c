#include "Sort.h"
#include "Stack.h"


//双指针法取中间值
int GetMindInit(int* a, int left, int right)
{
	int mind = left + (right - left) / 2;
	if (a[mind] > a[right])
	{
		if (a[mind] < a[left])	//a[right]<a[mind]<a[left]
			return mind;
		if (a[left] > a[right])	//a[right]<a[left]<a[mind]
			return left;
		else					//a[left]<a[right]<a[mind]
			return right;	
	}
	else						//a[mind]<a[right]
	{
		if (a[mind] > a[left])	//a[left]<a[mimd]<a[right]
			return mind;
		if (a[left] > a[right])	//a[mind]<a[right]<a[left]
			return right;
		else					//a[mind]<a[left]<a[right]
			return left;	
	}
}

// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{
	int star = left;
	int begin = left;
	int end = right;
	while (begin < end)
	{
		while (a[end] >= a[star] && begin < end)
		{
			end--;
		}
		while (a[begin] <= a[star] && begin < end)
		{
			begin++;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[star], &a[begin]);
	return begin;
}
// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	int key = a[left];//提取坑里的数据
	int hole = left;//挖坑
	while (left < right)
	{
		while (a[right] >= key && left < right)//向前找小，找到就填坑
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;//设置新坑
		while (a[left] <= key && left < right)//向后找大,找到就填坑
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;//设置新坑
	}
	a[hole] = key;//坑里数据回填，坑前为小，坑后为大
	return hole;
}
// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{
	//防止取到最大或最小值
	Swap(&a[left], &a[GetMindInit(a, left, right)]);
	int key = left;
	int prev = left;
	int cur = left + 1;
	while (cur <= right)//cur向后寻找小于KEY的位置，依次与KEY后面的位置交换，放入prev
	{
		if(a[cur] < a[key] && a[++prev] != a[cur])
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[prev], &a[key]);//prev内必然小于KEY，交换后KEY前均为小，KEY后均为大
	return prev;
}
// 快速排序递归实现
//hoare
void QuickSort1(int* a, int left, int right)
{
	assert(a);
	if (left >= right-1)
	{
		return;
	}
	int key = PartSort1(a, left, right);
	QuickSort1(a, left, key-1);
	QuickSort1(a, key+1, right);
}
//挖坑
void QuickSort2(int* a, int left, int right)
{
	assert(a);
	if (left >= right)
	{
		return;
	}
	int key = PartSort2(a, left, right);
	QuickSort2(a, left, key - 1);
	QuickSort2(a, key + 1, right);
}
//双指针
void QuickSort3(int* a, int left, int right)
{
	assert(a);
	if (left >= right)
	{
		return;
	}
	int key = PartSort3(a, left, right);
	QuickSort3(a, left, key - 1);
	QuickSort3(a, key + 1, right);
}

// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right)
{
	assert(a);
	Stack S;
	StackInit(&S);
	StackPush(&S, left);
	StackPush(&S, right-1);
	while (!StackEmpty(&S))
	{
		int tail = StackTop(&S);
		StackPop(&S);
		int head = StackTop(&S);
		StackPop(&S);
		if (tail - head < 1)
		{
			continue;
		}
		int key = PartSort1(a, head, tail);
		StackPush(&S, key + 1);
		StackPush(&S, tail);
		StackPush(&S, head);
		StackPush(&S, key - 1);
	}
	StackDestroy(&S);
}