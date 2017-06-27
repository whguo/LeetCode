/*
把有序数组转换为二叉搜索树。
*/
/*
思路：把中间结点拿出来新建根结点，然后把数组下标传入递归函数分别递归左右子树。
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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)	return NULL;
        return createBST(nums,0,nums.size()-1);
    }
    TreeNode* createBST(vector<int>& nums,int left,int right)
    {
    	if(left>right) return NULL;
        if(left==right) return new TreeNode(left);
    	int mid = (left+right)/2;
    	TreeNode* root = new TreeNode(nums[mid]);
    	TreeNode* leftnode = createBST(nums,left,mid-1);
    	TreeNode* rightnode = createBST(nums,mid+1,right);
    	root->left = leftnode, root->right = rightnode;
    	return root;
    }
};
int main()
{
	Solution s;
	vector<int> nums{1,2,3,4,5,6,7,8};
	TreeNode* out = s.sortedArrayToBST(nums);
}

