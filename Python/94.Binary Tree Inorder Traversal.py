#写出二叉树的中序遍历
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def inorderTraversal(self, root):
        self.result = []
        self.inorder(root)
        return self.result

    def inorder(self,p):
        if p!=None:
            self.inorder(p.left) if p.left!=None else None
            self.result.append(p.val)
            self.inorder(p.right) if p.right!=None else None


t1 = TreeNode(1)
t2 = TreeNode(2)
t3 = TreeNode(3)
t4 = TreeNode(4)
t5 = TreeNode(5)
t6 = TreeNode(6)
t1.left = t2
t1.right = t3
t3.left = t4
t4.right = t5

s = Solution()
print(s.inorderTraversal(t1))

