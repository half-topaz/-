#include "Heap.h"



void SwapData(HPDataType* child, HPDataType* parent)
{
	HPDataType sz = *child;
	*child = *parent;
	*parent = sz;
}

// 堆的构建
void HeapInit(Heap* hp)
{
	assert(hp);
	hp->a = NULL;
	hp->capacity = hp->size = 0;
}
// 堆的销毁
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->a);
	hp->a = NULL;
	hp->capacity = hp->size = 0;
}
// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		int newcapacity = hp->capacity == 0 ? 5 : hp->capacity * 2;
		HPDataType* sz = (HPDataType*)realloc(hp->a, sizeof(HPDataType)*newcapacity);
		if (sz == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		hp->a = sz;
		hp->capacity = newcapacity;
	}
	hp->a[hp->size] = x;
	int child = hp->size;
	int parent = (hp->size - 1) / 2;

	while (child)
	{
		if (hp->a[child] > hp->a[parent])
		{
			SwapData(&hp->a[child], &hp->a[parent]);
			child = parent;
			parent = (parent - 1) / 2;
		}
		else
		{
			break;
		}
	}
	hp->size++;
}
// 堆的删除
void HeapPop(Heap* hp)
{
}

// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->a[0];
}

// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}

// 堆的判空
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->size == 0;
}

void PrintHeap(Heap* hp)
{
	assert(hp);
	int i = 0;
	while (i < hp->size)
	{
		printf("%d ", hp->a[i++]);
	}
	printf("\n");
}
// TopK问题：找出N个数里面最大/最小的前K个问题。
// 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
// 需要注意：
// 找最大的前K个，建立K个数的小堆
// 找最小的前K个，建立K个数的大堆
void PrintTopK(int* a, int n, int k)
{}

void TestTopk()
{}
