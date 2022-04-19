#include "Heap.h"


//���ݽ���
void SwapData(HPDataType* child, HPDataType* parent)
{
	HPDataType sz = *child;
	*child = *parent;
	*parent = sz;
}

//���ϵ���
void Dataup(int* a ,int site )
{
	int child = site;
	int parent = (site - 1) / 2;
	while (child)
	{
		if (a[child] < a[parent])//����С��
		//if (a[child] > a[parent])�������
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

//���µ���
void DataDown(int* a, int site, int size)
{
	int parent = site;
	int child = site * 2 + 1;
	while (child <= size-1)
	{
		if ( child + 1 < size && a[child] > a[child + 1] )//����С��ʱ��ѡ����������С��
		//if ( child + 1 < size && a[child] < a[child + 1] )//�������ʱ��ѡ���������д��
		{
			child++;
		}

		if (a[child] < a[parent])//����С��
		//if (a[child] > a[parent])�������
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
	
	Dataup(hp->a, hp->size);
	
	hp->size++;
}
// �ѵ�ɾ��
void HeapPop(Heap* hp)
{
	assert(hp);
	SwapData(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;
	DataDown(hp->a, 0, hp->size);
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

// �ѵĴ�ӡ
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
// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
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
