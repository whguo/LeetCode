/*
两个链表代表两个整数，求二者的和链表。
(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
=> 7 -> 8 -> 0 -> 7
不能动链表怎么办？即不能逆序。
*/
/*
思路：用栈把两个链表都存下来，然后求和。
 */

#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		stack<int>	s1,s2;
		while(l1)
		{
			s1.push(l1->val);
			l1 = l1->next;
		}
		while(l2)
		{
			s2.push(l2->val);
			l2 = l2->next;
		}
		int sum = 0;
		ListNode *nhead = new ListNode(0); 
		while(!s1.empty() || !s2.empty())
		{
			if(!s1.empty())	sum += s1.top() , s1.pop();
			if(!s2.empty())	sum += s2.top() , s2.pop();
			nhead->val = sum%10;
			ListNode *tmp = new ListNode(sum/10);
			tmp->next = nhead;
			nhead = tmp;
			sum /= 10;
		}
		return  nhead->val==0 ? nhead->next:nhead;
    }
};
int main()
{
	Solution s;
	ListNode head(7);
	ListNode t1(2);
	ListNode t2(4);
	ListNode t3(3);

	ListNode t4(5);
	ListNode t5(6);
	ListNode t6(4);
	head.next = &t1;
	t1.next = &t2;
	t2.next = &t3;

	t4.next = &t5;
	t5.next = &t6;
 	ListNode* h = s.addTwoNumbers(&head,&t4);
 	while(h)
 	{
 		cout<<h->val<<endl;
 		h = h->next;
 	}
}

