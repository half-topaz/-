#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct ListNode 
{
    int val;
    struct ListNode* next;
};

struct ListNode* removeElements(struct ListNode* head, int val)//力扣203，单链表删除指定节点
{
    struct ListNode* empHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    empHead->next = head;
    struct ListNode* tempHead = empHead;
    while (tempHead != NULL && tempHead->next != NULL)
    {
        if (tempHead->next->val == val)
        {
            tempHead->next = tempHead->next->next;
        }
        else
        {
            tempHead = tempHead->next;
        }
    }
    return empHead->next;
}

struct ListNode* reverseList(struct ListNode* head)//力扣206，反转单链表
{
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->next = NULL;
    struct ListNode* tempHead;
    while (head != NULL)//头删的同时头插
    {
        tempHead = head->next;
        head->next = newNode->next;
        newNode->next = head;
        head = tempHead;
    }
    return newNode->next;
}

struct ListNode* middleNode(struct ListNode* head)//力扣876，单链表中间节点
{
    struct ListNode* slowhead = head;//慢指针
    struct ListNode* fasthead = head;//快指针
    while (fasthead != NULL && fasthead->next != NULL)
    {
        slowhead = slowhead->next;
        fasthead = fasthead->next->next;
    }
    return slowhead;
}
int main()
{
    return 0;
}