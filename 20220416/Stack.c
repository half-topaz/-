#include "Stack.h"


// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

// ��ջ 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->capacity == ps->top)
	{
		ps->capacity = ps->capacity == 0 ? 4 : ps->capacity*2;
		ps->a = (STDataType*)realloc(ps->a, ps->capacity*sizeof(STDataType));
		if (ps->a == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
	}
	ps->a[ps->top] = data;
	ps->top++;
}
// ��ջ 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}
// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}
// ����ջ 
void StackDestroy(Stack* ps)
{
	assert(ps);
	assert(ps->a);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

void PrintStack(Stack* ps)
{
	assert(ps);
	if (ps->a == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		int i = 0;
		for (i = 0;i < ps->top;i++)
		{
			printf("%d ", ps->a[i]);
		}
		printf("\n");
	}
}