/*
求二叉树最小深度，也就是从根到叶的最短路径长度。
*/
/*
思路：递归解法。左子树为空，递归右侧。右子树为空，递归左侧。否则两侧都递归取最小的。
*/
#include <iostream>
#include <windows.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int minDepth(TreeNode* root) {
        if(!root)	return 0;
        if(!root->left) return minDepth(root->right)+1;
        if(!root->right) return minDepth(root->left)+1;
        return min(minDepth(root->left),minDepth(root->right))+1;
    }
};
int main()
{
	Solution s;
	TreeNode root(1),t1(2),t2(3);
	root.right = &t1;
	t1.left = &t2;
	cout << s.minDepth(&root)<<endl;
}

