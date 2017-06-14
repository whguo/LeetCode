/*
给出一组整数，数大小在0-2^31，找出其中的两个，有最大的异或值。
*/
/*
思路：使用前缀树。左代表0，右代表1。
	  先遍历每个数的32位，构造出前缀树。
	  然后再用每个数去从上到下遍历前缀树。
	  遍历的方法为，如果这一位为0而且右子树不为空，那么在结果中或上这个二进制位，然后走右子树。
	  如果右子树为空，那么数组中没有这一位为1的数，只能走左子树。
	  如果这一位为1而且左子树不为空，相反即可。
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class TreeNode
{
public:
	TreeNode* next[2];
	TreeNode(){ next[0] = NULL; next[1] = NULL;}
};

class Solution {
public:
	int findMaximumXOR(vector<int>& nums) {
    	TreeNode* root = buildTree(nums);
    	int result = 0;
    	for(int num:nums)
    		result = max(result,getOneMax(root,num));
    	return result;
    }
    TreeNode* buildTree(vector<int>& nums)
    {
		TreeNode* root = new TreeNode,*cur;
		int n = nums.size();
		for(int num:nums)
		{
			cur = root;
			for(int j=31; j >= 0; --j)
			{
				int index = ((num>>j)&1);
				if(cur->next[index]==NULL)
					cur->next[index] = new TreeNode;
				cur = cur->next[index];
			}
		}
		return root;
    }
    int getOneMax(TreeNode* cur,int num)
    {
    	int result = 0;
    	for(int i=31; i >= 0; --i)
    	{
    		int index = ((num >> i) & 1)? 0:1;
    		result <<= 1;
    		if(cur->next[index])
    		{
    			result |= 1;
    			cur = cur->next[index];
    		}
    		else
    			cur = cur->next[index? 0:1];
    	}
    	return result;
    }
};
int main()
{
	Solution s;
	vector<int>  nums{3, 10, 5, 25, 2, 8};
	cout << s.findMaximumXOR(nums) <<endl;
}

