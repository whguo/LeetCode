/*
删除有序链表中数字重复的结点（凡是有重复的全部删除）。
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
	ListNode* deleteDuplicates(ListNode* head) {
		if(!head)	return NULL;
		ListNode nHead(0);
        nHead.next = head;
		ListNode *cur=head,*pre=&nHead;
        while(cur && cur->next)
        {
        	if(cur->val==cur->next->val)
        	{
        		while(cur->next && cur->val==cur->next->val )
        			cur=cur->next;
        		pre->next = cur->next;
        	}
        	else
        		pre = cur;
        	cur = cur->next;
        }
        return nHead.next;
    }
};
int main()
{
	Solution s;
	ListNode head(1);
	ListNode t1(2);
	ListNode t2(2);
	ListNode t3(4);
	ListNode t4(5);
	ListNode t5(5);
	head.next = &t1;
	t1.next = &t2;
	t2.next = &t3;
	t3.next = &t4;
	t4.next = &t5;
 	ListNode* h = s.deleteDuplicates(&head);
 	while(h)
 	{
 		cout<<h->val<<endl;
 		h = h->next;
 	}
}

