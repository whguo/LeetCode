/*
给出一个二叉树，判断是否为平衡二叉树（左右子树高度差小于等于1）。
*/
/*
思路：后序遍历二叉树，在遍历根结点的时候，左右子树的深度是已知的，所以可以判断是否平衡。
由于递归函数的返回值要用bool值返回该结点是否平衡，所以深度应该使用指针类型的函数参数返回。
*/
#include <iostream>
#include <windows.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	bool isBalanced(TreeNode* root) {
        if(!root)	return true;
        int depth = 0;
        return helpBalanced(root,&depth);
    }
    bool helpBalanced(TreeNode* root,int* depth)
    {
    	if(!root)	return true;
    	int leftdep = (*depth)+1, rightdep = (*depth)+1;
    	bool isLeftBalanced = helpBalanced(root->left,&leftdep);
    	bool isRightBalanced = helpBalanced(root->right,&rightdep);
    	*depth = max(leftdep,rightdep);
    	return isLeftBalanced && isRightBalanced && leftdep-rightdep<=1 && leftdep-rightdep>=-1;
    }
};
int main()
{
	Solution s;
	TreeNode root(1),t1(2),t2(3);
	root.right = &t1;
	t1.left = &t2;
	cout << s.isBalanced(&root)<<endl;
}

