#define CRT_SECURE_NO_WARNINGS

//1.删除链表中等于给定值 val 的所有节点。
//
//示例:
//
//输入: 1->2->6->3->4->5->6, val = 6
//输出: 1->2->3->4->5

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
        //当前结点的值val要删除
        if(cur->val == val)
        {
            //先获取cur->next
            next = cur->next;
            free(cur);
            cur = next;
            //删除的是否为头结点
            if(prev == NULL)
            {
                head = next;
            }
            //删除的不是头结点
            else
            {
                prev->next = next;
            }
        }
        //当前结点不需要删除
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}

//2.反转一个单链表。
//
//示例:
//
//输入: 1->2->3->4->5->NULL
//输出: 5->4->3->2->1->NULL

struct ListNode* reverseList(struct ListNode* head)
{
	struct ListNode* prev = NULL;
	struct ListNode* cur = head;
	struct ListNode* next;
	while(cur)
	{
		//先获取下一个结点
		next = cur->next;
		//更改当前结点的指向
		cur->next =prev;
		prev = cur;
		cur = next;
	}
	return next;
}

//3.给定一个带有头结点 head 的非空单链表，返回链表的中间结点。

//如果有两个中间结点，则返回第二个中间结点。

//示例 1：

//输入：[1,2,3,4,5]
//输出：此列表中的结点 3 (序列化形式：[3,4,5])
//返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
//注意，我们返回了一个 ListNode 类型的对象 ans，这样：
//ans.val = 3, ans.next.val = 4,
//ans.next.next.val = 5, 以及 ans.next.next.next = NULL.

//示例 2：
//
//输入：[1,2,3,4,5,6]
//输出：此列表中的结点 4 (序列化形式：[4,5,6])
//由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
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
    //定义两个指针，快指针和慢指针
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
//4.返回倒数第k个链表
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
//5.将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//
//示例：
//
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4
//1.找到新链表的头结点，两个链表中小的结点作为新链表的头结点；
//2.逐步比较两个链表中剩余的元素进行比较，从大到小插入新链表中；
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
    //确定新的头结点
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
    //如果l1和l2都有有效结点，逐个比较把新的放到尾部
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
    //如果还有一个链表没有遍历完，把这个链表放到尾部
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
