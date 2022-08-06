#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;
	int _capacity;
}Stack;

//��ʼ��ջ
void StackInit(Stack* ps);
//����ջ
void StackDestroy(Stack* ps);
//��ջ
void StackPush(Stack* ps, STDataType x);
//��ջ
void StackPop(Stack* ps);
//��ȡջ��Ԫ��
STDataType StackTop(Stack* ps);
//���ջ�Ƿ�Ϊ��
int StackEmpty(Stack* ps);
