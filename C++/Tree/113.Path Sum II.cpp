/*
找出从根到叶的所有路径，结点和等于给出的数。
*/
/*
思路：向下递归，把当前结点的值减掉传入下一层，记录中间路径结果，
	  到达叶结点时判断是否等于传入的值即可。
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
	vector<vector<int>> result;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root)	return result;
        vector<int> tmp;
        helpPathSum(root,sum,tmp);
        return result;
    }
	void helpPathSum(TreeNode* root, int sum,vector<int>& tmp)
	{
		//if(root->val > sum)	return;  //不能提前终止，因为结点值有负的。
		tmp.push_back(root->val);
		if(!root->left && !root->right && root->val==sum)
			result.push_back(tmp);
		if(root->left)	helpPathSum(root->left,sum-root->val,tmp);
		if(root->right) helpPathSum(root->right,sum-root->val,tmp);
		tmp.pop_back();
	}
};
int main()
{
	Solution s;
	TreeNode root(1),t1(2),t2(3);
	root.right = &t1;
	t1.left = &t2;
	vector<vector<int>> out = s.pathSum(&root,6);
}

