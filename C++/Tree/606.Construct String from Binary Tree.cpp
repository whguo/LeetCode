/*
给出二叉树，返回它所代表的先序遍历字符串。如果右节点不为空，左边空结点用空的括号对表示。
       1
     /   \
    2     3
   /    
  4             返回"1(2(4))(3)"
       1
     /   \
    2     3
     \  
      4        返回"1(2()(4))(3)"
*/
/*
思路：递归做法。
*/
#include <iostream>
#include <cstring>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    string tree2str(TreeNode* t) {
        if (!t) return "";
        string s = to_string(t->val);
        if (t->left) 	s += "(" + tree2str(t->left) + ")";
        else if (t->right)	s += "()";
        if (t->right) 	s += "(" + tree2str(t->right) + ")";
        return s;
    }
};
int main()
{
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n4.left = &n3, n4.right = &n5;
	n3.left = &n1, n1.right = &n2;
	n5.right = &n6;
	Solution s;
    cout << s.tree2str(&n4)<<endl;
}

