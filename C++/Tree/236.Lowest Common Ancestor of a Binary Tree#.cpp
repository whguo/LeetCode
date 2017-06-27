/*
求任意二叉树中，两个结点的最低公共祖先结点。
*/
/*
思路：递归方法，当根结点为空，或者是pq二者之一，那么返回根结点。
	  否则，递归左右子树，如果左右子树都不为空，那么说明在左右子树分别找到p和q，返回当前根结点。
	  如果只有左子树为空，返回右子树。右子树为空，返回左子树。
	  情况有两种，一种就是最小共同祖先是qp二者之一，一种不是。
	  如果是情况一，那么递归进行到最小祖先处，判断出当前结点为二者之一，返回当前结点。
	  不往下进行。那么一直返回到最外层递归，得出结果为刚才返回的结点。
	  如果是情况二，递归分别进行至pq处，然后向上返回，直到共同最小祖先处，左右子树返回均不为空，
	  向上返回该结点。
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        return !left ? right : !right ? left : root;
    }
};
int main()
{
	Solution s;
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n4.left = &n3, n4.right = &n5;
	n3.left = &n1, n1.right = &n2;
	n5.right = &n6;
	TreeNode* out = s.lowestCommonAncestor(&n4,&n1,&n6);
	cout<<out->val<<endl;
}

