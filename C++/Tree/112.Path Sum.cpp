/*
判断是否存在一条从根到叶的路径，它的结点和等于给出的数。
*/
/*
思路：向下递归，把当前结点的值减掉传入下一层，到达叶结点时判断是否等于传入的值即可。
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
	bool hasPathSum(TreeNode* root, int sum) {
        if(!root)	return false;
        if(!root->left && !root->right)	return root->val==sum; 
        return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val);
    }
};
int main()
{
	Solution s;
	TreeNode root(1),t1(2),t2(3);
	root.right = &t1;
	t1.left = &t2;
	cout << s.hasPathSum(&root,6)<<endl;
}

