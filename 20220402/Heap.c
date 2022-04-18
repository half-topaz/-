#include "Heap.h"



void SwapData(HPDataType* child, HPDataType* parent)
{
	HPDataType sz = *child;
	*child = *parent;
	*parent = sz;
}

// �ѵĹ���
void HeapInit(Heap* hp)
{
	assert(hp);
	hp->a = NULL;
	hp->capacity = hp->size = 0;
}
// �ѵ�����
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->a);
	hp->a = NULL;
	hp->capacity = hp->size = 0;
}
// �ѵĲ���
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
// �ѵ�ɾ��
void HeapPop(Heap* hp)
{
}

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->a[0];
}

// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}

// �ѵ��п�
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
// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
void PrintTopK(int* a, int n, int k)
{}

void TestTopk()
{}
