/*
把二叉树的所有结点挪到右子树，使它成为链表状。
*/
/*
思路：从根结点开始，如果根的左子树不为空，那么把根的右子树放在左子树的最右结点右侧。
	  然后把根的左子树挪到右子树，左子树赋值为空。
	  最后把根结点挪到它的右子树,循环。
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
    void flatten(TreeNode* root) {
        while(root)
        {
        	TreeNode* leftright = root->left;
        	if(leftright)
        	{
        		while(leftright->right)	leftright = leftright->right;
        		leftright->right = root->right;
        		root->right = root->left;
        		root->left = NULL;
        	}
        	root = root->right;
        }
    }
};
int main()
{
	Solution s;
	TreeNode root(1),t1(2),t2(3);
	root.right = &t1;
	t1.left = &t2;
	s.flatten(&root);
}

