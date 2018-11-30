#define CRT_SECURE_NO_WARNINGS

//1.ɾ�������е��ڸ���ֵ val �����нڵ㡣
//
//ʾ��:
//
//����: 1->2->6->3->4->5->6, val = 6
//���: 1->2->3->4->5

	/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    struct ListNode* next;
    while(cur)
    {
        //��ǰ����ֵvalҪɾ��
        if(cur->val == val)
        {
            //�Ȼ�ȡcur->next
            next = cur->next;
            free(cur);
            cur = next;
            //ɾ�����Ƿ�Ϊͷ���
            if(prev == NULL)
            {
                head = next;
            }
            //ɾ���Ĳ���ͷ���
            else
            {
                prev->next = next;
            }
        }
        //��ǰ��㲻��Ҫɾ��
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}

//2.��תһ��������
//
//ʾ��:
//
//����: 1->2->3->4->5->NULL
//���: 5->4->3->2->1->NULL

struct ListNode* reverseList(struct ListNode* head)
{
	struct ListNode* prev = NULL;
	struct ListNode* cur = head;
	struct ListNode* next;
	while(cur)
	{
		//�Ȼ�ȡ��һ�����
		next = cur->next;
		//���ĵ�ǰ����ָ��
		cur->next =prev;
		prev = cur;
		cur = next;
	}
	return next;
}

//3.����һ������ͷ��� head �ķǿյ���������������м��㡣

//����������м��㣬�򷵻صڶ����м��㡣

//ʾ�� 1��

//���룺[1,2,3,4,5]
//��������б��еĽ�� 3 (���л���ʽ��[3,4,5])
//���صĽ��ֵΪ 3 �� (����ϵͳ�Ըý�����л������� [3,4,5])��
//ע�⣬���Ƿ�����һ�� ListNode ���͵Ķ��� ans��������
//ans.val = 3, ans.next.val = 4,
//ans.next.next.val = 5, �Լ� ans.next.next.next = NULL.

//ʾ�� 2��
//
//���룺[1,2,3,4,5,6]
//��������б��еĽ�� 4 (���л���ʽ��[4,5,6])
//���ڸ��б��������м��㣬ֵ�ֱ�Ϊ 3 �� 4�����Ƿ��صڶ�����㡣
struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* cur = head;
    int count = 0;
    int mid = 0;
    while(cur)
    {
        count++;
        cur = cur->next;
    }
    
    mid = count/2;
    cur = head;
    
    while(mid--)
    {
        cur = cur->next;
    }
    return cur;
}

struct ListNode* middleNode(struct ListNode* head)
{
    //��������ָ�룬��ָ�����ָ��
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next; 
    }
    return slow;
}

struct ListNode* fast = head;
struct ListNode* slow = head;
while(k--)
{
	if(fast)
	{
		fast = fast->next;
	}
	else
	{
		return NULL;
	}
	//
	while(fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}
//4.���ص�����k������
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
    struct ListNode* fast = pListHead;
    struct ListNode* slow = pListHead;
    for(int i=0;i<k;i++)
    {
        if(fast == NULL)
    {
    return NULL;
    }
        fast = fast->next;
    }
    while(fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
    
    
};
//5.��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ� 
//
//ʾ����
//
//���룺1->2->4, 1->3->4
//�����1->1->2->3->4->4
//1.�ҵ��������ͷ��㣬����������С�Ľ����Ϊ�������ͷ��㣻
//2.�𲽱Ƚ�����������ʣ���Ԫ�ؽ��бȽϣ��Ӵ�С�����������У�
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* head;
    struct ListNode* tail;
    if(l1 == NULL)
    {
        return l2;
    }
    if(l2 == NULL)
    {
        return l1;
    }
    //ȷ���µ�ͷ���
    if(l1->val < l2->val)
    {
        head = l1;
        l1 = l1->next;
    }
    else
    {
        head = l2;
        l2 = l2->next;
    }
    tail = head;
    //���l1��l2������Ч��㣬����Ƚϰ��µķŵ�β��
    while(l1 && l2)
    {
        if(l1->val < l2->val)
        {
            tail->next = l1;
            tail = tail->next;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            tail = tail->next;
            l2 = l2->next;
        }
    }
    //�������һ������û�б����꣬���������ŵ�β��
    if(l1)
    {
        tail->next = l1;
    }
    if(l2)
    {
        tail->next = l2;
    }
    return head;
    
}
