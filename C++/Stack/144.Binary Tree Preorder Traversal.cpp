/*
前序遍历二叉树。
*/
/*
思路：使用栈，在压栈前将当前结点遍历。
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
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        stack<TreeNode*> mystack;
        while(root || !mystack.empty())
        {
        	while(root)
        	{
        		preorder.push_back(root->val);
        		mystack.push(root);
        		root = root->left;
        	}
        	if(!mystack.empty())
        	{
        		root = mystack.top()->right;
        		mystack.pop();
        	}
        }
        return preorder;
    }
};
int main()
{
	Solution s;
	TreeNode root(1),t1(2),t2(3);
	root.right = &t1;
	t1.left = &t2;
	vector<int> out = s.preorderTraversal(&root);
	for(int n:out)
		cout<<n<<" ";
	cout<<endl;
}

