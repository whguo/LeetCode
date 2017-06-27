/*
二叉树构成的街道，结点为房子，如果抢劫直接相连的两个结点，那么会触发警报。
问不触发警报情况下能抢到的最多的钱。
*/
/*
思路：1.递归的方法，假设rob(root)表示根结点这棵树能得到的最多的钱，
      那么如何用rob(root->left),rob(root->right)...等等得到计算出rob(root)。
      首先，递归终止条件，一棵树为空时，返回0。
      然后，对于某棵树，根结点两种情况。如果根结点没有被抢，那么最大值为左右子树可抢的和，
      也就是rob(root->left)+rob(root->right)。
      如果根结点被抢了，那么它的左右子结点都不能抢，只能抢它的4个孙子结点。
      也就是这种情况下，最大值为root->val + rob(root->left->left) + rob(root->left->right)
                                + (rob(root->right->left) + rob(root->right->right))
      那么根结点能抢的最大值就是这两种情况的较大值。
	  但是这种思路有太多的重复计算，速度太慢1000多ms。
	  比如，计算根的最大值时要计算rob(root->left->left)和rob(root->left->right)，而计算
	  rob(root->left)又要计算一次。
      2.由于思路1的太多重复计算，想到动态规划，把子问题的计算结果保存下来，供后续使用。
      3.由1导出2的动态规划中，发现仍然有重复计算的子问题。这源于问题的定义rob(root)表示从
      root抢到的最多的钱，但是并没有区分root结点是否被抢，所有有信息损失，随着问题递归的深入，
      就会导致重复的计算。
      重新定义rob(root)，返回一个有两个值的数组res，res[0]代表root结点没有被抢能得到的最大值。
      res[1]表示root结点被抢的情况能得到的最大值。
	  如果rob(root->left)和rob(root->right)的返回值为left和right，
	  那么res[0]的值为max(left[0],left[1]) + max(right[0],right[1])。
	  res[1]的值为root->val + left[0] + right[0]。
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
	//方法1
    int rob1(TreeNode* root) {
        if(!root)	return 0;
        int val = 0;
        if(root->left)
        	val += (rob1(root->left->left) + rob1(root->left->right));
        if(root->right)
        	val += (rob1(root->right->left) + rob1(root->right->right));
        return max(val+root->val,rob1(root->left)+rob1(root->right));
    }

    //方法2
public:
	unordered_map<TreeNode*,int>  mymap;
    int rob2(TreeNode* root) {
    	if(!root)	return 0;
    	if(mymap.find(root)!=mymap.end())	return mymap[root];
    	int val = 0;
        if(root->left)
        	val += (rob2(root->left->left) + rob2(root->left->right));
        if(root->right)
        	val += (rob2(root->right->left) + rob2(root->right->right));
        val = max(val+root->val,rob2(root->left)+rob2(root->right));
        mymap[root] = val;
        return val;
    }

    //方法3
    int rob(TreeNode* root) {
    	vector<int> res = robSub(root);
    	return max(res[0],res[1]);
    }
    vector<int> robSub(TreeNode *root)
    {
    	if(!root)	return vector<int> (2);
    	vector<int> left = robSub(root->left);
    	vector<int> right = robSub(root->right);
    	vector<int> result(2);
    	result[0] = max(left[0],left[1]) + max(right[0],right[1]);
    	result[1] = root->val + left[0] + right[0];
    	return result;
    }
};
int main()
{
	Solution s;
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n4.left = &n3, n4.right = &n5;
	n3.left = &n1, n1.right = &n2;
	n5.right = &n6;
	cout << s.rob(&n4) << endl;
}

