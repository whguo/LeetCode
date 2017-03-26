/*
把有序链表转换为平衡二叉搜索树。
*/
/*
用快慢指针，找到中间，建立结点，递归左右。
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (!head)	return NULL;
		if (!head->next)
		{
			TreeNode *root = new TreeNode(head->val);
			return root;
		}
		ListNode *fast = head->next->next,*preslow = head;
		while (fast && fast->next)
		{
			preslow = preslow->next;
			fast = fast->next->next;
		}
		TreeNode *root = new TreeNode(preslow->next->val);
		root->right = sortedListToBST(slow->next->next);
		preslow->next = NULL;
		root->left = sortedListToBST(head);
		return root;
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
 	TreeNode* h = s.sortedListToBST(&head);
}

