#include "Sort.h"

//void Swap(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}


void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
	{
		return;
	}
	int gap = (right - left) / 2;
	_MergeSort(a, left, left + gap,tmp);
	_MergeSort(a, left + gap + 1, right, tmp);
	int head1 = left;
	int end1 = left + gap;
	int head2 = left + gap + 1;
	int end2 = right;
	int i = left;
	while (head1 <= end1 && head2 <= end2)
	{
		if (a[head1] > a[head2])
		{
			tmp[i++] = a[head2++];
		}
		else
		{
			tmp[i++] = a[head1++];
		}
	}
	while (head1 <= end1)
	{
		tmp[i++] = a[head1++];
	}
	while (head2 <= end2)
	{
		tmp[i++] = a[head2++];
	}
	memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));
}

// 归并排序递归实现
void MergeSort(int* a, int n)
{
	assert(a);
	int* set = (int*)malloc(sizeof(int) * (n));
	_MergeSort(a, 0, n - 1, set);
	free(set);
}

// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{
	assert(a);
	int* tmp = (int*)malloc(sizeof(int) * (n));
	
	int gap = 1;
	while (gap < n)
	{
		int head1 = 0;
		int end1 = gap-1;
		int head2 = gap;
		int end2 = gap * 2 - 1;
		if (end2 >= n)
		{
			end2 = n - 1;
		}
		int i = 0;
		while (head1 < n - 1)
		{
			int set = head1;
			while (head1 <= end1 && head2 <= end2)
			{
				if (a[head1] > a[head2])
				{
					tmp[i++] = a[head2++];
				}
				else
				{
					tmp[i++] = a[head1++];
				}
			}
			while (head1 <= end1)
			{
				tmp[i++] = a[head1++];
			}
			while (head2 <= end2)
			{
				tmp[i++] = a[head2++];
			}
			memcpy(a + set, tmp + set, sizeof(int) * (end2 - set + 1));
			head1 = end2 + 1;
			end1 = head1 + gap - 1;
			if (end1 > n - 1)
			{
				end1 = n - 1;
				head2 = n;
				end2 = n - 1;
				continue;
			}
			head2 = end1 + 1;
			end2 = head2 + gap - 1;
			if (end2 > n - 1)
			{
				end2 = n - 1;
			}
		}
		gap *= 2;
	}
	free(tmp);
}


// 计数排序
void CountSort(int* a, int n)
{
	assert(a);
	int max = a[0];
	int min = a[0];
	for (int i = 0;i < n;i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	int length = max - min + 1;
	int* tmp = (int*)malloc(sizeof(int) * length);
	memset(tmp, 0, sizeof(int) * length);
	for (int i = 0;i < n;i++)
	{
		tmp[a[i] - min]++;
	}
	int j = 0;
	int i = 0;
	while (j < length)
	{
		if (tmp[j] == 0)
		{
			j++;
		}
		else
		{
			a[i] = j + min;
			tmp[j]--;
			i++;
		}
	}
	free(tmp);
}
