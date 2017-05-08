/*
删除链表中的倒数第n个结点。
*/
/*
思路：用Map存下每个节点位置和指针，耗费空间。
两个指针，让快指针先走n步，然后两者再一起走，直到快的到末尾，那么慢的到第len-n的位置。
 */

#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		/*map存的方法
        unordered_map<int,ListNode*>	mymap;
        ListNode nHead(0);
        nHead.next = head;
        int count = 1;
        mymap[0] = &nHead;
        while(head)
        {
        	mymap[count++] = head;
        	head = head->next;
        }
        ListNode *pre = mymap[count-n-1];
        ListNode *tmp = pre->next;
        pre->next = tmp->next;
        delete tmp;
        return nHead.next;*/
        ListNode nHead(0);
        nHead.next = head;
        ListNode *fast = head, *slow = &nHead;
        for(int i=1; i <= n; ++i)
        	fast = fast->next;
        while(fast)
        {
        	fast = fast->next;
        	slow = slow->next;
        }
        slow->next = slow->next->next;
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
	t2.next = &t3;
	t3.next = &t4;
	t4.next = &t5;
 	ListNode* h = s.removeNthFromEnd(&head,3);
 	while(h)
 	{
 		cout<<h->val;
 		h = h->next;
 	}
}

