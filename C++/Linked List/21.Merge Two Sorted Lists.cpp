/*
合并两个有序链表。
*/
/*
思路：不要新建结点，每次把小的结点链在新链表里即可。
直到某一个链表为空，然后把另一个直接全都放在结尾。
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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode nHead(0);
        ListNode* cur = &nHead;
        while(l1 && l2)
        {
        	if(l1->val < l2->val)
        	{
        		cur->next = l1;
        		l1 = l1->next;
        	}
        	else
        	{
        		cur->next = l2;
        		l2 = l2->next;
        	}
        	cur = cur->next;	
        }
        cur->next = l1? l1:l2;
        return nHead.next;
    }
};
int main()
{
	Solution s;
	ListNode head(2);
	ListNode t1(5);
	ListNode t2(10);
	ListNode t3(3);
	ListNode t4(6);
	ListNode t5(13);
	head.next = &t1;
	t1.next = &t2;
	t3.next = &t4;
	t4.next = &t5;
 	ListNode* h = s.mergeTwoLists(&head,&t3);
 	while(h)
 	{
 		cout<<h->val<<endl;
 		h = h->next;
 	}
}

