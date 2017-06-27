/*
给出两个二叉树，判断其中一个的子树是不是与另外一个结构值完全相同。
*/
/*
思路：非递归先序遍历找到s中与t的根结点值相同的结点，然后递归判断是否结构和值完全相同。
*/
#include <iostream>
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
	bool isSubtree(TreeNode* s, TreeNode* t) {
        stack<TreeNode*> mystack;
        while(s || !mystack.empty())
        {
        	while(s)
        	{
        		mystack.push(s);
        		if(s->val == t->val && isSame(s,t))	return true;
        		s = s->left;	
        	}
        	if(!mystack.empty())
        	{
        		s = mystack.top();
        		mystack.pop();
        		s = s->right;
        	}
        }
        return false;
    }
    bool isSame(TreeNode* s, TreeNode* t)
    {
    	if(!s && !t)	return true;
    	if(!s ^ !t)	return false;
    	return s->val==t->val && isSame(s->left,t->left) && isSame(s->right,t->right);
    }
};
int main()
{
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n4.left = &n3, n4.right = &n5;
	n3.left = &n1, n1.right = &n2;
	n5.right = &n6;
	Solution s;
    cout << s.isSubtree(&n4,&n4)<<endl;
}

