/*
在任意一个二叉树结构中增加一个next指针，指向同一层右侧的结点。
如果右侧没有结点则为NULL。
        1
       /  \
      2    3
     / \    \
    4   5    7
    改造为：
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/
/*
思路：1.按照分层返回结点的方法，记录到当前为止每层的最右侧结点。然后不断更新。
	  2.三个辅助的指针，head代表下一层的头，prev代表下一层的前一个结点，cur表示当前层的当前结点。
	  每一层的循环，先将prev和head置为NULL，然后循环当前层的每个结点，找到下一层第一个不为空的位置
	  然后将head和prev都赋值为它。继续循环该层，然后将下一层的结点都用prev连接起来，直到该层结束。
	  最后cur置为head，开始下一层，循环直到为空。
*/
#include <iostream>
#include <vector>
using namespace std;

struct TreeLinkNode {
	int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *head=NULL,*prev=NULL,*cur = root;
        while(cur)
        {
        	while(cur)  //当前层的循环
        	{
        		if(cur->left)
        		{
        			if(prev)	prev->next = cur->left;
        			else head = cur->left;
        			prev = cur->left;
        		}
        		if(cur->right)
        		{
        			if(prev)	prev->next = cur->right;
        			else head = cur->right;
        			prev = cur->right;
        		}
        		cur = cur->next;
        	}
        	cur = head , head = NULL, prev = NULL;
        }	
    }
};
int main()
{
	Solution s;
	TreeLinkNode root(1),t1(2),t2(3);
	root.right = &t1;
	t1.left = &t2;
	s.connect(&root);
}

