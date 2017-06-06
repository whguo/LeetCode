/*
返回二叉搜索树中第k小的数。
*/
/*
思路：二分查找法。计算根结点左边结点个数count，如果大于k，递归左子树。
如果小于k，那么递归右子树，寻找右子树中第k-count-1小的数。
等于k，则返回当前根结点的值。
如果第k小的数更多的出现在右子树中，那么时间复杂度更小。
如果更多出现在左子树，那么会不断重复计算左子树结点个数，反而更慢。
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
        int count = countNodes(root->left);
        if (k <= count) 
            return kthSmallest(root->left, k);
        else if (k > count + 1)
            return kthSmallest(root->right, k-1-count); // 1 is counted as current node 
        return root->val;
    }
    int countNodes(TreeNode* p)
    {
    	if(p==NULL)	return 0;
    	return 1+countNodes(p->left)+countNodes(p->right);
    }
};

int main()
{
	Solution s;
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n4.left = &n3, n4.right = &n5;
	n3.left = &n1, n1.right = &n2;
	n5.right = &n6;
	cout<<s.countNodes(&n4)<<endl;
}

