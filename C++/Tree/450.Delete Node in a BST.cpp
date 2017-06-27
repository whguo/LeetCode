/*
删除二叉搜索树中的给定结点，使其仍为二叉搜索树。
*/
/*
思路：1.先根据二叉搜索树的排序特点找到要删除的结点以及它的父结点。
		如果该结点左子树为空，那么右子树直接替代，如果右子树为空，用左子树替代。
		如果都不为空，那么把右子树挂在左子树的最右侧。然后用左子树替代原结点。
		如果要删除的结点为根结点，那么返回相应替代结点。
	  2.递归写法。
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
	TreeNode* deleteNode1(TreeNode* root, int key) {
        TreeNode* parent = root,*cur = root;
        while(cur && cur->val != key)
        {
        	parent = cur;
        	if(cur->val > key)	cur = cur->left;
        	else cur = cur->right;
        }
        if (!cur)	return root;
        TreeNode* replace;
        if(!cur->left)	replace = cur->right;
        else if(!cur->right)	replace = cur->left;
        else
        {
        	replace = cur->left;
        	TreeNode* tmp = cur->left;
        	while(tmp->right)	tmp = tmp->right;
        	tmp->right = cur->right;
        }
        if(cur->val > cur->val)	parent->left = replace;
        else parent->right = replace;
        	
        if(parent!=root)	return root;
        else return replace;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
    	if(!root)	return NULL;
    	if(key < root->val)		root->left = deleteNode(root->left,key);
    	else if(key > root->val)	root->right = deleteNode(root->right,key);
    	else
    	{
    		if(!root->left)	return root->right;
    		else if(!root->right)	return root->left;
    		TreeNode *minNode = root->right;
    		while(minNode->left)	minNode = minNode->left;
    		root->val = minNode->val;
    		root->right = deleteNode(root->right,root->val);
    	}
    	return root;
    }
};
int main()
{
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n4.left = &n3, n4.right = &n5;
	n3.left = &n1, n1.right = &n2;
	n5.right = &n6;
	Solution s;
    TreeNode* out1 = s.deleteNode(&n4,5);
    TreeNode* out2 = s.deleteNode(&n4,4);
    TreeNode* out3 = s.deleteNode(&n4,2);
}

