#include "slit.h"
// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	assert(newNode);
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
// 单链表打印
void SListPrint(SListNode* plist)
{
	if (plist == NULL)//空链表
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
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* newNode =BuySListNode(x);
	if (*pplist == NULL)//空链表
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
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* newNode = BuySListNode(x);
	SListNode* st = *pplist;
	newNode->next = st;
	*pplist = newNode;
}
// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	if (*pplist == NULL)//空链表
	{
		return;
	}
	else if ((*pplist)->next==NULL)//只有一个数据
	{
		free(*pplist);
		*pplist = NULL;
	}
	else//两个及以上数据
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
// 单链表头删
void SListPopFront(SListNode** pplist)
{
	if (*pplist == NULL)//空链表
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
// 单链表查找
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
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
//可以在找到pos位置之后直接进行操作，不用再次遍历链表取寻找pos前一个位置
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* newNode = BuySListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
//可以在找到pos位置之后直接进行操作，不用再次遍历链表取寻找pos前一个位置
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
// 单链表的销毁
void SListDestory(SListNode** pplist)
{
	assert(pplist);
	while (*pplist)
	{
		SListPopFront(pplist);
	}
	*pplist = NULL;
}