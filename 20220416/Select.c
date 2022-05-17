#include "Sort.h"

void SelectSort(int* a, int n)
{
	assert(a);
	int i = 0;
	int j = 0;
	int key = 0;
	for (i = 0;i < n;i++)
	{
		key = i;
		for (j = i + 1;j < n;j++)
		{
			if (a[j] < a[key])
				key = j;
		}
		Swap(&a[i], &a[key]);
	}
}