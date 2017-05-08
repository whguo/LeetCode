/*
判断链表中是否有环，不使用额外空间。
*/
/*
用快慢指针，如果二者可以相等，那么有环。
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
	bool hasCycle(ListNode *head) {
        if(!head || !head->next)   return false;
        ListNode *fast=head->next->next,*slow=head->next;
        while(fast && fast->next)
        {
        	fast = fast->next->next;
        	slow = slow->next;
        	if(slow==fast)	return true;
        }

        return false;
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
 	cout<< s.hasCycle(&head);
}

