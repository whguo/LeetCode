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
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
private:
	unordered_map<int,int>	mymap;
public:
	vector<int> findFrequentTreeSum(TreeNode* root) {
		int maxcount = 0;
		helpFind(root,maxcount);
        vector<int>	result;
        for(auto it:mymap)
        {
        	if(it.second == maxcount)	result.push_back(it.first);
        }
        return result;
    }
    int helpFind(TreeNode* root,int& maxcount)
    {
    	if(!root)	return 0;
    	int sum = root->val;
    	sum += helpFind(root->left,maxcount);
    	sum += helpFind(root->right,maxcount);
    	++mymap[sum];
    	maxcount = max(maxcount,mymap[sum]);
    	return sum;
    }
};
int main()
{
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n4.left = &n3, n4.right = &n5;
	n3.left = &n1, n1.right = &n2;
	n5.right = &n6;
	Solution s;
    vector<int> out = s.findFrequentTreeSum(&n4);
    for(int n:out)
    	cout<<n<<" ";
    cout<<endl;
}

