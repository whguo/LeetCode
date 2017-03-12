/*
中序遍历二叉树。
*/
/*
思路：。
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

	/*递归方法，时间较长。
	public:
	vector<int> result;
	public:
	vector<int> inorderTraversal(TreeNode* root) {
	inorder(root);
	return result;
	}
	void inorder(TreeNode* root)
	{
	if(root)
	{
	inorder(root->left);
	result.push_back(root->val);
	inorder(root->right);
	}
	}*/

public:
	//使用堆栈
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*>	mystack;
		TreeNode *cur = root;
		while (!mystack.empty() || cur)
		{
			if (cur)
			{
				mystack.push(cur);
				cur = cur->left;
			}
			else
			{
				cur = mystack.top();
				result.push_back(cur->val);
				mystack.pop();
				cur = cur->right;
			}
		}
		return result;
	}
};

int main()
{
	Solution s;
	TreeNode root(1);
	TreeNode t2(2);
	TreeNode t3(3);
	root.right = &t2;
	t2.left = &t3;
	vector<int> out;
	out = s.inorderTraversal(&root);
	for (int i = 0; i < out.size(); ++i)
	{
		cout << out[i] << endl;
	}
}

