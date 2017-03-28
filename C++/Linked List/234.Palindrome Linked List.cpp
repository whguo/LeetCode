/*
判断链表是不是回文的。
O(N)时间，O(1)空间。
*/
/*
思路：找到中间，翻转后一半，然后从头比较。
但是------空间复杂度不仅仅是只额外使用的空间，而要看程序对空间写入了多少次。
所以翻转链表的空间复杂度是O(N)的。
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

	//递归解法，也不是O(1)
	ListNode* temp;
	bool isPalindrome(ListNode* head) {
		temp = head;
        return check(head);
    }
    
    bool check(ListNode* p) {
        if (NULL == p) return true;
        bool isPal = check(p->next) & (temp->val == p->val);
        temp = temp->next;
        return isPal;
    }
		/*翻转后一半
		if(!head || !head->next)	return true;
        ListNode* p1=head,*p2=head->next;
        while(p2 && p2->next)
        {
        	p2 = p2->next->next;
        	p1 = p1->next;
        }
        //reverse后一半
        ListNode *pre = p1->next, *cur = p1->next->next;
        while(cur)
        {
        	pre->next = cur->next;
        	cur->next = p1->next;
        	p1->next = cur;
        	cur = pre->next;
        }
        p2 = p1->next;
        p1 = head;
        while(p2)
        {
        	if(p1->val != p2->val)
        		return false;
        	p1 = p1->next, p2 = p2->next;
        }
        return true;
    }*/

};
int main()
{
	Solution s;
	ListNode head(3);
	ListNode t1(2);
	ListNode t2(8);
	ListNode t3(8);
	ListNode t4(2);
	ListNode t5(3);
	head.next = &t1;
	t1.next = &t2;
	t2.next = &t3;
	t3.next = &t4;
	t4.next = &t5;
 	cout<<s.isPalindrome(&head)<<endl;	
}

