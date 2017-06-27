/*
判断一个二叉树自身是不是镜像的。
*/
/*
思路：分别递归左子树的左子树和右子树的右子树，以及左子树的右子树和右子树的左子树。
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
	bool isSymmetric(TreeNode* root) {
        return root==NULL? true:issymmetric(root->left,root->right);
    }
    bool issymmetric(TreeNode* p,TreeNode* q)
    {
    	if(p==NULL || q==NULL) return p==q;
    	return p->val==q->val && issymmetric(p->left,q->right) && issymmetric(p->right,q->left); 
    }
};
int main()
{
	Solution s;
	TreeNode t1(1),t2(2),t3(3);
	t1.right = &t2;
	t2.left = &t3;
	cout << s.isSymmetric(&t1)<<endl;
}

