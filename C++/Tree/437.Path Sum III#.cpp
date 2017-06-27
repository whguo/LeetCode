/*
找出二叉树中有几条的路径，路径上结点的和等于给定值。
路径不一定要从根开始，在叶结束，只需要是从上到下的即可。
*/
/*
思路：1.递归解法。对于根结点root，路径分为有root和没有root的路径。
	  所以root这棵树的路径数为，和为sum-root->val的路径数，加上root->left和root->right中
	  和为sum的路径数。
	  2.思路1存在较多的重复计算，所以考虑使用哈希表把根到当前结点的和cursum记录下来。
	  如果cursum-target在哈希表中，那么说明根到当前结点一定有子路径的和为target。
	  cursum-target出现了几次，就有几条子路径。
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
public:
	//哈希方法
	unordered_map<int,int> mymap;
	int pathSum(TreeNode* root, int sum) {
		mymap[0] = 1;
		return helpPathSum(root,0,sum);
	}

	int helpPathSum(TreeNode *root,int cursum,int target)
	{
		if(!root)	return 0;
		cursum += root->val;
		int result = (mymap.find(cursum-target)!=mymap.end())? mymap[cursum-target]:0;
		if(mymap.find(cursum)==mymap.end()) mymap[cursum] = 1;
		else ++mymap[cursum];
		
		result += helpPathSum(root->left,cursum,target);
		result += helpPathSum(root->right,cursum,target);
		--mymap[cursum];
		return result;
	}

	//递归解法
	int pathSum1(TreeNode* root, int sum) {
        if(!root) return 0;
        return sumUp(root, 0, sum) + pathSum1(root->left, sum) + pathSum1(root->right, sum);
    }
private:
    int sumUp(TreeNode* root, int pre, int& sum){
        if(!root) return 0;
        int current = pre + root->val;
        return (current == sum) + sumUp(root->left, current, sum) + sumUp(root->right, current, sum);
    }
};
int main()
{
	Solution s;
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n4.left = &n3, n4.right = &n5;
	n3.left = &n1, n1.right = &n2;
	n5.right = &n6;
	cout << s.pathSum(&n4,10) << endl;
}

