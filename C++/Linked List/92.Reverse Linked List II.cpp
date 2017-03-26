/*
把链表中第m和第n个结点之间逆序。
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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode nHead(0);
        nHead.next = head;
        ListNode *preM = &nHead, *cur,*tmp;
        for (int i = 0; i < m-1; ++i)
        {
        	preM = preM->next;
        }
        cur = preM->next;
        for(int i=0; i < n-m; ++i)
        {
        	tmp = cur->next;
        	cur->next = tmp->next;
        	tmp->next = preM->next;
        	preM->next = tmp;
        }
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
 	ListNode* h = s.reverseBetween(&head,2,4);
 	while(h)
 	{
 		cout<<h->val<<endl;
 		h = h->next;
 	}
}

