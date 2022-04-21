#include "Queue.h"
// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->head = q->tail = NULL;
}
// ��β����� 
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
// ��ͷ������ 
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
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->head);
	return q->head->data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->tail);
	return q->tail->data;
}
// ��ȡ��������ЧԪ�ظ��� 
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
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->head == NULL;
}
// ���ٶ��� 
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