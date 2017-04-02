/*
两个链表表示两个整数，返回两个数的和的链表。
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode nHead(0);
        ListNode *cur = &nHead;
        int flag=0,temp;
        while(l1 || l2 || flag!=0)
        {
        	temp = flag;
        	if(l1)	temp += l1->val,l1=l1->next;
        	if(l2)	temp += l2->val,l2=l2->next;
        	flag = temp/10;
        	temp = temp%10;
        	ListNode *tmp = new ListNode(temp);
        	cur->next = tmp;
        	cur=tmp; 
        }
        return nHead.next;
    }
};
int main()
{
	Solution s;
	ListNode head(2);
	ListNode t1(4);
	ListNode t2(3);
	ListNode t3(5);
	ListNode t4(6);
	ListNode t5(4);
	head.next = &t1;
	t1.next = &t2;
	t3.next = &t4;
	t4.next = &t5;
 	ListNode* h = s.addTwoNumbers(&head,&t3);
 	while(h)
 	{
 		cout<<h->val;
 		h = h->next;
 	}
}

