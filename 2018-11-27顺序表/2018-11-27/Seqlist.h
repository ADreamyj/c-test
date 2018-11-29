#pragma  once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>


typedef int SLDateType;

//顺序表的动态存储
typedef struct Seqlist
{
	SLDateType* _array;//指向动态开辟的数组
	size_t _size;//有效数据的个数
	size_t _capacity;//容量空间的的大小
}Seqlist;


void SeqlistInit(Seqlist* ps,size_t capacity);//初始化数据
void SeqlistDestory(Seqlist* ps);//销毁数据
void CheckCapacity(Seqlist* ps);//内存空间不够进行扩容

void SeqlistPushback(Seqlist* ps,SLDateType x);//在尾上插入一个数据
void SeqlistPopback(Seqlist* ps);//在尾部删除一个数据

void SeqlistPushfront(Seqlist* ps,SLDateType x);//在头上插入一个数据
void SeqlistPopfront(Seqlist* ps);//在头部删除一个数据

void SeqlistInsert(Seqlist* ps ,size_t pos , SLDateType x);//在任意一个位置插入
void SeqlistErase(Seqlist* ps ,size_t pos);//在任意一个位置删除

int SeqlistFind(Seqlist* ps,SLDateType x);//查找一个元素所在的位置
size_t SeqlistSize(Seqlist* ps);
int SeqlistEmpty(Seqlist* ps);//清空数据元素
void SeqlistModify(Seqlist* ps,size_t pos,SLDateType x);//修改数据元素


//笔试必考重点
void SeqlistBubbleSort(Seqlist* ps);//冒泡排序
int SeqlistBinaryfind(Seqlist* ps, SLDateType x); //二分查找
// 本题要求：时间复杂度：O(N) 空间复杂度 O(1)
void SeqlistRemoveAll(Seqlist* ps, SLDateType x); //删除所有的x


void SeqlistPrint(Seqlist* ps);//打印输出的数据元素
void SeqlistTest1();//菜单栏
void SeqlistTest2();//菜单栏
void SeqlistTest3();//菜单栏
void SeqlistTest4();//菜单栏