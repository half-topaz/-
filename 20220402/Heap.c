#include "Heap.h"


//数据交换
void SwapData(HPDataType* child, HPDataType* parent)
{
	HPDataType sz = *child;
	*child = *parent;
	*parent = sz;
}

//向上调整
void Dataup(int* a ,int site )
{
	int child = site;
	int parent = (site - 1) / 2;
	while (child)
	{
		if (a[child] < a[parent])//建立小堆
		//if (a[child] > a[parent])建立大堆
		{
			SwapData(&a[child], &a[parent]);
			child = parent;
			parent = (parent - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//向下调整
void DataDown(int* a, int site, int size)
{
	int parent = site;
	int child = site * 2 + 1;
	while (child <= size-1)
	{
		if ( child + 1 < size && a[child] > a[child + 1] )//建立小堆时，选左右子数中小的
		//if ( child + 1 < size && a[child] < a[child + 1] )//建立大堆时，选左右子数中大的
		{
			child++;
		}

		if (a[child] < a[parent])//建立小堆
		//if (a[child] > a[parent])建立大堆
		{
			SwapData(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
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
	
	Dataup(hp->a, hp->size);
	
	hp->size++;
}
// 堆的删除
void HeapPop(Heap* hp)
{
	assert(hp);
	SwapData(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;
	DataDown(hp->a, 0, hp->size);
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

// 堆的打印
void PrintHeap(Heap* hp)
{
	assert(hp);
	int i = 0;
	while (i < hp->size)
	{
		printf("%3d ", hp->a[i++]);
	}
	printf("\n");
}
// TopK问题：找出N个数里面最大/最小的前K个问题。
// 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
// 需要注意：
// 找最大的前K个，建立K个数的小堆
// 找最小的前K个，建立K个数的大堆
void PrintTopK(int* a, int n, int k)
{
	assert(a);
	int* hp = (int*)malloc(sizeof(int)*10);
	int i = 0;
	while (i < k)
	{
		hp[i] = a[i];
		i++;
	}
	for (int j = (k - 1 - 1) / 2;j >= 0;j--)
	{
		DataDown(hp, j, k);
	}
	while (i < n)
	{
		if (a[i] > hp[0])
		{
			hp[0] = a[i];
			DataDown(hp, 0, k);
		}
		i++;
	}
	for (i = 0;i < k;i++)
	{
		printf("%3d ", hp[i]);
	}
	printf("\n");
	free(hp);
}

void TestTopk()
{}
