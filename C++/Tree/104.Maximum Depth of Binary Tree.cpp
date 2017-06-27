/*
求二叉树最大深度。
*/
/*
思路：递归函数参数加一个深度即可。
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
	int maxdepth;
public:
	int maxDepth(TreeNode* root) {
		maxdepth = 0;
        if(root==NULL)	return maxdepth;
        helpLevelOrder(root,1);
        return maxdepth;
    }
    void helpLevelOrder(TreeNode* cur,int level)
    {
    	if(cur!=NULL)
    	{
    		if(level > maxdepth) maxdepth = level;
    		helpLevelOrder(cur->left,level+1);
    		helpLevelOrder(cur->right,level+1);
    	}
    }
};
int main()
{
	Solution s;
	TreeNode t1(1),t2(2),t3(3);
	t1.right = &t2;
	t2.left = &t3;
	cout << s.maxDepth(&t1) <<endl;
}

