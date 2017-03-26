/*
把链表逆序。
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
	ListNode* reverseList(ListNode* head) {
		if(!head)	return NULL;
        ListNode nHead(0);
        nHead.next = head;
        ListNode *pre = head, *cur = head->next;
        while(cur)
        {
        	pre->next = cur->next;
        	cur->next = nHead.next;
        	nHead.next = cur;
        	cur = pre->next;
        }
        return nHead.next;
    }
};
int main()
{
	Solution s;
	ListNode head(1);
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
 	ListNode* h = s.reverseList(&head);
 	while(h)
 	{
 		cout<<h->val<<endl;
 		h = h->next;
 	}
}

