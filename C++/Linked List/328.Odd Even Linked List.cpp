/*
把链表重新排序，奇数节点放在一起，偶数节点放在奇数后边，(链表号奇偶数，不是链表中的数)
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
	ListNode* oddEvenList(ListNode* head) {
		if(!head || !head->next)	return head;
        ListNode *odd=head,*ev=new ListNode(0),*cur=head->next,*even;
        even = ev;
        while(cur)
        {
        	even = even->next = cur;
        	cur = cur->next;
        	if(!cur)	break;
        	odd = odd->next = cur;
        	cur = cur->next;
        }
        even->next = NULL;
        odd->next = ev->next;
        return head;
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
 	ListNode* h = s.oddEvenList(&head);
 	while(h)
 	{
 		cout<<h->val<<endl;
 		h = h->next;
 	}
}

