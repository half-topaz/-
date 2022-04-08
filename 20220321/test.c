#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"




int main()
{
	ListNode* pHead = ListCreate();
	ListPushBack(pHead, 4);
	ListPushBack(pHead, 5);
	ListPushBack(pHead, 6);
	ListPushFront(pHead, 3);
	ListPushFront(pHead, 2);
	ListPushFront(pHead, 1);
	ListPrint(pHead);
	ListPopBack(pHead);
	ListPrint(pHead);
	ListPopFront(pHead);
	ListPrint(pHead);
	ListNode* pos = ListFind(pHead, 3);
	ListInsert(pos, 100);
	ListPrint(pHead);
	ListErase(pos);
	ListPrint(pHead);
	ListDestory(pHead);
	ListPrint(pHead);
	return 0;
}