/*
在完全二叉树结构中增加一个next指针，指向同一层右侧的结点。
如果右侧没有结点则为NULL。
        1            
       /  \
      2    3
     / \  / \
    4  5  6  7
    改造为：
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/
/*
思路：1.按照分层返回结点的方法，记录到当前为止每层的最右侧结点。然后不断更新。
	  2.可以这样做是因为给出的是完全二叉树。
      使用两个辅助指针，一个pre指向每层最左结点，一个cur指针横着遍历每一层的每个结点。
      每一层，cur从pre开始，cur的左子结点的next赋值为cur的右子结点，即cur->left->next=cur->right。
      如果cur的next不为空，则右侧有结点。那么右子结点的next赋值为右侧结点的左子结点，
      即cur->right->next=cur->next->left。然后cur向右移动，直到cur为空。
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
private:
	vector<TreeLinkNode *> nodevec;
public:
	//方法1
    void connect1(TreeLinkNode *root) {
        if(root==NULL)	return;
        helpLevelOrder(root,0);
    }
    void helpLevelOrder(TreeLinkNode* cur,int level)
    {
    	if(cur!=NULL)
    	{
    		if(nodevec.size()<=level)	nodevec.push_back(cur);
    		else 
    		{
    			nodevec[level]->next = cur;
    			nodevec[level] = cur;
    		}
    		helpLevelOrder(cur->left,level+1);
    		helpLevelOrder(cur->right,level+1);
    	}
    }

    //方法2
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
    	TreeLinkNode *pre = root;
    	TreeLinkNode *cur = NULL;
    	while(pre->left) 
    	{
        	cur = pre;
        	while(cur) 
        	{
            	cur->left->next = cur->right;
            	if(cur->next) cur->right->next = cur->next->left;
            	cur = cur->next;
        	}
        	pre = pre->left;
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

