/*
判断链表中是否有环，不使用额外空间。
*/
/*
用快慢指针，slow==fast位置为P，环的起点为S。
head到S长为a，S到P长度b，P到S长度c。那么有2*(a+b)=a+b+c+b。
可知a==c。
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
	ListNode *detectCycle(ListNode *head){
        if(!head || !head->next)   return NULL;
        ListNode *fast=head->next->next,*slow=head->next;
        while(fast && fast->next)
        {
        	fast = fast->next->next;
        	slow = slow->next;
        	if(slow==fast)
        	{
        		ListNode *h = head;
        		while(h!=slow)	h=h->next,slow=slow->next;
        		return slow;
        	}
        }
        return NULL;
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
	t5.next = &t1;
 	ListNode* h = s.detectCycle(&head);
 	cout<<h->val<<endl;
}

