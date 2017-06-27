/*
把二叉搜索树转换为"大树"。
转换操作为每个结点的值需要加上其他值大于它的结点的值。
   5           18
 /   \    =>  /   \
2     13     20    13
结点2加上5+13，结点5加上13，结点13不动。
*/
/*
思路：首先二叉搜索树的中序遍历是有序的，那么想要得到所有比当前值大的结点
  	  就要从右侧进行中序遍历，遍历到当前结点时，比它大的结点一定已经遍历过了。
  	  然后将已经遍历的数累计求和，加到当前结点即可。
*/
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
private:
	int cur_sum = 0;
public:
	TreeNode* convertBST(TreeNode* root) {
		helpconvert(root);
        return root;
    }
    void helpconvert(TreeNode* root)
    {
    	if(!root)	return ;
    	if(root->right)	helpconvert(root->right);
    	root->val = (cur_sum += root->val);
    	if(root->left)	helpconvert(root->left); 
    }
};
int main()
{
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n4.left = &n3, n4.right = &n5;
	n3.left = &n1, n1.right = &n2;
	n5.right = &n6;
	Solution s;
    TreeNode* out = s.convertBST(&n4);
}

