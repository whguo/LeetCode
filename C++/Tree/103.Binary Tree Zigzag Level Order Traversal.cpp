/*
按照zigzan的方式分层返回二叉树结点的值。
*/
/*
思路：分层返回结点时，奇数层的结点从前面插入。
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)	return result;
        helpLevelOrder(root,0);
        return result;
    }
    void helpLevelOrder(TreeNode* cur,int level)
    {
    	if(cur!=NULL)
    	{
    		if(result.size()<=level)	result.push_back(vector<int> (1,cur->val));
    		else
    		{
    			if(level & 1) result[level].insert(result[level].begin(),cur->val);
    			else 	result[level].push_back(cur->val);
    		}
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
	vector<vector<int>> out = s.zigzagLevelOrder(&t1);
	for(auto vec:out)
	{
		for(auto n:vec)
			cout<<n;
		cout<<endl;
	}
}

