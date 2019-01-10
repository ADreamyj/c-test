
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


//typedef int STDataType;
//
//typedef struct Stack
//{
//	STDataType* _a;
//	int _top;       // 栈顶 
//	int _capacity;  // 容量
//}Stack;
//void StackInit(Stack* ps)//初始化栈空间
//{
//	assert(ps);
//	ps->_a = NULL;
//	ps->_capacity = 0;
//	ps->_top = 0;
//}
//void StackDestory(Stack* ps)//销毁栈空间
//{
//	assert(ps);
//	free(ps->_a);
//	ps->_a = NULL;
//	ps->_capacity = 0;
//	ps->_top = 0;
//}
//void StackPush(Stack* ps, STDataType x)//给栈中插入元素
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
//void StackPop(Stack* ps)//删除栈中的元素
//{
//	assert(ps && ps->_top > 0);
//	ps->_top--;
//}
//STDataType StackTop(Stack* ps)//栈顶的元素
//{
//	assert(ps && ps->_top > 0);
//	return ps->_a[ps->_top - 1];
//}
//int StackEmpty(Stack* ps)//栈中的元素是否为空
//{
//	assert(ps);
//	return ps->_top == 0 ? 0 : 1;
//}
//int StackSize(Stack* ps)//栈中元素的个数
//{
//	assert(ps);
//	return ps->_top;
//}

void test1();
void test2();