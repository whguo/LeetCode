/*
求二叉搜索树中，两个结点的最低公共祖先结点。
*/
/*
思路：找出p、q中大的那个，从根结点开始，如果结点值大于大的那个，那么向左走，
	  如果结点值小于小的那个，那么向右走。如果在二者中间，跳出循环，返回该结点。
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
        if(p->val > q->val)		std::swap(p,q);   //保证p<q
        TreeNode *cur = root;
        while(1)
        {
        	if(cur->val>q->val)	cur = cur->left;
        	else if(cur->val<p->val)	cur = cur->right;
        	else break;
        }
        return cur;
    }
};
int main()
{
	Solution s;
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n4.left = &n3, n4.right = &n5;
	n3.left = &n1, n1.right = &n2;
	n5.right = &n6;
	TreeNode* out = s.lowestCommonAncestor(&n4,&n1,&n3);
	cout<<out->val<<endl;
}

