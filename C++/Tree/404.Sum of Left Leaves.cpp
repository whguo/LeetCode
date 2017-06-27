/*
返回所有左侧叶结点的和。
    3
   / \
  9  20
    /  \
   15   7    左侧叶结点为9和15，返回24。
*/
/*
思路：1.非递归做法，使用中序(或前序)非递归遍历的做法，利用栈，在压栈时同时压入一个数，
	  记录是否是该侧子树的第一个(例如3,9是一条线，20,15是一条线，7是一条线，
	  第一个分别是3,20,7)。
	  出栈时，判断结点的左右如果为空，而且不是该侧子树的第一个，那么累加和。
	  2.递归做法，如果根的左侧为叶结点，那么返回左侧结点值加上右子树的递归。
*/
#include <iostream>
#include <vector>
#include <utility>
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
	int sumOfLeftLeaves(TreeNode* root) {
        stack<pair<TreeNode*,int>> mystack;
        int result = 0;
        while(root || !mystack.empty())
        {
        	int tmp = 0;
        	while(root)
        	{
        		mystack.push(make_pair(root,tmp++));
        		root = root->left;
        	}
        	if(!mystack.empty())
        	{
        		auto t = mystack.top();
        		if(!t.first->left && !t.first->right && t.second>0)	result += t.first->val;
        		mystack.pop();
        		root = t.first->right;
        	}
        }
        return result;
    }

    int sumOfLeftLeaves1(TreeNode* root) {
        if (!root) return 0;
        if (root->left && !root->left->left && !root->left->right) 
        	return root->left->val + sumOfLeftLeaves(root->right);
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
int main()
{
	Solution s;
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n4.left = &n3, n4.right = &n5;
	n3.left = &n1, n1.right = &n2;
	n5.right = &n6;
	cout << s.sumOfLeftLeaves(&n4) << endl;
}

