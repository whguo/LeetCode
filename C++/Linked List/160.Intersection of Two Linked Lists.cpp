/*
求两个链表的交叉口，如果没有返回null。
要求O(N)时间，O(1)空间。
*/
/*
思路：1.先跑一次，得到二者长度，
        然后长的先走l1-l2步，此时二者距离交叉点长度一样，然后同步向后即可。
      2.不用记录长度，一直循环到二者相等，第一次遍历p1先到结尾后，让p1为另一个链表的头。
        p2到结尾后，p2赋值为链表1的头，此时二者距离相遇点的距离是相同的。
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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

		//思路2
		if(headA==NULL || headB==NULL)	return NULL;
		ListNode *p1=headA,*p2=headB;

		while(p1!=p2)
		{
			p1 = (p1==NULL)? headB : p1->next;
			p2 = (p2==NULL)? headA : p2->next;
		}
		return p1;

		/*思路1
        ListNode *p1=headA,*p2=headB;
        int count1=0,count2=0;
        while(p1)
        {
        	count1++;
        	p1 = p1->next;
        }
        while(p2)
        {
        	count2++;
        	p2 = p2->next;
        }
        p1 = headA,p2 = headB;
        if(count1>count2)
        {
        	for(int i=0; i < count1-count2; ++i)
        		p1 = p1->next;
        }
        else
        {
        	for(int i=0; i < count2-count1; ++i)
        		p2 = p2->next;
        }
        while(p1 && p1!=p2)
        {
        	p1 = p1->next;
        	p2 = p2->next;
        }
        return p1;*/
    }
};
int main()
{
	Solution s;
	ListNode head1(3);
	ListNode head2(1);
	ListNode t1(2);
	ListNode t2(8);
	ListNode t3(4);
	ListNode t4(10);
	ListNode t5(6);
	ListNode t6(5);
	head1.next = &t1;
	t1.next = &t2;
	t2.next = &t3;
	t3.next = &t4;
	t4.next = &t5;
	head2.next = &t6;
	t6.next = &t3;
 	ListNode* h = s.getIntersectionNode(&head1,&head2);	
 	if(h)	cout<<h->val<<endl;
}

