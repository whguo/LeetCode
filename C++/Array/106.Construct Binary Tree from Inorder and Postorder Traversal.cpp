/*
给出二叉树的后序和中序遍历，求出二叉树。
中序：左子树，根节点，右子树
后序：左子树，右子树，根节点
*/
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> mypostorder;
	vector<int> myinorder;
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0)	return NULL;
		mypostorder = postorder, myinorder = inorder;
		return buildSubTree(0, postorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* buildSubTree(int postleft,int postright,int inleft,int inright)
    {
    	if(postleft>postright || inleft>inright)	return NULL;
    	TreeNode *root = new TreeNode(mypostorder[postright]);
    	for(int i=0; i <= inright; ++i)
    	{
    		if(myinorder[i]==root->val)
    		{
    			root->left = buildSubTree(postleft,postleft+i-inleft-1,inleft,i-1);
    			root->right = buildSubTree(postright-(inright-i),postright-1,i+1,inright);
    			return root;
    		}
    	}
    	return NULL;
    }
};

void preorder(TreeNode *root)
{
	if (root)
	{
		cout << root->val << endl;
		preorder(root->left);
		preorder(root->right);	
	}
}

int main()
{
	Solution s;
	vector<int> inorder{ 4,2,8,5,1,6,9,3,7 };
	vector<int> postorder{ 4,8,5,2,9,6,7,3,1 };
	TreeNode *tree = s.buildTree(inorder, postorder);
	preorder(tree);
}

