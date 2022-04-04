#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode
{
 	int val;
    struct ListNode *next;
 };

//ţ�� �����е�����k���ڵ�
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
{
    if (pListHead == NULL)
        return NULL;
    struct ListNode* slowHead = pListHead;//��ָ��
    struct ListNode* fastHead = pListHead;//��ָ��
    while (k--)//��ָ������k��
    {
        if (fastHead == NULL)
        {
            return NULL;
        }
        fastHead = fastHead->next;
    }
    while (fastHead)
    {
        fastHead = fastHead->next;
        slowHead = slowHead->next;
    }
    return slowHead;
}
//����21���ϲ�������������
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    if (list1 == NULL)//������һ������Ϊ�գ�ֱ�ӷ�����һ������
    {
        return list2;
    }
    else if (list2 == NULL)
    {
        return list1;
    }
    else
    {
        struct ListNode* empHead = (struct ListNode*)malloc(sizeof(struct ListNode));
        struct ListNode* temp;
        struct ListNode* tempHead = empHead;
        while (list1 && list2)//ԭ����ͷɾ��������β�����ϣ�������һ������Ϊ��ʱ����
        {
            if (list1->val > list2->val)
            {
                temp = list2->next;
                list2->next = NULL;
                empHead->next = list2;
                list2 = temp;
                empHead = empHead->next;
            }
            else
            {
                temp = list1->next;
                list1->next = NULL;
                empHead->next = list1;
                list1 = temp;
                empHead = empHead->next;
            }
        }
        //��ʱʣ�µ������Ȼ�������������ĩβ
        if (list1 != NULL)//��ʣ��һ����Ϊ�յ�����ֱ��������������֮��
        {
            empHead->next = list1;
        }
        else
        {
            empHead->next = list2;
        }
        return tempHead->next;
    }
}

//ţ��CM11 ����ָ�
struct ListNode* partition(struct ListNode* pHead, int x)
{
    struct ListNode* oldhead = (struct ListNode*)malloc(sizeof(struct ListNode));//�������Ŵ���
    struct ListNode* newhead = (struct ListNode*)malloc(sizeof(struct ListNode));//��������С��
    oldhead->next = pHead;//����������ԭ����
    struct ListNode* bighead = oldhead;
    struct ListNode* smallhead = newhead;
    struct ListNode* temp;
    while (bighead->next != NULL)//��С���ƶ���������
    {
        if (bighead->next->val < x)
        {
            temp = bighead->next->next;
            bighead->next->next = NULL;
            smallhead->next = bighead->next;
            bighead->next = temp;
            smallhead = smallhead->next;
        }
        else
        {
            bighead = bighead->next;
        }
    }
    smallhead->next = oldhead->next;//������β�����Ӿ�����ͷ��
    return newhead->next;
}

//ţ��OR36 ����Ļ��Ľṹ
bool chkPalindrome(struct ListNode* A)
{
    struct ListNode* slow = A;
    struct ListNode* fast = A;
    while (fast != NULL && fast->next != NULL)//���е�
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* mind = slow;
    struct ListNode* temp;
    while (slow->next)//��ת����
    {
        temp = mind;
        mind = slow->next;
        slow->next = mind->next;
        mind->next = temp;
    }
    while (mind)//�ж����
    {
        if (A->val == mind->val)
        {
            A = A->next;
            mind = mind->next;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    return 0;
}