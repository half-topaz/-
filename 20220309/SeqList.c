#include "SeqList.h"

void SeqListInit(SeqList* ps)//��ʼ��˳���
{
	assert(ps);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}
void SeqListDestory(SeqList* ps)//ɾ������˳���
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListCheckCapacity(SeqList* ps)//����
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

void SeqListPrint(SeqList* ps)//��ӡ˳���
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


void SeqListPushBack(SeqList* ps, SLDateType x)//β��
{
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPushFront(SeqList* ps, SLDateType x)//ͷ��
{
	SeqListCheckCapacity(ps);
	size_t n = 0;
	while (n < ps->size)//���ݺ���
	{
		ps->a[ps->size - n] = ps->a[ps->size - 1 - n];
		n++;
	}
	ps->a[0] = x;
	ps->size++;
}
void SeqListPopFront(SeqList* ps)//ͷɾ
{
	int n = ps->size;
	if (ps->size > 0)//�����ݲ�ɾ
	{
		while (n > 0)
		{
			ps->a[ps->size - n] = ps->a[ps->size - n + 1];
			n--;
		}
		ps->size--;
	}
}
void SeqListPopBack(SeqList* ps)//βɾ
{
	assert(ps);
	if (ps->size > 0)//�����ݲ�ɾ
	{
		ps->size--;
	}
}

// ˳������
int SeqListFind(SeqList* ps, SLDateType x)//�ҵ��󷵻��±꣬�Ҳ�������-1
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
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	SeqListCheckCapacity(ps);
	if (ps->size > pos)
	{
		size_t n = 0;
		while (n < ps->size - pos)//���ݺ���
		{
			ps->a[ps->size - n] = ps->a[ps->size - 1 - n];
			n++;
		}
		ps->a[pos] = x;
		ps->size++;
	}
}
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos)
{
	size_t n = pos;
	if (ps->size > pos)//���ڲ�ɾ��
	{
		while (n <ps->size)
		{
			ps->a[n] = ps->a[n + 1];
			n++;
		}
		ps->size--;
	}
}
// ˳����޸�posλ�õ�ֵ
void SeqListRevise(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps);
	if (ps->size > pos)
	{
		ps->a[pos] = x;
	}
}