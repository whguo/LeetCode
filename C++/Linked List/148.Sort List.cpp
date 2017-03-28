/*
给链表排序，要求平均O(N*logN)。
*/
/*
归并排序：长度小于2，直接返回。长度等于2，判断一下大小是否需要调转。
长度大于2，均分两部分，然后递归调用，最后把两部分并起来。
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
	ListNode* sortList(ListNode* head) {
        if(!head || !head->next)	return head;
        if(!head->next->next)
        {
        	if(head->val > head->next->val)
        	{
        		ListNode* tmp = head->next;
        		tmp->next = head;
        		head->next = NULL;
        		return tmp;
        	}
        	return head;
        }
        else
        {
        	ListNode *p1 = head->next,*p2=head->next->next,*tmp,*nhead;
        	while(p2 && p2->next)
        	{
        		p1 = p1->next;
        		p2 = p2->next->next;
        	}
        	p2 = p1->next;
        	p1->next = NULL;
        	p1 = sortList(head);
        	p2 = sortList(p2);
        	nhead = new ListNode(0);
        	tmp = nhead;
        	while(p1 && p2)
        	{
        		if(p1->val < p2->val)
        		{
        			tmp = tmp->next = p1;
        			p1 = p1->next;
        		}
        		else
        		{
        			tmp = tmp->next = p2;
        			p2 = p2->next;
        		}
        	}
        	tmp->next = (p1)? p1 : p2;
        	return nhead->next;
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
 	ListNode* h = s.sortList(&head);	
 	while(h)
 	{
 		cout<<h->val<<endl;
 		h = h->next;
 	}
}

