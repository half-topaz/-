#include "Sort.h"





void test1()
{
	printf("Merge\n");
	int a[] = { 11,5,4,9,7,3,8,2,1,10,6 };
	int n = sizeof(a) / sizeof(a[0]);
	MergeSort(a, n);
	for (int i = 0;i < n;i++)
	{
		printf("%2d ", a[i]);
	}
	printf("\n");
}

void test2()
{
	printf("MergeNonR\n");
	int a[] = { 11,5,4,9,7,3,8,2,1,10,6 };
	int n = sizeof(a) / sizeof(a[0]);
	MergeSortNonR(a, n);
	for (int i = 0;i < n;i++)
	{
		printf("%2d ", a[i]);
	}
	printf("\n");
}

void test3()
{
	printf("Count\n");
	int a[] = { 11,50000,41111111,9,7,3,8,2,1,10,6 };
	int n = sizeof(a) / sizeof(a[0]);
	CountSort(a, n);
	for (int i = 0;i < n;i++)
	{
		printf("%2d ", a[i]);
	}
	printf("\n");
}

int main()
{
	test1();
	test2();
	test3();
	return 0;
}