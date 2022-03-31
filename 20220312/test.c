#include "slit.h"
SListNode* test()
{
	SListNode* a1 = (SListNode*)malloc(sizeof(SListNode));
	SListNode* a2 = (SListNode*)malloc(sizeof(SListNode));
	SListNode* a3 = (SListNode*)malloc(sizeof(SListNode));
	SListNode* a4 = (SListNode*)malloc(sizeof(SListNode));
	SListNode* a5 = (SListNode*)malloc(sizeof(SListNode));
	a1->data = -2;
	a1->next = a2;
	a2->data = -1;
	a2->next = a3;
	a3->data = 0;
	a3->next = a4;
	a4->data = 1;
	a4->next = a5;
	a5->data = 2;
	a5->next = NULL;
	return a1;
}
int main()
{
	SListNode* plist = test();
	SListPrint(plist);
	SListPushBack(&plist, 3);
	SListPrint(plist);
	SListPushFront(&plist, -3);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListNode* pos = SListFind(plist, 1);
	SListInsertAfter(pos, 100);
	SListPrint(plist);
	SListEraseAfter(pos);
	SListPrint(plist);
	SListDestory(&plist);
	SListPrint(plist);
	return 0;
}