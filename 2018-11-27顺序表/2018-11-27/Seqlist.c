#include "Seqlist.h"

void SeqlistInit(Seqlist* ps,size_t capacity)//初始化数据
{
	assert(ps);
	ps->_array = (SLDateType*)malloc(sizeof(SLDateType)*capacity);
	ps->_size = 0;
	ps->_capacity = capacity;
}

void SeqlistDestory(Seqlist* ps)//销毁数据
{
	assert(ps);
	if(ps-> _array)
	{
		free(ps-> _array);
		ps-> _array = NULL;
		ps-> _size = ps->_capacity = 0;
	}
}
void CheckCapacity(Seqlist* ps)//内存空间不够进行扩容
{
	if(ps->_size == ps->_capacity)
   {
	   ps->_capacity *=2;
	   ps->_array = realloc(ps->_array ,ps->_capacity*sizeof(SLDateType));
	   assert(ps->_array);
   }
}
void SeqlistPushback(Seqlist* ps,SLDateType x)//在尾上插入一个数据
{
   assert(ps);
   CheckCapacity(ps);
   ps->_array [ps->_size ] = x;
   ps->_size ++;
}

void SeqlistPopback(Seqlist* ps)//在尾部删除一个数据
{
	assert(ps && ps->_size >0);
	ps->_array [ps->_size - 1] = 0;
	ps->_size --;
}
void SeqlistPushfront(Seqlist* ps,SLDateType x)//在头上插入一个数据
{
	int  end = ps->_size -1;
	assert(ps);
	CheckCapacity(ps);
	while(end >= 0)
	{
		ps->_array [end + 1] = ps->_array [end];
		end--;
	}
	ps->_array [0] = x;
	ps->_size ++;
}

void SeqlistPopfront(Seqlist* ps)//在头部删除一个数据
{
	size_t begin = 0;
	assert(ps);
	CheckCapacity(ps);
	while(begin < ps->_size - 1)
	{
		ps->_array [begin] = ps->_array [begin + 1];
		begin++;
	}
	ps->_size --;
}

void SeqlistInsert(Seqlist* ps ,size_t pos , SLDateType x)//在任意一个位置插入
{
	//int a =ps->_size - 1;
	//assert(ps && pos <= ps->_size );
	//CheckCapacity(ps);
	//while(a >= (int)pos)
	//{
	//	ps->_array [a + 1] = ps->_array [a];
	//	a--;
	//}
	//ps->_array [pos] = x;
	//ps->_size ++;
	size_t a = ps->_size ;
	assert(ps && pos <= ps->_size );
	CheckCapacity(ps);
	while(a > pos)
	{
		ps->_array [a] = ps->_array [a - 1];
		a--;
	}
	ps->_array [pos] = x;
	ps->_size ++;
}
void SeqlistErase(Seqlist* ps ,size_t pos)//在任意一个位置删除
{
	size_t a = pos;
	assert(ps && pos < ps->_size );
	CheckCapacity(ps);
	while(a < ps->_size -1)
	{
		ps->_array [a] = ps->_array [a + 1];
		a++;
	}
	ps->_size --;
}

int SeqlistFind(Seqlist* ps,SLDateType x)//查找一个元素所在的位置
{
	size_t i = 0;
	assert(ps);
	for(i = 0;i < ps->_size ;i++)
	{
		if(ps->_array [i] = x)
		{
			return 1;
		}
	}
	return -1;
}
size_t SeqlistSize(Seqlist* ps)
{
	assert(ps);
	return ps->_size ;
}
//非空返回01，空返回0；
int SeqlistEmpty(Seqlist* ps)//清空数据元素
{
	assert(ps);
	return ps->_size > 0 ? 1 : 0;
}
void SeqlistModify(Seqlist* ps,size_t pos,SLDateType x)//修改数据元素
{
	assert(ps && pos < ps->_size);
	ps->_array [pos] = x;
}


void SeqlistBubbleSort(Seqlist* ps)//冒泡排序//时间复杂度n2
{
	size_t i = 0;
	SLDateType tmp = 0;
	size_t finish = ps->_size;
	int change = 0;
	while(finish > 1)
	{
		for(i = 0; i < finish ;i++ )
		{
			if(ps->_array[i -1] > ps->_array[i])
			{
				tmp = ps->_array[i - 1];
				ps->_array[i - 1] = ps->_array[i];
				ps->_array[i] = tmp;
				change = 1;
			}
		}
		finish--;
	}
}

int SeqlistBinaryfind(Seqlist* ps, SLDateType x)//二分查找
{
	SLDateType begin = 0;
	SLDateType end = ps->_size - 1;
	int mid = (begin + end)/2;
	assert(ps && ps->_size > 0);
	while(begin <= end)
	{
		if(ps->_array [mid] > x)
		{
			begin = mid + 1;
		}
		else if(ps->_array [mid] < x)
		{
			end = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return 1;
}

void SeqlistRemoveAll(Seqlist* ps, SLDateType x) //删除所有的x
{
	size_t begin = 0;
	size_t end = 0;
	assert(ps);
	while(begin < ps->_size )
	{
		if(ps->_array [begin] != x)
		{
			ps->_array [end] = ps->_array [begin];
			end++;
		}
		begin++;
	}
	ps->_size = end;
}
void SeqlistPrint(Seqlist* ps)//打印输出的数据元素
{
	size_t i = 0;
	assert(ps);
	for(i = 0;i < ps->_size ;i++)
	{
		printf("%d ",ps->_array[i]);
	}
	printf("\n");
}
void SeqlistTest1()//菜单栏
{
	Seqlist s;
	SeqlistInit(&s,10);


	SeqlistPushback(&s,1);
	SeqlistPushback(&s,1);
	SeqlistPushback(&s,1);
	SeqlistPushback(&s,1);
	SeqlistPushback(&s,1);
	SeqlistPushback(&s,1);
	SeqlistPushback(&s,1);
	SeqlistPushback(&s,1);
	SeqlistPushfront(&s,2);
	SeqlistPushfront(&s,2);
    SeqlistPrint(&s);
	
	SeqlistPopback(&s);
	SeqlistPopback(&s);
	SeqlistPopback(&s);
	SeqlistPopfront(&s);
    SeqlistPrint(&s);


	SeqlistDestory(&s);
}
void SeqlistTest2()
{
	Seqlist s;
	SeqlistInit(&s,3);
	SeqlistPushback(&s,1);
	SeqlistPushback(&s,2);
	SeqlistPushback(&s,3);
	SeqlistPushback(&s,4);
	SeqlistInsert(&s,2,30);
	SeqlistInsert(&s,0,30);
	SeqlistErase(&s,1);
	SeqlistPrint(&s);






	SeqlistDestory(&s);
}
void SeqlistTest3()
{
	Seqlist s;
	SeqlistInit(&s,3);
	SeqlistPushback(&s,1);
	SeqlistPushback(&s,2);
	SeqlistPushback(&s,3);
	SeqlistPushback(&s,4);
	SeqlistInsert(&s,2,30);
	SeqlistInsert(&s,0,30);
	SeqlistPrint(&s);

	SeqlistBubbleSort(&s);
	SeqlistPrint(&s);

	SeqlistBinaryfind(&s,2);
	SeqlistPrint(&s);




	SeqlistDestory(&s);
}

void SeqlistTest4()
{
	Seqlist s;
	SeqlistInit(&s,3);
	SeqlistPushback(&s,1);
	SeqlistPushback(&s,2);
	SeqlistPushback(&s,3);
	SeqlistPushback(&s,4);
	SeqlistPushback(&s,4);
	SeqlistPushback(&s,5);
	SeqlistPrint(&s);





	SeqlistRemoveAll(&s,4);
	SeqlistPrint(&s);
	SeqlistDestory(&s);
}