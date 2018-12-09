#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef int HPDateType;

typedef struct Heap
{
	HPDateType* _array;//ָ��̬���ٵ�����
	size_t _size;//��Ч���ݵĸ���
	size_t _capacity;//�����ռ�Ĵ�С
}Heap;

void HeapInit(Heap* hp, HPDateType* a, size_t n);//��ʼ��������
void HeapDestory(Heap* hp);//�ͷŶ�����

void HeapPrint(Heap* hp);//��ӡ������
 

void HeapPush(Heap* hp, HPDateType x);//����һ���ڵ�
void HeapPop(Heap* hp); //ɾ��һ�����
HPDateType HeapTop(Heap* hp); //���ضѶ�
int HeapSize(Heap* hp); //���ؽ�����
int HeapEmpty(Heap* hp);//�ǿշ���-1���շ���0��

void HeapSort(int* a, int n);//������

void TestHeap();//�˵���
void Topk();