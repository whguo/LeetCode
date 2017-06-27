/*
求二叉树所有从根到叶结点的路径。
*/
/*
思路：递归将路径上的每个点加入即可，到根结点时将整个路径加入result数组。
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
	vector<string> result;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)	return result;
        helpBinaryTreePaths(root,to_string(root->val));
        return result;
    }
    void helpBinaryTreePaths(TreeNode* root,string prepath)
    {
    	if(!root->left && !root->right)	
    	{
    		result.push_back(prepath);
    		return ;
    	} 
    	if(root->left) helpBinaryTreePaths(root->left,prepath+"->"+to_string(root->left->val));
        if(root->right) helpBinaryTreePaths(root->right,prepath+"->"+to_string(root->right->val));
    }
};
int main()
{
	Solution s;
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n4.left = &n3, n4.right = &n5;
	n3.left = &n1, n1.right = &n2;
	n5.right = &n6;
	vector<string> out = s.binaryTreePaths(&n4);
	for(string s:out)
		cout<<s<<endl;
}

