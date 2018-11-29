#pragma  once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>


typedef int SLDateType;

//˳���Ķ�̬�洢
typedef struct Seqlist
{
	SLDateType* _array;//ָ��̬���ٵ�����
	size_t _size;//��Ч���ݵĸ���
	size_t _capacity;//�����ռ�ĵĴ�С
}Seqlist;


void SeqlistInit(Seqlist* ps,size_t capacity);//��ʼ������
void SeqlistDestory(Seqlist* ps);//��������
void CheckCapacity(Seqlist* ps);//�ڴ�ռ䲻����������

void SeqlistPushback(Seqlist* ps,SLDateType x);//��β�ϲ���һ������
void SeqlistPopback(Seqlist* ps);//��β��ɾ��һ������

void SeqlistPushfront(Seqlist* ps,SLDateType x);//��ͷ�ϲ���һ������
void SeqlistPopfront(Seqlist* ps);//��ͷ��ɾ��һ������

void SeqlistInsert(Seqlist* ps ,size_t pos , SLDateType x);//������һ��λ�ò���
void SeqlistErase(Seqlist* ps ,size_t pos);//������һ��λ��ɾ��

int SeqlistFind(Seqlist* ps,SLDateType x);//����һ��Ԫ�����ڵ�λ��
size_t SeqlistSize(Seqlist* ps);
int SeqlistEmpty(Seqlist* ps);//�������Ԫ��
void SeqlistModify(Seqlist* ps,size_t pos,SLDateType x);//�޸�����Ԫ��


//���Աؿ��ص�
void SeqlistBubbleSort(Seqlist* ps);//ð������
int SeqlistBinaryfind(Seqlist* ps, SLDateType x); //���ֲ���
// ����Ҫ��ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1)
void SeqlistRemoveAll(Seqlist* ps, SLDateType x); //ɾ�����е�x


void SeqlistPrint(Seqlist* ps);//��ӡ���������Ԫ��
void SeqlistTest1();//�˵���
void SeqlistTest2();//�˵���
void SeqlistTest3();//�˵���
void SeqlistTest4();//�˵���