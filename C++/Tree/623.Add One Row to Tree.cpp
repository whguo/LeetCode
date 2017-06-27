/*
给出二叉树和数v，深度d，在二叉树的深度d处加一行。
*/
/*
思路：DFS递归，记录深度，到达要插入的上一层时，建立结点。
*/
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
    	if(!root) return NULL;
    	if(d==1)
    	{
    		TreeNode* newroot = new TreeNode(v);
    		newroot->left = root;
    		return newroot;
    	}	
        helpAddRow(root,v,d-1);
        return root;
    }
    void helpAddRow(TreeNode* root, int v, int d)
    {
    	if(!root)   return;
    	if(d==1)
    	{
    		TreeNode *newleft = new TreeNode(v),*newright = new TreeNode(v);
    		newleft->left = root->left,root->left = newleft;
    		newright->right = root->right,root->right = newright;
    	}
    	else
    	{
    		helpAddRow(root->left,v,d-1);
    		helpAddRow(root->right,v,d-1);
    	}
    }
};
int main()
{
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n4.left = &n3, n4.right = &n5;
	n3.left = &n1, n1.right = &n2;
	n5.right = &n6;
	Solution s;
    TreeNode* out = s.addOneRow(&n4,2,3);
}

