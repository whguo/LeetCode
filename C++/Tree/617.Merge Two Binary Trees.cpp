/*
将两个二叉树合并，如果同一位置结点都存在，那么结点值求和，如果有一个不存在，
那么直接把另一个结点挂上去。
*/
/*
思路：递归做法。
*/
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    	if(!t1)	return t2;
    	if(!t2)	return t1;
    	t1->val += t2->val;
    	t1->left = mergeTrees(t1->left,t2->left);
    	t1->right = mergeTrees(t1->right,t2->right);
        return t1;
    }
};
int main()
{
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n4.left = &n3, n4.right = &n5;
	n3.left = &n1, n1.right = &n2;
	n5.right = &n6;
	Solution s;
    TreeNode* out = s.mergeTrees(&n4,&n4);
}

