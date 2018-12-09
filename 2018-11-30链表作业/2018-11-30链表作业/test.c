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
	return prev;
}
//递归实现
struct ListNode* reverseList(struct ListNode* head) 
{
	if(head == NULL || head -> next == NULL) return head;
	struct ListNode* h = reverseList(head -> next);
	head -> next -> next = head;
	head -> next = NULL;
	return h;
}

//3.给定一个带有头结点 head 的非空单链表，返回链表的中间结点。

如果有两个中间结点，则返回第二个中间结点。

示例 1：

输入：[1,2,3,4,5]
输出：此列表中的结点 3 (序列化形式：[3,4,5])
返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
注意，我们返回了一个 ListNode 类型的对象 ans，这样：
ans.val = 3, ans.next.val = 4,
ans.next.next.val = 5, 以及 ans.next.next.next = NULL.

示例 2：

输入：[1,2,3,4,5,6]
输出：此列表中的结点 4 (序列化形式：[4,5,6])
由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
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
//5.将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//
示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
1.找到新链表的头结点，两个链表中小的结点作为新链表的头结点；
2.逐步比较两个链表中剩余的元素进行比较，从大到小插入新链表中；
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
//6.编写代码，以给定值x为基准将链表分割成两部分，
//所有小于x的结点排在大于或等于x的结点之前
//给定一个链表的头指针 ListNode* pHead，
//请返回重新排列后的链表的头指针。
//注意：分割以后保持原来的数据顺序不变

1.新建两个链表，一个存放所有小于x的结点，
另一个存放所有大于x的结点。
2.把两个链表拼接，第一个链表的尾连接第二个链表的头。
3.返回第一个链表的有效结点。
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
        //遍历每一个元素
        while(cur)
        {
            //判断当前元素是否小于x
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
        //连接两个新的链表
        ltail->next = ghead->next;
        //链表最后一个为NULL
        gtail->next = NULL;
        pHead = lhead->next;
        free(lhead);
        free(ghead);
        return pHead;
    }
};



7.在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
重复的结点不保留，返回链表头指针。

例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

1.保存当前结点的上一个结点;
2.看下一个结点的值是否和当前结点cur相同，如果相同，
next继续向后遍历，找到第一个和当前结点不同的结点next;
3.删除当前结点cur--next之间的所有结点;
4.重新连接prev--next;
如果cur和next的值不同，cur后移一步，prev指向cur，
next向后移步一位

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
            //判断当前的值是否和下一个结点相同；
            if(cur->val == next->val)
            {
                //向后找第一个值不相等的结点
                next = next->next;
                while(next)
                {
                  if(next->val != cur->val)
                      break;
                      next = next->next;
                }
                //删除cur到next之间的结点
                while(cur != next)
                {
                    struct ListNode* temp = cur;
                    cur = cur->next;
                    free(temp);
                }
                //重新连接链表
                if(prev == NULL)//如果删除的是头结点
                {
                    pHead = next;
                }
                else
                {
                    prev->next = next;
                }
                if(next)//判断最后一个位置有没有值，有值的话继续走
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

题目描述
8.对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。
给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
测试样例：
1->2->2->1
返回：true

回文结构正反顺序相同
0.找到链表的之间结点
1.逆转链表后半部分
2.比较链表其后两部分对应位置的值，如果全部相等，则链表为一个回文结构

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



1.slow走一步，fast走两步。一定为相遇。进环之后，
  每次差距缩小一肯定会有一次到0。
2.slow走一步，fast走两步，不一定相遇。进环之后，
  每次差距缩小二，1-2 = -1 ！=0;