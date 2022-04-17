#include "Stack.h"

int main()
{
	Stack* ps=(Stack*)malloc(sizeof(Stack));
	StackInit(ps);
	StackPush(ps, 0);
	StackPush(ps, 1);
	StackPush(ps, 2);
	StackPush(ps, 3);
	StackPush(ps, 4);
	StackPush(ps, 5);
	PrintStack(ps);
	StackPop(ps);
	StackPop(ps);
	PrintStack(ps);
	StackPush(ps, 6);
	StackPush(ps, 7);
	StackPush(ps, 8);
	PrintStack(ps);
	StackDestroy(ps);
	PrintStack(ps);
	return 0;
}

//#include "Queue.h"
//
//int main()
//{
//	Queue* q = (Queue*)malloc(sizeof(Queue));
//	QueueInit(q);
//	PrintQueue(q);
//	QueuePush(q, 0);
//	QueuePush(q, 1);
//	QueuePush(q, 2);
//	QueuePush(q, 3);
//	QueuePush(q, 4);
//	PrintQueue(q);
//	QueuePop(q);
//	QueuePop(q);
//	PrintQueue(q);
//	printf("head=%d\n", QueueFront(q));
//	printf("tail=%d\n", QueueBack(q));
//	printf("empty?  %d\n", QueueEmpty(q));
//	QueueDestroy(q);
//	PrintQueue(q);
//	return 0;
//}




//leetcode225 用队列实现栈
//typedef struct QNode
//{
//    int data;
//    struct QNode* next;
//}QNode;
//typedef struct
//{
//    QNode* head1;//头1
//    QNode* tail1;//尾1
//    QNode* head2;//头2
//    QNode* tail2;//尾2
//} MyStack;
//MyStack* myStackCreate()
//{
//    MyStack* NewQueue = (MyStack*)malloc(sizeof(MyStack));
//    assert(NewQueue);
//    NewQueue->head1 = NULL;
//    NewQueue->head2 = NULL;
//    NewQueue->tail1 = NULL;
//    NewQueue->tail2 = NULL;
//    return NewQueue;
//}
//void myStackPush(MyStack* obj, int x)
//{
//    assert(obj);
//    QNode* newNode = (QNode*)malloc(sizeof(QNode));
//    assert(newNode);
//    newNode->data = x;
//    newNode->next = NULL;
//    if (obj->head1 == NULL)
//    {
//        obj->head1 = newNode;
//        obj->tail1 = newNode;
//    }
//    else
//    {
//        obj->tail1->next = newNode;
//        obj->tail1 = newNode;
//    }
//}
//int myStackPop(MyStack* obj)
//{
//    assert(obj);
//    //队列头尾地址不相等说明至少有两个数据，需要进行队列交换，如果相等说明队列为空或者只一个数据，题目保证了pop时不为空，所以只需要考虑一个数据情况。只有一个数据的情况下不需要进行队列交换，直接出栈。
//    while (obj->head1 != obj->tail1)
//    {
//        if (obj->head2 == NULL)
//        {
//            obj->head2 = obj->tail2 = obj->head1;
//            obj->head1 = obj->head1->next;
//            obj->tail2->next = NULL;
//        }
//        else
//        {
//            QNode* s = obj->head1->next;
//            obj->tail2->next = obj->head1;
//            obj->tail2 = obj->tail2->next;
//            obj->tail2->next = NULL;
//            obj->head1 = s;
//        }
//    }
//    int i = obj->head1->data;//提取值
//    free(obj->head1);//出栈
//    //将队列进行交换
//    obj->head1 = obj->head2;
//    obj->head2 = NULL;
//    obj->tail1 = obj->tail2;
//    obj->tail2 = NULL;
//    return i;
//}
//int myStackTop(MyStack* obj)
//{
//    assert(obj);
//    return obj->tail1->data;
//}
//bool myStackEmpty(MyStack* obj)
//{
//    assert(obj);
//    return (obj->head1 == NULL) && (obj->head2 == NULL);
//}
//void myStackFree(MyStack* obj)
//{
//    assert(obj);
//    while (obj->head1 != NULL)
//    {
//        QNode* s = obj->head1;
//        obj->head1 = obj->head1->next;
//        free(s);
//    }
//    obj->tail1 = NULL;
//}


//leetcode232.用栈实现队列
//typedef struct Stack
//{
//    int* a;
//    int size;
//    int capacity;
//}Stack;
//
//typedef struct
//{
//    Stack* S1;
//    Stack* S2;
//} MyQueue;
//
//Stack* StackCreate()
//{
//    Stack* newStack = (Stack*)malloc(sizeof(Stack));
//    newStack->a = NULL;
//    newStack->size = newStack->capacity = 0;
//    return newStack;
//}
//
//MyQueue* myQueueCreate()
//{
//    MyQueue* newQueue = (MyQueue*)malloc(sizeof(MyQueue));
//    newQueue->S1 = StackCreate();
//    newQueue->S2 = StackCreate();
//    return newQueue;
//}
//
//void myQueuePush(MyQueue* obj, int x)
//{
//    assert(obj);
//    assert(obj->S1 && obj->S2);
//    if (obj->S1->capacity == obj->S1->size)
//    {
//        int newcapacity = obj->S1->capacity;
//        newcapacity = newcapacity == 0 ? 5 : newcapacity * 2;
//        obj->S1->a = (int*)realloc(obj->S1->a, sizeof(int) * newcapacity);
//        if (obj->S1->a == NULL)
//        {
//            printf("realloc fail\n");
//            exit(-1);
//        }
//        obj->S1->capacity = newcapacity;
//    }
//    obj->S1->a[obj->S1->size++] = x;
//}
//
//int myQueuePop(MyQueue* obj)
//{
//    assert(obj);
//    assert(obj->S1 && obj->S2);
//    if (obj->S1->size > 0 && obj->S2->size == 0)
//    {
//        while (obj->S1->size > 0)
//        {
//            if (obj->S2->capacity == obj->S2->size)
//            {
//                int newcapacity = obj->S2->capacity;
//                newcapacity = newcapacity == 0 ? 5 : newcapacity * 2;
//                obj->S2->a = (int*)realloc(obj->S2->a, sizeof(int) * newcapacity);
//                if (obj->S2->a == NULL)
//                {
//                    printf("realloc fail\n");
//                    exit(-1);
//                }
//                obj->S2->capacity = newcapacity;
//            }
//            obj->S2->a[obj->S2->size++] = obj->S1->a[--obj->S1->size];
//        }
//    }
//    return obj->S2->a[--obj->S2->size];
//}
//
//int myQueuePeek(MyQueue* obj)
//{
//    assert(obj);
//    assert(obj->S1 && obj->S2);
//    if (obj->S2->size == 0)
//    {
//        return obj->S1->a[0];
//    }
//    else
//    {
//        return obj->S2->a[obj->S2->size - 1];
//    }
//}
//
//bool myQueueEmpty(MyQueue* obj)
//{
//    assert(obj);
//    assert(obj->S1 && obj->S2);
//    if (obj->S1->size == 0 && obj->S2->size == 0)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//
//void myQueueFree(MyQueue* obj)
//{
//    assert(obj);
//	  assert(obj->S1&& obj->S2);
//	  free(obj->S1->a);
//	  free(obj->S2->a);
//	  free(obj->S1);
//	  free(obj->S2);
//	  free(obj);
//}


//leetcode622. 设计循环队列
//typedef struct Qnode
//{
//    int data;
//    struct Qnode* front;
//    struct Qnode* next;
//}Qnode;
//
//typedef struct
//{
//    int capacity;
//    int size;
//    Qnode* head;
//    Qnode* tail;
//} MyCircularQueue;
//
//
//MyCircularQueue* myCircularQueueCreate(int k)
//{
//    MyCircularQueue* newQueue = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//    newQueue->capacity = k;
//    newQueue->size = 0;
//    newQueue->head = NULL;
//    newQueue->tail = NULL;
//    return newQueue;
//}
//
//bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
//{
//    assert(obj);
//    if (obj->size < obj->capacity)
//    {
//        Qnode* newNode = (Qnode*)malloc(sizeof(Qnode));
//        newNode->data = value;
//        if (obj->head == NULL)
//        {
//            newNode->front = newNode->next = newNode;
//            obj->head = obj->tail = newNode;
//        }
//        else
//        {
//            newNode->front = obj->tail;
//            newNode->next = obj->head;
//            obj->tail->next = newNode;
//            obj->head->front = newNode;
//            obj->tail = newNode;
//        }
//        obj->size++;
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//
//bool myCircularQueueDeQueue(MyCircularQueue* obj)
//{
//    assert(obj);
//    if (obj->size > 1)
//    {
//        Qnode* sz = obj->head;
//        obj->head = obj->head->next;
//        obj->head->front = obj->tail;
//        obj->tail->next = obj->head;
//        free(sz);
//        obj->size--;
//        return true;
//    }
//    else if (obj->size == 1)
//    {
//        free(obj->head);
//        obj->head = NULL;
//        obj->tail = NULL;
//        obj->size--;
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//
//int myCircularQueueFront(MyCircularQueue* obj)
//{
//    assert(obj);
//    if (obj->size == 0)
//    {
//        return -1;
//    }
//    else
//    {
//        return obj->head->data;
//    }
//}
//
//int myCircularQueueRear(MyCircularQueue* obj)
//{
//    assert(obj);
//    if (obj->size == 0)
//    {
//        return -1;
//    }
//    else
//    {
//        return obj->tail->data;
//    }
//}
//
//bool myCircularQueueIsEmpty(MyCircularQueue* obj)
//{
//    assert(obj);
//    if (obj->size == 0)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//
//bool myCircularQueueIsFull(MyCircularQueue* obj)
//{
//    assert(obj);
//    if (obj->size == obj->capacity)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//
//void myCircularQueueFree(MyCircularQueue* obj)
//{
//    assert(obj);
//    while (myCircularQueueDeQueue(obj));
//}