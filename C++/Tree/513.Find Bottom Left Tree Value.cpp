/*
返回二叉树最底层的最左侧结点值
*/
/*
思路：1.递归遍历记录每层的第一个。
	  2.使用队列进行广度优先遍历，而且是广度是从右向左的。那么队列中的最后一个结点就是所求结点。
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
private:
	vector<int>	firstoflevel;
public:
	int findBottomLeftValue1(TreeNode* root) {
        helpfind(root,0);
        return firstoflevel.back();
    }
    void helpfind(TreeNode* root,int level)
    {
    	if(firstoflevel.size() <= level)	firstoflevel.push_back(root->val);
    	if(root->left)	helpfind(root->left,level+1);
    	if(root->right)	helpfind(root->right,level+1);
    }
    
    //方法2
    int findBottomLeftValue(TreeNode* root) {
    	queue<TreeNode*>	myqueue;
    	myqueue.push(root);
    	TreeNode* tmp;
    	while(!myqueue.empty())
    	{
    		tmp = myqueue.front();
    		myqueue.pop();
    		if(tmp->right)	myqueue.push(tmp->right);
    		if(tmp->left)	myqueue.push(tmp->left);
    	}
    	return tmp->val;
    }
};
int main()
{
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n4.left = &n3, n4.right = &n5;
	n3.left = &n1, n1.right = &n2;
	n5.right = &n6;
	Solution s;
    cout << s.findBottomLeftValue(&n4) <<endl;
}

