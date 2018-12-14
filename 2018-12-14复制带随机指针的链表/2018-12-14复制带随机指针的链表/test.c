/**
* Definition for singly-linked list with a random pointer.
* struct RandomListNode {
*     int label;
*     struct RandomListNode *next;
*     struct RandomListNode *random;
* };
*/
typedef struct RandomListNode RLNote;
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
	//第一步，先复制链表中的所有结点
	RLNote *cur = head;
	RLNote *next;
	while (cur)
	{
		next = cur->next;
		RLNote *copy = (RLNote *)malloc(sizeof(RLNote));
		copy->label = cur->label;
		cur->next = copy;
		copy->next = next;
		cur = next;
	}
	//第二步，将random连接起来
	cur = head;
	while (cur)
	{
		RLNote* copy = cur->next;
		if (cur->random)
			copy->random = cur->random->next;
		else
			copy->random = NULL;
		cur = copy->next;
	}
	//第三步，将copy提取出来
	RLNote* copyhead, *tail;
	copyhead = tail = (RLNote*)malloc(sizeof(RLNote));
	cur = head;
	while (cur)
	{
		RLNote* copy = cur->next;
		RLNote* next = copy->next;

		tail->next = copy;
		tail = copy;
		//链接原链表的所有next
		cur->next = next;
		//循环下一个时将cur指向next
		cur = next;
	}
	RLNote* newnode = copyhead->next;
	free(copyhead);
	return newnode;
}