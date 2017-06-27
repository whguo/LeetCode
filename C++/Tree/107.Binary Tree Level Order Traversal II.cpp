/*
从下到上，分层返回二叉树结点。
*/
/*
思路：每当有新的一层时，在结果数组中头部插入。然后在每层插入新的数时，下标为result.size()-level。
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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL)	return result;
        helpLevelOrder(root,1);
        return result;
    }
    void helpLevelOrder(TreeNode* cur,int level)
    {
    	if(cur!=NULL)
    	{
    		if(result.size()<level)	result.emplace(result.begin(),vector<int> (1,cur->val));
    		else result[result.size()-level].push_back(cur->val);
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
	vector<vector<int>> out = s.levelOrderBottom(&t1);
	for(auto vec:out)
	{
		for(auto n:vec)
			cout<<n;
		cout<<endl;
	}
}

