#include "Heap.h"


void TestHeap1()
{
	Heap* hp = (Heap*)malloc(sizeof(Heap));
	HeapInit(hp);
	HeapPush(hp, 15);
	HeapPush(hp, 74);
	HeapPush(hp, 25);
	HeapPush(hp, 23);
	HeapPush(hp, 11);
	HeapPush(hp, 64);
	PrintHeap(hp);
	HeapPop(hp);
	PrintHeap(hp);
	HeapPop(hp);
	PrintHeap(hp);
	HeapPop(hp);
	PrintHeap(hp);
	HeapPush(hp, 8);
	PrintHeap(hp);
	HeapPush(hp, 10);
	HeapPush(hp, 99);
	HeapPush(hp, 65);
	PrintHeap(hp);
	printf("\n");
}

void TestHeap2()
{
	int a[100] = { 0 };
	int i = 0;
	srand((unsigned)time(NULL));
	while (i < 100)
	{
		a[i] = rand() % 10000;
		i++;
	}
	a[11] = 10000001;
	a[22] = 10000002;
	a[33] = 10000003;
	a[44] = 10000004;
	a[55] = 10000005;
	a[66] = 10000006;
	a[77] = 10000007;
	a[88] = 10000008;
	a[99] = 10000009;
	a[4] = 10000000;
	i = 0;
	while (i<100)
	{
		printf("%7d ", a[i]);
		if (i % 10 == 9)
		{
			printf("\n");
		}
		i++;
	}
	printf("\n");
	PrintTopK(a, 100, 10);
}


int main()
{
	TestHeap1();
	printf("TopK\n");
	TestHeap2();
	return 0;
}