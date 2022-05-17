#include "Sort.h"
#include "Stack.h"


//˫ָ�뷨ȡ�м�ֵ
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

// ��������hoare�汾
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
// ���������ڿӷ�
int PartSort2(int* a, int left, int right)
{
	int key = a[left];//��ȡ���������
	int hole = left;//�ڿ�
	while (left < right)
	{
		while (a[right] >= key && left < right)//��ǰ��С���ҵ������
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;//�����¿�
		while (a[left] <= key && left < right)//����Ҵ�,�ҵ������
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;//�����¿�
	}
	a[hole] = key;//�������ݻ����ǰΪС���Ӻ�Ϊ��
	return hole;
}
// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	//��ֹȡ��������Сֵ
	Swap(&a[left], &a[GetMindInit(a, left, right)]);
	int key = left;
	int prev = left;
	int cur = left + 1;
	while (cur <= right)//cur���Ѱ��С��KEY��λ�ã�������KEY�����λ�ý���������prev
	{
		if(a[cur] < a[key] && a[++prev] != a[cur])
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[prev], &a[key]);//prev�ڱ�ȻС��KEY��������KEYǰ��ΪС��KEY���Ϊ��
	return prev;
}
// ��������ݹ�ʵ��
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
//�ڿ�
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
//˫ָ��
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

// �������� �ǵݹ�ʵ��
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