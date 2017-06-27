/*
判断两个二叉树是否为同一个二叉树，结构一样，对应值也一样。
*/
/*
思路：递归判断即可。
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
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL) return (p == q);
    	return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};
int main()
{
	Solution s;
	TreeNode t1(1),t2(2),t3(3);
	t1.right = &t2;
	t2.left = &t3;
	TreeNode t4(1),t5(2),t6(3);
	t4.right = &t5;
	t5.left = &t6;
	cout << s.isSameTree(&t1,&t4)<<endl;
}

