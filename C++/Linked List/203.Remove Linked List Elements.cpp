/*
删除链表中的某个值。
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
	ListNode* removeElements(ListNode* head, int val) {
        ListNode *nhead=new ListNode(0);
        nhead->next = head;
        ListNode *cur = nhead;
        while(cur->next)
        {
        	if(cur->next->val == val)
        	{
        		cur->next = cur->next->next;
        	}
        	else
        	{
        		cur = cur->next;
        	}
        }

        return nhead->next;
    }
};
int main()
{
	Solution s;
	ListNode head(3);
	ListNode t1(2);
	ListNode t2(8);
	ListNode t3(4);
	ListNode t4(3);
	ListNode t5(6);
	head.next = &t1;
	t1.next = &t2;
	t2.next = &t3;
	t3.next = &t4;
	t4.next = &t5;
 	ListNode* h = s.removeElements(&head,3);	
 	while(h)
 	{
 		cout<<h->val<<endl;
 		h = h->next;
 	}
}

