/*
二叉树，找出出现次数最多的子树和。
  5
 /  \
2   -3    返回[2,-3,4]每个子树和都只出现一次。

  5
 /  \
2   -5    返回[2]，因为和为2的子树和出现了两次(2和-5+2+5)。
*/
/*
思路：递归方式用Map存下每个子树的和以及出现次数，记下出现次数最多的数。
然后在遍历一次map，找出所有等于这个次数的数。
 */
#include <iostream>
#include <vector> 
#include <unordered_map>
#include <windows.h>
#include <windef.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	unordered_map<int,int>	mymap;
public:
	vector<int> findFrequentTreeSum(TreeNode* root) {
		int maxcount = 0;
        coutSubTreeSum(root,maxcount);
        vector<int>	result;
        for(auto it=mymap.begin(); it != mymap.end(); ++it)
        {
        	if(it->second==maxcount)	result.push_back(it->first);
        }
        return result;
    }
    int coutSubTreeSum(TreeNode *root,int& maxcount)
    {
    	if(!root)	return 0;
    	int sum = root->val;
    	sum += coutSubTreeSum(root->left,maxcount);
    	sum += coutSubTreeSum(root->right,maxcount);
    	++mymap[sum];
    	maxcount = max(maxcount,mymap[sum]);
    	return sum;
    }
};
int main()
{
	Solution s;
	TreeNode root(5);
	TreeNode t1(2);
	TreeNode t2(-5);
	root.left = &t1;
	root.right = &t2;
	vector<int> out;
 	out = s.findFrequentTreeSum(&root);
 	for(auto i:out)
 		cout<<i<<endl;
}

