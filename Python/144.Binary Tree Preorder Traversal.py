#先序遍历一个二叉树
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def preorderTraversal(self, root):
        self.result = []
        self.preorder(root)
        return self.result

    def preorder(self,p):
        if p!=None:
            self.result.append(p.val)
            self.preorder(p.left) if p.left!=None else None
            self.preorder(p.right) if p.right!=None else None


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
t2.right = t6

s = Solution()
print(s.preorderTraversal(t1))