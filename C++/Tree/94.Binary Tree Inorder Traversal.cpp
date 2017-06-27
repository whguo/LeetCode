/*
二叉树的中序遍历。
*/
/*
思路：非递归遍历使用栈。
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
    	stack<TreeNode*> mystack;
    	vector<int>	result;
    	TreeNode *cur = root;
    	while(cur || !mystack.empty())
    	{
    		while(cur)
    		{
    			mystack.push(cur);
    			cur = cur->left;
    		}
    		if(!mystack.empty())
    		{
    			TreeNode *tmp = mystack.top();
    			mystack.pop();
    			result.push_back(tmp->val);
    			cur = tmp->right;
    		}
    	}
    	return result;
    }
};
int main()
{
	Solution s;
	TreeNode root(1),t1(2),t2(3);
	root.right = &t1;
	t1.left = &t2;
	vector<int> out = s.inorderTraversal(&root);
	for(int n:out)
		cout<<n<<" ";
	cout<<endl;
}

