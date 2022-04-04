#include "SeqList.h"

void SeqListInit(SeqList* ps)//初始化顺序表
{
	assert(ps);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}
void SeqListDestory(SeqList* ps)//删除整个顺序表
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListCheckCapacity(SeqList* ps)//扩容
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 5 : 2 * ps->capacity;
		SLDateType* ret = (SLDateType*)realloc(ps->a, sizeof(SLDateType) * newcapacity);
		if (ret == NULL)
		{
			printf("ERROR\n");
			exit(1);
		}
		else
		{
			ps->a = ret;
			ps->capacity = newcapacity;
		}
	}
}

void SeqListPrint(SeqList* ps)//打印顺序表
{
	assert(ps);
	size_t i = 0;
	while (i < ps->size)
	{
		printf("%d ", ps->a[i]);
		i++;
	}
	printf("\n");
}


void SeqListPushBack(SeqList* ps, SLDateType x)//尾插
{
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPushFront(SeqList* ps, SLDateType x)//头插
{
	SeqListCheckCapacity(ps);
	size_t n = 0;
	while (n < ps->size)//数据后移
	{
		ps->a[ps->size - n] = ps->a[ps->size - 1 - n];
		n++;
	}
	ps->a[0] = x;
	ps->size++;
}
void SeqListPopFront(SeqList* ps)//头删
{
	int n = ps->size;
	if (ps->size > 0)//有数据才删
	{
		while (n > 0)
		{
			ps->a[ps->size - n] = ps->a[ps->size - n + 1];
			n--;
		}
		ps->size--;
	}
}
void SeqListPopBack(SeqList* ps)//尾删
{
	assert(ps);
	if (ps->size > 0)//有数据才删
	{
		ps->size--;
	}
}

// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x)//找到后返回下标，找不到返回-1
{
	assert(ps);
	size_t n = 0;
	for (n = 0;n < ps->size ;n++)
	{
		if (ps->a[n] == x)
			return n;
	}
	return -1;
}
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	SeqListCheckCapacity(ps);
	if (ps->size > pos)
	{
		size_t n = 0;
		while (n < ps->size - pos)//数据后移
		{
			ps->a[ps->size - n] = ps->a[ps->size - 1 - n];
			n++;
		}
		ps->a[pos] = x;
		ps->size++;
	}
}
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos)
{
	size_t n = pos;
	if (ps->size > pos)//存在才删除
	{
		while (n <ps->size)
		{
			ps->a[n] = ps->a[n + 1];
			n++;
		}
		ps->size--;
	}
}
// 顺序表修改pos位置的值
void SeqListRevise(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps);
	if (ps->size > pos)
	{
		ps->a[pos] = x;
	}
}