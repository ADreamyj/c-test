#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef int HPDateType;

typedef struct Heap
{
	HPDateType* _array;//指向动态开辟的数组
	size_t _size;//有效数据的个数
	size_t _capacity;//容量空间的大小
}Heap;

void HeapInit(Heap* hp, HPDateType* a, size_t n);//初始化二叉树
void HeapDestory(Heap* hp);//释放二叉树

void HeapPrint(Heap* hp);//打印二叉树
 

void HeapPush(Heap* hp, HPDateType x);//插入一个节点
void HeapPop(Heap* hp); //删除一个结点
HPDateType HeapTop(Heap* hp); //返回堆顶
int HeapSize(Heap* hp); //返回结点个数
int HeapEmpty(Heap* hp);//非空返回-1；空返回0；

void HeapSort(int* a, int n);//堆排序

void TestHeap();//菜单栏
void Topk();