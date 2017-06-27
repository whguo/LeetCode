/*
给出二叉树的前序和中序遍历，求出二叉树。
前序：根节点，左子树，右子树
中序：左子树，根节点，右子树
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
	vector<int> mypreorder;
	vector<int> myinorder;
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0)	return NULL;
		mypreorder = preorder, myinorder = inorder;
		return buildSubTree(0, preorder.size() - 1, 0, inorder.size() - 1);
	}
	TreeNode* buildSubTree(int preleft, int preright,int inleft, int inright )
	{
		if (preleft>preright)	return NULL;
		TreeNode *root = new TreeNode(mypreorder[preleft]);
		for (int i = inleft; i <= inright; ++i)
		{
			if (myinorder[i] == root->val)
			{
				root->left = buildSubTree(preleft + 1, preleft+i-inleft, inleft, i - 1);
				root->right = buildSubTree(preright-(inright-i-1), preright, i + 1, inright);
				return root;
			}
		}
		return NULL;
	}
};

void postorder(TreeNode *root)
{
	if (root)
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->val << endl;
	}
}

int main()
{
	Solution s;
	vector<int> preorder{ 1,2,3 };
	vector<int> inorder{ 2,3,1 };
	TreeNode *tree = s.buildTree(preorder, inorder);
	postorder(tree);
}

