/*
二叉树每个结点只包含数字0--9，每个从根到叶的路径代表一个整数。
返回所有路径代表整数的和。
*/
/*
思路：递归，上层结点乘10加到当前结点，一直往下传，直到根结点，加到sum里。
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
private:
	int sum;
public:
    int sumNumbers(TreeNode* root) {
    	if(!root)	return 0;
    	sum = 0;
    	helpSumNumber(root,0);
        return sum;
    }
    void helpSumNumber(TreeNode* root,int presum)
    {
    	if(!root->left && !root->right)	sum += (presum+root->val);
    	if(root->left)	helpSumNumber(root->left,10*(root->val+presum));
    	if(root->right)	helpSumNumber(root->right,10*(root->val+presum));
    }
};
int main()
{
	Solution s;
	TreeNode root(1),t1(2),t2(3);
	root.right = &t1;
	t1.left = &t2;
	cout << s.sumNumbers(&root) << endl;
}

