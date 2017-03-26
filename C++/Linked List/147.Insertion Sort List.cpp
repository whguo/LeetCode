/*
用插入排序法给链表排序。
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
	ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)	return head;
		ListNode *nhead = new ListNode(0);
		nhead->next = head;
		ListNode *cur = head->next, *insert, *pre = head;
		while (cur)
		{
			insert = nhead;
			while (insert->next->val < cur->val && insert->next != cur)
			{
				insert = insert->next;
			}
			if (insert->next == cur)
			{
				pre = cur;
				cur = cur->next;
			}
			else
			{
				pre->next = cur->next;
				cur->next = insert->next;
				insert->next = cur;
				cur = pre->next;
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
	ListNode t4(10);
	ListNode t5(6);
	head.next = &t1;
	t1.next = &t2;
	t2.next = &t3;
	t3.next = &t4;
	t4.next = &t5;
 	ListNode* h = s.insertionSortList(&head);
 	while(h)
 	{
 		cout<<h->val<<endl;
 		h = h->next;
 	}
}

