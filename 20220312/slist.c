#include "slit.h"
// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	assert(newNode);
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
// �������ӡ
void SListPrint(SListNode* plist)
{
	if (plist == NULL)//������
	{
		printf("NULL\n");
	}
	else
	{
		while (plist)
		{
			printf("%d ", plist->data);
			plist = plist->next;
		}
		printf("\n");
	}
}
// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* newNode =BuySListNode(x);
	if (*pplist == NULL)//������
	{
		*pplist = newNode;
	}
	else
	{
		SListNode* st = *pplist;
		while (st->next)
		{
			st = st->next;
		}
		st->next = newNode;
	}
}
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* newNode = BuySListNode(x);
	SListNode* st = *pplist;
	newNode->next = st;
	*pplist = newNode;
}
// �������βɾ
void SListPopBack(SListNode** pplist)
{
	if (*pplist == NULL)//������
	{
		return;
	}
	else if ((*pplist)->next==NULL)//ֻ��һ������
	{
		free(*pplist);
		*pplist = NULL;
	}
	else//��������������
	{
		SListNode* st = *pplist;
		while (st->next->next)
		{
			st = st->next;
		}
		free(st->next);
		st->next = NULL;
	}
}
// ������ͷɾ
void SListPopFront(SListNode** pplist)
{
	if (*pplist == NULL)//������
	{
		return;
	}
	else 
	{
		SListNode* st = (*pplist)->next;
		free(*pplist);
		*pplist = st;
	}
}
// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	SListNode* st = plist;
	while (st)
	{
		if (st->data == x)
		{
			return st;
		}
		else
		{
			st = st->next;
		}
	}
	return NULL;
}
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
//�������ҵ�posλ��֮��ֱ�ӽ��в����������ٴα�������ȡѰ��posǰһ��λ��
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* newNode = BuySListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
//�������ҵ�posλ��֮��ֱ�ӽ��в����������ٴα�������ȡѰ��posǰһ��λ��
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	if (pos->next)
	{
		SListNode* st = pos->next;
		pos->next = st->next;
		free(st);
	}
}
// �����������
void SListDestory(SListNode** pplist)
{
	assert(pplist);
	while (*pplist)
	{
		SListPopFront(pplist);
	}
	*pplist = NULL;
}