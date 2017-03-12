/*
一个链表，每个节点包含一个随机指针，可能指向任何一个节点或者是空。
返回该链表的深拷贝。
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		unordered_map<RandomListNode*,RandomListNode*> mymap;
        RandomListNode nhead(0);
        RandomListNode *cur = &nhead,*temp,*h=head;
        while(h)
        {
        	temp = new RandomListNode(h->label);
        	mymap.insert({h,temp});
        	cur->next = temp;
        	cur = temp;
        	h = h->next;
        }
        cur = nhead.next;
        while(head)
        {
        	cur->random = mymap[head->random];
        	cur = cur->next;
        	head = head->next;
        }
        return nhead.next;
    }
};

int main()
{
	Solution s;
	RandomListNode head(1);
	RandomListNode h2(2);
	RandomListNode h3(3);
	head.next = &h2;
	h2.next = &h3;
	RandomListNode *out = s.copyRandomList(&head);
	while(out)
	{
		cout<<out->label<<endl;
		out = out->next;
	}
}

