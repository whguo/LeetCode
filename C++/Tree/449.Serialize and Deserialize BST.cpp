/*
对二叉搜索树进行序列化和反序列化。
*/
/*
思路：由于二叉搜索树的中序遍历是一定的，所以任何相同结点的二叉搜索树中序序列一样。
      因此，为了使得序列化后的唯一性，考虑使用前序遍历。
      前序遍历的序列中，先是root，然后是root左侧，最后root右侧。
      左右侧是靠root结点的值区分开的，左侧的小于root，右侧大于。
      反序列化是依据这一特点解开的。
      为了方便，这里使用4字节的char直接表示一个int值。
*/
#include <iostream>
#include <cstring>
#include <limits.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:
	string serialize(TreeNode* root) {
        string order;
        inorderDFS(root, order);
        return order;
    }
    inline void inorderDFS(TreeNode* root, string& order) {
        if (!root) return;
        char buf[4];
        memcpy(buf, &(root->val), sizeof(int));
        for (int i=0; i<4; i++) order.push_back(buf[i]);
        inorderDFS(root->left, order);
        inorderDFS(root->right, order);
    }

    TreeNode* deserialize(string data) {
        int pos = 0;
        return reconstruct(data, pos, INT_MIN, INT_MAX);
    }
    inline TreeNode* reconstruct(const string& buffer, int& pos, int minValue, int maxValue) {
        if (pos >= buffer.size()) return NULL; 
        
        int value;
        memcpy(&value, &buffer[pos], sizeof(int));
        if (value < minValue || value > maxValue) return NULL;
        
        TreeNode* node = new TreeNode(value);
        pos += sizeof(int);
        node->left = reconstruct(buffer, pos, minValue, value);
        node->right = reconstruct(buffer, pos, value, maxValue);
        return node;
    }
};
int main()
{
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n4.left = &n3, n4.right = &n5;
	n3.left = &n1, n1.right = &n2;
	n5.right = &n6;
	Codec codec;
    TreeNode *root = codec.deserialize(codec.serialize(&n4));
}

