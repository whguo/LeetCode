/*
后序遍历二叉树。
*/
/*
思路：1.使用递归。
      2.使用栈。当某个结点第一次出现在栈顶时，不能将其出栈并访问，因为右子结点还没访问。
      当访问完其右孩子时，该结点又出现在栈顶，此时可以将其出栈并访问。
      具体见"更简单的非递归遍历二叉树"。
*/
#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root)   return result;
        stack< pair<TreeNode *, bool> > s;
        s.push(make_pair(root, false));
        bool visited;
        while(!s.empty())
        {
            root = s.top().first,visited = s.top().second;
            s.pop();
            if(visited)
                result.push_back(root->val);
            else
            {
                s.push(make_pair(root, true));
                if(root->right) s.push(make_pair(root->right, false));
                if(root->left) s.push(make_pair(root->left, false));
            }
        } 
        return result;
    }
};
int main()
{
	Solution s;
	TreeNode root(1),t1(2),t2(3);
	root.right = &t1;
	t1.left = &t2;
	vector<int> out = s.postorderTraversal(&root);
	for(int n:out)
		cout<<n<<" ";
	cout<<endl;
}

