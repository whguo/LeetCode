/*
将一个二叉树左右翻转(即返回镜像)。
*/
/*
思路：1.递归方法，根结点处交换左右子树，然后分别递归左右子树为根。
	  2.非递归方法，使用栈。先入栈根结点，然后每次取栈顶，将栈顶的左右子结点入栈，
	  然后交换左右子结点，循环直到栈为空。
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
    TreeNode* invertTree1(TreeNode* root) {
        if(root)
        {
        	TreeNode* tmp = root->left;
        	root->left = root->right;
        	root->right = tmp;
        	invertTree(root->left);
        	invertTree(root->right);
        }
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
    	stack<TreeNode*> mystack;
    	mystack.push(root);
    	while(!mystack.empty())
    	{
    		TreeNode* p = mystack.top();
    		mystack.pop();
    		if(p)
    		{
    			mystack.push(p->left);
    			mystack.push(p->right);
    			std::swap(p->left,p->right);
    		}
    	}
    	return root;
    }
};
int main()
{
	Solution s;
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n4.left = &n3, n4.right = &n5;
	n3.left = &n1, n1.right = &n2;
	n5.right = &n6;
	TreeNode* out = s.invertTree(&n4);
}

