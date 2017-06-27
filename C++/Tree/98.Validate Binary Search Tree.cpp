/*
判断一棵树是否是二叉搜索树。
*/
/*
思路：中序遍历二叉树，依次比较前一个数是否比当前数小。
	  使用一个数last记录上一个结点的数，由于可能出现结点中的数是INT_MIN的情况，
	  所以又使用一个isfirst标识是否为第一个数。
	  不节省空间的话，该部分可以用vector直接代替。
 */
#include <iostream>
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
	bool isValidBST(TreeNode* root) {
        stack<TreeNode*> mystack;
    	TreeNode *cur = root;
    	int isfirst = 1, last = 0;
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
    			if(isfirst==0 && tmp->val<=last) 	return false;
    			else isfirst = 0,last = tmp->val;
    			cur = tmp->right;
    		}
    	}
    	return true;
    }
};
int main()
{
	Solution s;
	TreeNode root(1),t1(2),t2(3);
	root.right = &t1;
	t1.left = &t2;
	cout << s.isValidBST(&root)<<endl;
}

