#include "List.h"
// �������������ͷ���.
ListNode* ListCreate()
{
	ListNode* newhead = (ListNode*)malloc(sizeof(ListNode));
	newhead->data = 0;
	newhead->next = newhead;
	newhead->prev = newhead;
	return newhead;
}
// �����½ڵ�
ListNode* newNode(LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
// ˫����������
void ListDestory(ListNode* pHead)
{
	assert(pHead);
	ListNode* st;
	while (pHead->next != pHead)
	{
		st = pHead->next;
		pHead->next = pHead->next->next;
		free(st);
		pHead->next->prev = pHead;
	}
	st = NULL;
}
// ˫�������ӡ
void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* st=pHead->next;
	while (st!=pHead)
	{
		printf("%d ", st->data);
		st = st->next;
	}
	printf("\n");
}
// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* new=newNode(x);
	new->prev = pHead->prev;
	new->next = pHead;
	pHead->prev->next = new;
	pHead->prev = new;
}
// ˫������βɾ
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	ListNode* st = pHead->prev;
	pHead->prev = pHead->prev->prev;
	free(st);
	pHead->prev->next = pHead;
}
// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* new = newNode(x);
	new->next = pHead->next;
	new->prev = pHead;
	new->next->prev = new;
	pHead->next = new;
}
// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	ListNode*  st = pHead->next;
	pHead->next = pHead->next->next;
	free(st);
	pHead->next->prev = pHead;
}
// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* st = pHead->next;
	while (st->data != x && st!=pHead)
	{
		st = st->next;
	}
	if (st == pHead)
	{
		return NULL;
	}
	else
	{
		return st;
	}
}
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* new = newNode(x);
	new->prev = pos->prev;
	new->next = pos;
	pos->prev->next = new;
	pos->prev = new;
}
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}