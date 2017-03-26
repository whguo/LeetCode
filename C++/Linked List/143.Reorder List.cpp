/*
给链表重新排序。
 L: L0→L1→…→Ln-1→Ln 重排为 L0→Ln→L1→Ln-1→L2→Ln-2→…
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
	void reorderList(ListNode* head) {
        if (!head || !head->next)	return;
		ListNode *slow=head,*fast=head->next,*tmp;

		//快慢指针找到中间
		while(fast && fast->next)
			fast = fast->next->next , slow = slow->next;

		ListNode *head2 = slow->next;
		slow->next = NULL;	

		//后一半逆序
		fast = head2->next;
		head2->next = NULL;
		while(fast)
		{
			slow = fast->next;
			fast->next = head2;
			head2 = fast;
			fast = slow;
		}

		//两个合并
		slow = head,fast=head2;
		while(slow)
		{
			tmp = slow->next;
			slow = slow->next = fast;
			fast = tmp;
		}
    }
};
int main()
{
	Solution s;
	ListNode head(3);
	ListNode t1(2);
	ListNode t2(8);
	ListNode t3(4);
	ListNode t4(10);
	ListNode t5(6);
	head.next = &t1;
	t1.next = &t2;
	t2.next = &t3;
	t3.next = &t4;
	t4.next = &t5;
 	s.reorderList(&head);
 	ListNode* h = &head;
 	while(h)
 	{
 		cout<<h->val<<endl;
 		h = h->next;
 	}
}

