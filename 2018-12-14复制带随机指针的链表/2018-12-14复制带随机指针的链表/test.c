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
	//��һ�����ȸ��������е����н��
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
	//�ڶ�������random��������
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
	//����������copy��ȡ����
	RLNote* copyhead, *tail;
	copyhead = tail = (RLNote*)malloc(sizeof(RLNote));
	cur = head;
	while (cur)
	{
		RLNote* copy = cur->next;
		RLNote* next = copy->next;

		tail->next = copy;
		tail = copy;
		//����ԭ���������next
		cur->next = next;
		//ѭ����һ��ʱ��curָ��next
		cur = next;
	}
	RLNote* newnode = copyhead->next;
	free(copyhead);
	return newnode;
}