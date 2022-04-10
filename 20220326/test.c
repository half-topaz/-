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
	StackPop(ps);
	StackPop(ps);
	StackPop(ps);
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




//leetcode225 �ö���ʵ��ջ
//typedef struct QNode
//{
//    int data;
//    struct QNode* next;
//}QNode;
//typedef struct
//{
//    QNode* head1;//ͷ1
//    QNode* tail1;//β1
//    QNode* head2;//ͷ2
//    QNode* tail2;//β2
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
//    //����ͷβ��ַ�����˵���������������ݣ���Ҫ���ж��н�����������˵������Ϊ�ջ���ֻһ�����ݣ���Ŀ��֤��popʱ��Ϊ�գ�����ֻ��Ҫ����һ�����������ֻ��һ�����ݵ�����²���Ҫ���ж��н�����ֱ�ӳ�ջ��
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
//    int i = obj->head1->data;//��ȡֵ
//    free(obj->head1);//��ջ
//    //�����н��н���
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