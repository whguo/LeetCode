/*
求二叉树所有结点的左右子树值和的绝对差的和。
例如：   1
       /   \
      2     3
     /
    4
结点4，左右子树值和的绝对差为0。结点2，左右子树值和的绝对差为4。
结点3，左右子树值和的绝对差为0。结点1，左右子树值和的绝对差为|6-3|=3。
所以返回结果7。
*/
/*
思路：递归返回左右子树的和，然后在根结点处求绝对差，累加即可。
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
	int findTilt(TreeNode* root) {
        if(!root)	return 0;
        helpTilt(root);
        return result;
    }
    int helpTilt(TreeNode* root)
    {
    	if(!root->left && !root->right)	return root->val;
    	int left = 0, right = 0;
    	if(root->left) left = helpTilt(root->left);
    	if(root->right) right = helpTilt(root->right);
    	result += abs(left-right);
    	return left+right+root->val;
    }
};
int main()
{
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n4.left = &n3, n4.right = &n5;
	n3.left = &n1, n1.right = &n2;
	n5.right = &n6;
	Solution s;
    cout << s.findTilt(&n4)<<endl;
}

