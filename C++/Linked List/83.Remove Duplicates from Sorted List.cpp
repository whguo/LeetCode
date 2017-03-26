/*
删除有序链表中数字重复的结点。
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
		ListNode *cur=head;
        while(cur->next)
        {
        	if(cur->val == cur->next->val)
        		cur->next = cur->next->next;
        	else cur = cur->next;
        }
        return head;

        /*递归写法
        if(head == NULL || head->next == NULL)return head;
        head->next = deleteDuplicates(head->next);
        return head->val == head->next->val ? head->next : head;
         */
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

