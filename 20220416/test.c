#include "Sort.h"

void test1()
{
	printf("QShoare\n");
	int a[] = { 5,6,7,10,4,1,8,3,2,9 };
	int len = sizeof(a) / sizeof(a[0]);
	QuickSort1(a, 0, len-1);
	for (int i = 0;i < len;i++)
	{
		printf("%2d ", a[i]);
	}
	printf("\n");
}

void test2()
{
	printf("QSHole\n");
	int a[] = { 5,6,7,10,4,1,8,3,2,9 };
	int len = sizeof(a) / sizeof(a[0]);
	QuickSort2(a, 0, len-1);
	for (int i = 0;i < len;i++)
	{
		printf("%2d ", a[i]);
	}
	printf("\n");
}

void test3()
{
	printf("QSDoublePointer\n");
	int a[] = { 5,6,7,10,4,1,8,3,2,9 };
	int len = sizeof(a) / sizeof(a[0]);
	QuickSort3(a, 0, len-1);
	for (int i = 0;i < len;i++)
	{
		printf("%2d ", a[i]);
	}
	printf("\n");
}


void test4()
{
	printf("QSNonR\n");
	int a[] = { 5,6,7,10,4,1,8,3,2,9 };
	int len = sizeof(a) / sizeof(a[0]);
	QuickSortNonR(a, 0, len);
	for (int i = 0;i < len;i++)
	{
		printf("%2d ", a[i]);
	}
	printf("\n");
}

void test5()
{
	printf("Bubble\n");
	int a[] = { 5,6,7,10,4,1,8,3,2,9 };
	int len = sizeof(a) / sizeof(a[0]);
	BubbleSort(a, len);
	for (int i = 0;i < len;i++)
	{
		printf("%2d ", a[i]);
	}
	printf("\n");
}

void test6()
{
	printf("Select\n");
	int a[] = { 5,6,7,10,4,1,8,3,2,9 };
	int len = sizeof(a) / sizeof(a[0]);
	SelectSort(a, len);
	for (int i = 0;i < len;i++)
	{
		printf("%2d ", a[i]);
	}
	printf("\n");
}


void test7()
{
	printf("Heap\n");
	int a[] = { 5,6,7,10,4,1,8,3,2,9 };
	int len = sizeof(a) / sizeof(a[0]);
	HeapSort(a, len);
	for (int i = 0;i < len;i++)
	{
		printf("%2d ", a[i]);
	}
	printf("\n");
}

void test8()
{
	printf("Insert\n");
	int a[] = { 5,6,7,10,4,1,8,3,2,9 };
	int len = sizeof(a) / sizeof(a[0]);
	InsertSort(a, len);
	for (int i = 0;i < len;i++)
	{
		printf("%2d ", a[i]);
	}
	printf("\n");
}


void test9()
{
	printf("Shell\n");
	int a[] = { 5,6,7,10,4,1,8,3,2,9 };
	int len = sizeof(a) / sizeof(a[0]);
	ShellSort(a, len);
	for (int i = 0;i < len;i++)
	{
		printf("%2d ", a[i]);
	}
	printf("\n");
}

int main()
{
	/*test1();
	test2();
	test3();
	test4();
	test5();*/
	/*test6();
	test7();*/
	test8();
	test9();
	return 0;
}