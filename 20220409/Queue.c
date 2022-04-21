#include "Queue.h"
// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->head = q->tail = NULL;
}
// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = data;
	newNode->next = NULL;
	if (q->head == NULL)
	{
		q->head = newNode;
		q->tail = newNode;
	}
	else
	{
		q->tail->next = newNode;
		q->tail = newNode;
	}
}
// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q);
	assert(q->head);
	if (q->head == q->tail)
	{
		QueueInit(q);
	}
	else
	{
		QNode* s = q->head;
		q->head = q->head->next;
		free(s);
	}
}
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->head);
	return q->head->data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->tail);
	return q->tail->data;
}
// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q);
	if (q->head == NULL)
	{
		return 0;
	}
	else
	{
		int i = 1;
		QNode* s = q->head;
		while (s != q->tail)
		{
			i++;
			s = s->next;
		}
		return i;
	}
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->head == NULL;
}
// 销毁队列 
void QueueDestroy(Queue* q)
{
	assert(q);
	while (q->head!=NULL)
	{
		QNode* s = q->head;
		q->head = q->head->next;
		free(s);
	}
	q->tail = NULL;
}

//void PrintQueue(Queue* q)
//{
//	assert(q);
//	if (q->head == NULL)
//	{
//		printf("Qeueu Empty\n");
//	}
//	else
//	{
//		QNode* s = q->head;
//		while (s != NULL)
//		{
//			printf("%d ", s->data);
//			s = s->next;
//		}
//		printf("\n");
//	}
//}