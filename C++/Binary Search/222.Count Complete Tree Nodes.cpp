/*
计算完全二叉树有多少个结点。
*/
/*
思路：首先遍历最左子树，求出二叉树的深度height，那么除最后一层外，共有2^(height-1)-1个结点。
然后计算最后一层有多少结点。方法是，从根结点开始，找到它的左子树的最右下子结点。
如果它不为空，那么根结点的左子树最后一层已经被填满，那么令根结点的右子树为根，做同样的操作。
如果它为空，那么根结点的左子树最后一层没有被填满，那么令根结点的左子树为根，做同样的操作。
直到寻找到最后一层最后一个结点的位置。
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
public:
	int countNodes(TreeNode* root) {
        if(!root) return 0;
    	TreeNode *temp = root;
    	int height = 0, count = 0, level;
    	while(temp) 
    	{
        	temp = temp->left;
        	height ++;
    	}
    	temp = root;
    	level = height - 2;     //从第二行到最后一行所用次数。
    	while(level >= 0) 
    	{
        	TreeNode *left = temp->left;
        	for(int i = 0;i < level;i ++)    //寻找最右子树
        	{
            	left = left->right;
        	}
        	if(left) 
        	{
            	temp = temp->right;
            	count += (1 << level);
        	} 
        	else temp = temp->left;
        	--level;
    	}
    	if(temp) count ++;    //最后一个二层子树的右结点。
    	return (1 << (height - 1)) + count - 1;
    }
};

int main()
{
	Solution s;
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n1.left = &n2, n1.right = &n3;
	n2.left = &n4, n2.right = &n5;
	n3.left = &n6;
	cout<<s.countNodes(&n1)<<endl;
}

