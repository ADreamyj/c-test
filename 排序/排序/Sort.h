
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


//typedef int STDataType;
//
//typedef struct Stack
//{
//	STDataType* _a;
//	int _top;       // ջ�� 
//	int _capacity;  // ����
//}Stack;
//void StackInit(Stack* ps)//��ʼ��ջ�ռ�
//{
//	assert(ps);
//	ps->_a = NULL;
//	ps->_capacity = 0;
//	ps->_top = 0;
//}
//void StackDestory(Stack* ps)//����ջ�ռ�
//{
//	assert(ps);
//	free(ps->_a);
//	ps->_a = NULL;
//	ps->_capacity = 0;
//	ps->_top = 0;
//}
//void StackPush(Stack* ps, STDataType x)//��ջ�в���Ԫ��
//{
//	assert(ps);
//	if (ps->_top == ps->_capacity)
//	{
//		int newcapacity = ps->_capacity == 0 ? 1 : ps->_capacity * 2;
//		ps->_a = (STDataType*)realloc(ps->_a, sizeof(STDataType)*newcapacity);
//		assert(ps->_a);
//		ps->_capacity = newcapacity;
//	}
//	ps->_a[ps->_top] = x;
//	ps->_top++;
//
//}
//void StackPop(Stack* ps)//ɾ��ջ�е�Ԫ��
//{
//	assert(ps && ps->_top > 0);
//	ps->_top--;
//}
//STDataType StackTop(Stack* ps)//ջ����Ԫ��
//{
//	assert(ps && ps->_top > 0);
//	return ps->_a[ps->_top - 1];
//}
//int StackEmpty(Stack* ps)//ջ�е�Ԫ���Ƿ�Ϊ��
//{
//	assert(ps);
//	return ps->_top == 0 ? 0 : 1;
//}
//int StackSize(Stack* ps)//ջ��Ԫ�صĸ���
//{
//	assert(ps);
//	return ps->_top;
//}

void test1();
void test2();