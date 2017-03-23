/*
将链表中节点两个两个互换。
1->2->3->4返回2->1->4->3
只能用常数的空间，不能动链表中的值。
*/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if(!head)	return NULL;	
        ListNode nHead(0);
        nHead.next = head;
        ListNode* pre = &nHead, cur = head, past;
        while(cur && (past=cur->next))
        {
        	pre->next = past;
        	pre = cur;
        	cur = past->next;
        	past->next = pre;
        	pre->next = cur;
        }
        return nHead.next;
};
int main()
{
	Solution s;
	ListNode head(2);
	ListNode t1(5);
	ListNode t2(10);
	ListNode t3(3);
	ListNode t4(6);
	ListNode t5(13);
	head.next = &t1;
	t1.next = &t2;
	t2.next = &t3;
	t3.next = &t4;
	t4.next = &t5;
 	ListNode* h = s.swapPairs(&head);
 	while(h)
 	{
 		cout<<h->val<<endl;
 		h = h->next;
 	}
}

