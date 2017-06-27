/*
二叉搜索树中含有重复元素，左子树小于或等于根，右子树大于或等于根。
返回搜索树中重复次数最多的元素，有多个的话顺序任意。
尽量使用O(1)空间。
*/
/*
思路：1.使用栈进行非递归中序遍历，然后使用map记录每个数出现的次数，最后找出次数最多的。
        但是这种方法不是O(1)空间。
      2.遍历两次，第一次找出出现最多的次数，第二次找出所有出现次数是最多的数加到结果数组中。
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
	int curval,curcount=0,maxcount=0,modecount=0;
	vector<int> result;
public:
	vector<int> findMode(TreeNode* root) {
        inorder(root);
        //第一次遍历result一直为空。
        result.resize(modecount);
        modecount = 0, curcount = 0;
        inorder(root);
        return result;
    }
    void inorder(TreeNode* root)
    {
    	if(root)
    	{
    		inorder(root->left);
    		handleValue(root->val);
    		inorder(root->right);
    	}
    }
    void handleValue(int val)
    {
    	if(val != curval)
    	{
    		curval = val;
    		curcount = 0;
    	}
    	++curcount;
    	if(curcount > maxcount)
    	{
    		maxcount = curcount;
    		modecount = 1;
    	}
    	else if(curcount == maxcount)
    	{
    		if(result.size()!=0)	result[modecount] = curval;
    		++modecount;
    	}
    }
};
int main()
{
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(3),n6(6);
	n4.left = &n3, n3.right = &n5;
//	n3.left = &n1, n1.right = &n2;
//	n5.right = &n6;
	Solution s;
    vector<int> out = s.findMode(&n4);
    for(int n:out)
    	cout<<n<<endl;
}

