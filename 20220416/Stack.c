#include "Stack.h"


// 初始化栈 
void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

// 入栈 
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
// 出栈 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}
// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}
// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}
// 销毁栈 
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