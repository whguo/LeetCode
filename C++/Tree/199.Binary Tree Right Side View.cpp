/*
从上到下返回二叉树每一层的最右结点。
*/
/*
思路：修改按层返回结点代码，递归算法。
      但是递归时，先递归右子树，这样只需要在result数组小于level时加入值即可，
      不用进行值的覆盖，由于总是先遍历右边，所以result数组中一定是每层的最右。
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
	vector<int> result;
public:
    vector<int> rightSideView(TreeNode* root) {
        helpLevelOrder(root,1);
        return result;
    }
    void helpLevelOrder(TreeNode* cur,int level)
    {
    	if(cur!=NULL)
    	{
    		if(result.size()<level)	result.push_back(cur->val);
    		helpLevelOrder(cur->right,level+1);
    		helpLevelOrder(cur->left,level+1);	
    	}
    }
};
int main()
{
	Solution s;
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n4.left = &n3, n4.right = &n5;
	n3.left = &n1, n1.right = &n2;
	n5.right = &n6;
	vector<int> out = s.rightSideView(&n4);
	for(int n:out)
		cout<<n<<endl;
}

