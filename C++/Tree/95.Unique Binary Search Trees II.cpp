/*
给出正整数n，返回所有可能的二叉搜索树。
例如：给出3，返回以下5种。
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
/*
思路：
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
	vector<TreeNode*> generateTrees(int n) {
        return (n==0)? vector<TreeNode*> (NULL):generatetrees(1,n);
    }
    vector<TreeNode*> generatetrees(int left,int right)
    {
    	vector<TreeNode*> result;
    	if(left>right)
    	    result.push_back(NULL);
    	else if(left==right)
    	    result.push_back(new TreeNode(left));
    	else
    		for(int i=left; i <= right; ++i)
    		{
    			vector<TreeNode*> lefttree = generatetrees(left,i-1);
    			vector<TreeNode*> righttree = generatetrees(i+1,right);
    			for(auto lt:lefttree)
    			{
    				for(auto rt:righttree)
    				{
    					TreeNode* node = new TreeNode(i);
    					node->left = lt;
    					node->right = rt;
    					result.push_back(node);
    				}
    			}
    		}
    	return result;
    }
};
int main()
{
	Solution s;
	vector<TreeNode*> out =  s.generateTrees(3);
}

