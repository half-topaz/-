#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct ListNode 
{
    int val;
    struct ListNode* next;
};

struct ListNode* removeElements(struct ListNode* head, int val)//����203��������ɾ��ָ���ڵ�
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

struct ListNode* reverseList(struct ListNode* head)//����206����ת������
{
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->next = NULL;
    struct ListNode* tempHead;
    while (head != NULL)//ͷɾ��ͬʱͷ��
    {
        tempHead = head->next;
        head->next = newNode->next;
        newNode->next = head;
        head = tempHead;
    }
    return newNode->next;
}

struct ListNode* middleNode(struct ListNode* head)//����876���������м�ڵ�
{
    struct ListNode* slowhead = head;//��ָ��
    struct ListNode* fasthead = head;//��ָ��
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