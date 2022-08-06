#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"
//��ʼ��ջ
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_top = ps->_capacity = 0;
}
//����ջ
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
}
//��ջ
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)//����
	{
		ps->_capacity = ps->_capacity == 0 ? 4 : 2 * ps->_capacity;
	}
	STDataType* tmp = (STDataType*)realloc(ps->_a, ps->_capacity * sizeof(STDataType));
	if (tmp)
	{
		ps->_a = tmp;
		ps->_a[ps->_top] = x;
		++ps->_top;
	}
	else
	{
		perror("realloc failure in realloc");
		exit(-1);
	}
}
//��ջ
void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->_top--;
}
//��ȡջ��Ԫ��
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->_a[ps->_top - 1];
}
//���ջ�Ƿ�Ϊ��
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0;
}