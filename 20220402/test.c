#include "Heap.h"

int main()
{
	Heap* hp=(Heap*)malloc(sizeof(Heap));
	HeapInit(hp);
	HeapPush(hp,15);
	HeapPush(hp,74);
	HeapPush(hp,25);
	HeapPush(hp,23);
	HeapPush(hp, 7);
	HeapPush(hp,64);
	HeapPush(hp,35);
	HeapPush(hp,10);
	PrintHeap(hp);
	return 0;
}