/*
将链表循环右移K个位置。
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
	ListNode* rotateRight(ListNode* head, int k) {
        if(!head)   return NULL;
        ListNode *newhead = head, *tail;
        int count = 1;
        while(newhead->next)
        {
        	newhead = newhead->next;
        	count++;
        }
        k = k%count;
        if(count<=1 || k==0)	return head;
        ListNode nHead(0);
        nHead.next = head;
        
        tail = newhead,newhead = &nHead;
        for(int i=0; i < count-k; ++i)
        	newhead = newhead->next;
        cout<<newhead->val<<endl;
        nHead.next = newhead->next;
        newhead->next = NULL;
        tail->next = head;
        return nHead.next;
    }
};
int main()
{
	Solution s;
	ListNode head(1);
	ListNode t1(2);
	ListNode t2(3);
	ListNode t3(4);
	ListNode t4(5);
	ListNode t5(6);
	head.next = &t1;
	t1.next = &t2;
	t2.next = &t3;
	t3.next = &t4;
	t4.next = &t5;
 	ListNode* h = s.rotateRight(&head,1);
 	while(h)
 	{
 		cout<<h->val<<endl;
 		h = h->next;
 	}
}

