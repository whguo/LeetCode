/*
把链表小于给定数的挪到前面，大于等于它的放后面，按照原顺序排列。
*/
/*
思路：1.新建链表，跑两次。
	  2.找到第一个需要插入的地方，然后后边找到小的数依次插入。
	  3.新建两个头结点，然后分别把大的和小的串起来，最后再把大的放在小的后边。
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode node1(0), node2(0);
    	ListNode *p1 = &node1, *p2 = &node2;
    	while (head) {
        	if (head->val < x)
            	p1 = p1->next = head;
        	else
            	p2 = p2->next = head;
        	head = head->next;
    	}
    	p2->next = NULL;
    	p1->next = node2.next;
    	return node1.next;

		/*
        ListNode nHead(0);
        nHead.next = head;
        ListNode *pre,*h=&nHead,*cur;
        while(h->next && h->next->val<x)
        	h = h->next;
        pre = h->next;
        if(pre)		cur = pre->next;
        else return head;
        while(cur)
        {
        	if(cur->val < x)
        	{
        		pre->next = cur->next;
        		cur->next = h->next;
        		h->next = cur;
        		h = cur;
        		cur = pre->next;
        	}
        	else
        	{
        		pre = cur;
        		cur = cur->next;
        	}
        }
        return nHead.next;*/
    }
};
int main()
{
	Solution s;
	ListNode head(4);
	ListNode t1(4);
	ListNode t2(3);
	ListNode t3(2);
	ListNode t4(5);
	ListNode t5(2);
	head.next = &t1;
	t1.next = &t2;
	t2.next = &t3;
	t3.next = &t4;
	t4.next = &t5;
 	ListNode* h = s.partition(&head,3);
 	while(h)
 	{
 		cout<<h->val<<endl;
 		h = h->next;
 	}
}

