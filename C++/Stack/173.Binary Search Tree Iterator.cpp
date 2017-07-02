/*
实现二叉搜索树的一个迭代器，调用next()函数可以返回下一个最小的数。
next()函数和hasNext()函数需要时间O(1)和空间O(h)，h为二叉树高度。
*/
/*
思路：开始的最小值为最左子树，下一个最小值为它的右子树的最左子树，以此类推。
      所以使用一个栈，从根开始，向左子树遍历并且入栈，直到空。那么此时栈顶即为最小值。
      hasNext()函数只需要判断栈是否为空即可。
      当调用了next()函数以后，取到栈顶，出栈，然后将栈顶的右子树的最左子树，一路压栈。
      此时栈顶就是下一个最小数。
*/
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class BSTIterator {
private:
    stack<TreeNode*>	mystack;
public:
    BSTIterator(TreeNode *root) {
        while(root)
        {
        	mystack.push(root);
        	root = root->left;
        }
    }

    bool hasNext() {
        return !mystack.empty();
    }

    int next() {
        TreeNode* t = mystack.top(),*tmp = t->right;
        mystack.pop();
        while(tmp)
        {
        	mystack.push(tmp);
        	tmp = tmp->left;
        }
        return t->val;
    }
};
int main()
{
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n4.left = &n3, n4.right = &n5;
	n3.left = &n1, n1.right = &n2;
	n5.right = &n6;
	BSTIterator i = BSTIterator(&n4);
  	while (i.hasNext()) cout << i.next();
  	cout<<endl;
}

