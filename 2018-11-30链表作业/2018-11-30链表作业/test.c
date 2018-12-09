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
	return prev;
}
//�ݹ�ʵ��
struct ListNode* reverseList(struct ListNode* head) 
{
	if(head == NULL || head -> next == NULL) return head;
	struct ListNode* h = reverseList(head -> next);
	head -> next -> next = head;
	head -> next = NULL;
	return h;
}

//3.����һ������ͷ��� head �ķǿյ���������������м��㡣

����������м��㣬�򷵻صڶ����м��㡣

ʾ�� 1��

���룺[1,2,3,4,5]
��������б��еĽ�� 3 (���л���ʽ��[3,4,5])
���صĽ��ֵΪ 3 �� (����ϵͳ�Ըý�����л������� [3,4,5])��
ע�⣬���Ƿ�����һ�� ListNode ���͵Ķ��� ans��������
ans.val = 3, ans.next.val = 4,
ans.next.next.val = 5, �Լ� ans.next.next.next = NULL.

ʾ�� 2��

���룺[1,2,3,4,5,6]
��������б��еĽ�� 4 (���л���ʽ��[4,5,6])
���ڸ��б��������м��㣬ֵ�ֱ�Ϊ 3 �� 4�����Ƿ��صڶ�����㡣
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
    while(k--)
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
ʾ����

���룺1->2->4, 1->3->4
�����1->1->2->3->4->4
1.�ҵ��������ͷ��㣬����������С�Ľ����Ϊ�������ͷ��㣻
2.�𲽱Ƚ�����������ʣ���Ԫ�ؽ��бȽϣ��Ӵ�С�����������У�
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
//6.��д���룬�Ը���ֵxΪ��׼������ָ�������֣�
//����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ
//����һ�������ͷָ�� ListNode* pHead��
//�뷵���������к�������ͷָ�롣
//ע�⣺�ָ��Ժ󱣳�ԭ��������˳�򲻱�

1.�½���������һ���������С��x�Ľ�㣬
��һ��������д���x�Ľ�㡣
2.����������ƴ�ӣ���һ�������β���ӵڶ��������ͷ��
3.���ص�һ���������Ч��㡣
lesshead    lesstail      cur
greathead   greattail

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x)
    {
        struct ListNode* lhead ,*ltail;
        struct ListNode* ghead,*gtail;
        struct ListNode* cur = pHead;
        ltail = lhead = (struct ListNode*)malloc(sizeof(struct ListNode));
        gtail = ghead = (struct ListNode*)malloc(sizeof(struct ListNode));
        //����ÿһ��Ԫ��
        while(cur)
        {
            //�жϵ�ǰԪ���Ƿ�С��x
            if(cur->val < x)
            {
                ltail->next = cur;
                ltail = ltail->next;
            }
            else
            {
                gtail->next = cur;
                gtail = gtail->next;
            }
            cur = cur->next;
        }
        //���������µ�����
        ltail->next = ghead->next;
        //�������һ��ΪNULL
        gtail->next = NULL;
        pHead = lhead->next;
        free(lhead);
        free(ghead);
        return pHead;
    }
};



7.��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬
�ظ��Ľ�㲻��������������ͷָ�롣

���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5

1.���浱ǰ������һ�����;
2.����һ������ֵ�Ƿ�͵�ǰ���cur��ͬ�������ͬ��
next�������������ҵ���һ���͵�ǰ��㲻ͬ�Ľ��next;
3.ɾ����ǰ���cur--next֮������н��;
4.��������prev--next;
���cur��next��ֵ��ͬ��cur����һ����prevָ��cur��
next����Ʋ�һλ

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        struct ListNode* prev = NULL;
        struct ListNode* cur = pHead;
        struct ListNode* next = pHead->next;
        if(pHead == NULL || pHead->next == NULL)
        {
            return pHead;
        }
        while(next)
        {
            //�жϵ�ǰ��ֵ�Ƿ����һ�������ͬ��
            if(cur->val == next->val)
            {
                //����ҵ�һ��ֵ����ȵĽ��
                next = next->next;
                while(next)
                {
                  if(next->val != cur->val)
                      break;
                      next = next->next;
                }
                //ɾ��cur��next֮��Ľ��
                while(cur != next)
                {
                    struct ListNode* temp = cur;
                    cur = cur->next;
                    free(temp);
                }
                //������������
                if(prev == NULL)//���ɾ������ͷ���
                {
                    pHead = next;
                }
                else
                {
                    prev->next = next;
                }
                if(next)//�ж����һ��λ����û��ֵ����ֵ�Ļ�������
                next = next->next;
            }
            else
            {
                prev = cur;
                cur = next;
                next = next->next;
            } 
        }
        return pHead;
    }
};

��Ŀ����
8.����һ�����������һ��ʱ�临�Ӷ�ΪO(n),����ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ��
����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ����֤������С�ڵ���900��
����������
1->2->2->1
���أ�true

���Ľṹ����˳����ͬ
0.�ҵ������֮����
1.��ת�����벿��
2.�Ƚ�������������ֶ�Ӧλ�õ�ֵ�����ȫ����ȣ�������Ϊһ�����Ľṹ

struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    struct ListNode* next;
    while(cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    if(head == NULL || head -> next == NULL)
        return true;
    while(fast!= NULL && fast -> next!= NULL)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    slow = reverseList(slow);
    while(slow)
    {
        if(slow -> val != head -> val )
        {
            return false;
        }
        slow = slow -> next;
        head = head -> next;
    }
    return true;
}



1.slow��һ����fast��������һ��Ϊ����������֮��
  ÿ�β����Сһ�϶�����һ�ε�0��
2.slow��һ����fast����������һ������������֮��
  ÿ�β����С����1-2 = -1 ��=0;