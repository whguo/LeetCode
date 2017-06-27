/*
求二叉树的直径，即任意两个结点间的最长路径。
*/
/*
思路：递归左右子树的最大深度，左右深度求和之后与当前最大深度比较。
	  不能返回根结点的左右子树深度和，因为直径不一定经过根结点。
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
private:
	int result = 0;
public:
	int diameterOfBinaryTree(TreeNode* root) {
        if(!root)   return 0;
        helpDiameter(root);
        return result;
    }
    int helpDiameter(TreeNode* root)
    {
        if(!root)   return 0;
        int left = 0,right = 0;
        if(root->left)  left = helpDiameter(root->left);
        if(root->right) right = helpDiameter(root->right);
        result = max(left+right,result);
        return max(left,right)+1;
    }
};
int main()
{
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n4.left = &n3, n4.right = &n5;
	n3.left = &n1, n1.right = &n2;
	n5.right = &n6;
	Solution s;
    cout << s.diameterOfBinaryTree(&n4)<<endl;
}

