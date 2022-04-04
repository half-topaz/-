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

//牛客 链表中倒数第k个节点
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
{
    if (pListHead == NULL)
        return NULL;
    struct ListNode* slowHead = pListHead;//慢指针
    struct ListNode* fastHead = pListHead;//快指针
    while (k--)//快指针先走k个
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
//力扣21，合并有序链表（升序）
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    if (list1 == NULL)//若其中一条链表为空，直接返回另一条链表
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
        while (list1 && list2)//原链表头删、新链表尾插相结合，当其中一条链表为空时结束
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
        //此时剩下的链表必然都大于新链表的末尾
        if (list1 != NULL)//将剩下一条不为空的链表直接连接在新链表之后
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

//牛客CM11 链表分割
struct ListNode* partition(struct ListNode* pHead, int x)
{
    struct ListNode* oldhead = (struct ListNode*)malloc(sizeof(struct ListNode));//旧链表存放大数
    struct ListNode* newhead = (struct ListNode*)malloc(sizeof(struct ListNode));//新链表存放小数
    oldhead->next = pHead;//旧链表连接原链表
    struct ListNode* bighead = oldhead;
    struct ListNode* smallhead = newhead;
    struct ListNode* temp;
    while (bighead->next != NULL)//将小数移动到新链表
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
    smallhead->next = oldhead->next;//新链表尾端连接旧链表头部
    return newhead->next;
}

//牛客OR36 链表的回文结构
bool chkPalindrome(struct ListNode* A)
{
    struct ListNode* slow = A;
    struct ListNode* fast = A;
    while (fast != NULL && fast->next != NULL)//找中点
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* mind = slow;
    struct ListNode* temp;
    while (slow->next)//翻转后半段
    {
        temp = mind;
        mind = slow->next;
        slow->next = mind->next;
        mind->next = temp;
    }
    while (mind)//判断相等
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