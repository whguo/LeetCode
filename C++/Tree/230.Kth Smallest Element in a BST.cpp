/*
返回二叉搜索树中第k小的数。
*/
/*
思路：二叉搜索树中序遍历是有序的。
使用中序非递归遍历找到第k个即可。
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
	int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> mystack;
        TreeNode* p = root;
        int count = 0;
        while(p || !mystack.empty())
        {
        	while(p)
        	{
        		mystack.push(p);
        		p = p->left;
        	}
        	if(!mystack.empty())
        	{
        		p = mystack.top();
        		++count;
        		if(count == k)	return p->val;
        		mystack.pop();
        		p = p->right;
        	}
        }
        return -1;
    }
};

int main()
{
	Solution s;
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n4.left = &n3, n4.right = &n5;
	n3.left = &n1, n1.right = &n2;
	n5.right = &n6;
	cout<<s.countNodes(&n4)<<endl;
}

