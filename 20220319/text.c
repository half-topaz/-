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
 
//����160. �ཻ����

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    struct ListNode* nodeA = headA;
    struct ListNode* nodeB = headB;
    while (nodeA != nodeB)
    {
        if (nodeA == NULL)
        {
            nodeA = headB;
            nodeB = nodeB->next;
        }
        else if (nodeB == NULL)
        {
            nodeB = headA;
            nodeA = nodeA->next;
        }
        else
        {
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }
    }
    return nodeA;
}


//����142. �������� II
struct ListNode* detectCycle(struct ListNode* head)
{
    struct ListNode* fasthead = head;
    struct ListNode* slowhead = head;
    while (fasthead != NULL && fasthead->next != NULL)
    {
        fasthead = fasthead->next->next;
        slowhead = slowhead->next;
        if (fasthead == slowhead)
        {
            break;
        }
    }
    if (fasthead == NULL || fasthead->next == NULL)
    {
        return NULL;
    }
    else
    {
        slowhead = head;
        while (fasthead != slowhead)
        {
            fasthead = fasthead->next;
            slowhead = slowhead->next;
        }
        return slowhead;
    }
}

//����141. ��������
bool hasCycle(struct ListNode* head)
{
    struct ListNode* fasthead = head;
    struct ListNode* slowhead = head;
    while (fasthead != NULL && fasthead->next != NULL)
    {
        fasthead = fasthead->next->next;
        slowhead = slowhead->next;
        if (fasthead == slowhead)
        {
            break;
        }
    }
    if (fasthead == NULL || fasthead->next == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

//����138. ���ƴ����ָ�������
//struct Node* copyRandomList(struct Node* head)
//{
//    if (head == NULL)
//    {
//        return NULL;
//    }
//    struct Node* oldhead = head;
//    while (oldhead)
//    {
//        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
//        newnode->val = oldhead->val;
//        newnode->next = oldhead->next;
//        newnode->random = NULL;
//        oldhead->next = newnode;
//        oldhead = oldhead->next->next;
//    }
//    oldhead = head;
//    while (oldhead)
//    {
//        if (oldhead->random == NULL)
//        {
//            oldhead->next->random = NULL;
//        }
//        else
//        {
//            oldhead->next->random = oldhead->random->next;
//        }
//        oldhead = oldhead->next->next;
//    }
//    struct Node* newhead = head->next;
//    while (newhead->next)
//    {
//        newhead->next = newhead->next->next;
//        newhead = newhead->next;
//    }
//    return head->next;
//}

int main()
{
    return 0;
}