#include "List.h"
// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode* newhead = (ListNode*)malloc(sizeof(ListNode));
	newhead->data = 0;
	newhead->next = newhead;
	newhead->prev = newhead;
	return newhead;
}
// 创建新节点
ListNode* newNode(LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
// 双向链表销毁
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
// 双向链表打印
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
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* new=newNode(x);
	new->prev = pHead->prev;
	new->next = pHead;
	pHead->prev->next = new;
	pHead->prev = new;
}
// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	ListNode* st = pHead->prev;
	pHead->prev = pHead->prev->prev;
	free(st);
	pHead->prev->next = pHead;
}
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* new = newNode(x);
	new->next = pHead->next;
	new->prev = pHead;
	new->next->prev = new;
	pHead->next = new;
}
// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	ListNode*  st = pHead->next;
	pHead->next = pHead->next->next;
	free(st);
	pHead->next->prev = pHead;
}
// 双向链表查找
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
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* new = newNode(x);
	new->prev = pos->prev;
	new->next = pos;
	pos->prev->next = new;
	pos->prev = new;
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}