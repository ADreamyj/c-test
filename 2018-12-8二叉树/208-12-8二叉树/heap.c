#include"heap.h"

void swap(HPDateType* p1, HPDateType* p2)
{
	HPDateType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void AdjustDwon(HPDateType* a, size_t n, int root)//向下调整法
{
	size_t parent = root;
	size_t child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
			child++;
		if (a[child] > a[parent])
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void Adjustup(HPDateType* a, size_t n, size_t child)//向上调整法
{
	size_t parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapInit(Heap* hp, HPDateType* a, size_t n)//初始化二叉树
{
	assert(hp && a);
	hp->_array = (HPDateType*)malloc(sizeof(HPDateType)*n);
	hp->_size = hp->_capacity = n;

	memcpy(hp->_array, a, sizeof(HPDateType)*n);
	//建堆
	for (int i = (hp->_size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDwon(hp->_array, hp->_size, i);
	}
}

void HeapPush(Heap* hp, HPDateType x)//插入一个节点
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_array = (HPDateType*)realloc(hp->_array, hp->_capacity*sizeof(HPDateType));
		assert(hp->_array);
	}

	hp->_array[hp->_size] = x;
	hp->_size++;
	Adjustup(hp->_array , hp->_size , hp->_size -1);
}

void HeapPop(Heap* hp) //删除一个结点
{
	assert(hp);
	swap(&hp->_array[0], &hp->_array[hp->_size-1]);
	hp->_size--;
	AdjustDwon(hp->_array, hp->_size, 0);
}
size_t HeapSize(Heap* hp)//返回结点个数
{
	assert(hp);
	return hp->_size;
}
size_t HeapEmpty(Heap* hp)//非空返回-1；空返回0
{
	assert(hp);
	return hp->_size == 0 ? 0 : 1;
}
HPDateType HeapTop(Heap* hp)//返回堆顶
{
	assert(hp);
	return hp->_array[0];
}
void HeapDestory(Heap* hp)//释放二叉树
{
	assert(hp);
	free(hp->_array);
	hp->_array = NULL;
	hp->_size = hp->_capacity = 0;
}

void HeapPrint(Heap* hp)//打印二叉树
{
	assert(hp);
	for (size_t i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_array[i]);
	}
	printf("\n");
}
//升序--大堆
void HeapSort(int* a, int n)//堆排序
{
	//建大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}
	//交换
	size_t end = n - 1;
	while (end > 0)
	{
		swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		end--;
	}
}
void Topk()//选出最大的10个数
{
	const size_t N = 1000000;
	const size_t k = 10;
	size_t*a = (size_t*)malloc(sizeof(size_t)*N);
	srand(time(0));
	for (size_t i = 0; i < N; ++i)
	{
		a[i] = rand();
	}

	Heap hp;
	HeapInit(&hp, a, k);
	for (size_t i = k; i < N; i++)
	{
		if (HeapTop(&hp) < a[i])
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}
	HeapPrint(&hp);
}
void TestHeap()//菜单栏
{
	int a[] = { 2, 7, 8, 9, 5, 6, 4, 0, 66, 5, 5, 6 };
	Heap hp;
	HeapInit(&hp,a,sizeof(a)/sizeof(a[0]));
	HeapPrint(&hp);

	HeapPush(&hp, 100);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapSort(a, sizeof(a) / sizeof(int));
	for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	HeapDestory(&hp);
}