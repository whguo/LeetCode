/*
返回二叉树每一层中最大的数
*/
/*
思路：DFS递归遍历记录每层的最大数。
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
	vector<int>	maxoflevel;
public:
	vector<int> largestValues(TreeNode* root) {
		if(!root)	return maxoflevel;
        helpfind(root,0);
        return maxoflevel;
    }
    void helpfind(TreeNode* root,int level)
    {
    	if(maxoflevel.size() <= level)	maxoflevel.push_back(root->val);
    	else	maxoflevel[level] = max(maxoflevel[level],root->val);
    	if(root->left)	helpfind(root->left,level+1);
    	if(root->right)	helpfind(root->right,level+1);
    }
};
int main()
{
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n4.left = &n3, n4.right = &n5;
	n3.left = &n1, n1.right = &n2;
	n5.right = &n6;
	Solution s;
    vector<int> out = s.largestValues(&n4);
    for(int n:out)
    	cout<<n<<" ";
    cout<<endl;
}

