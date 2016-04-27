#返回二叉树的深度
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def levelOrder(self, root):
        self.maxdepth = 0
        self.inorder(root,1)
        return self.maxdepth

    def inorder(self,p,level):
        if p!=None:
            if self.maxdepth<level:
                self.maxdepth = level
            self.inorder(p.left,level+1) if p.left!=None else None
            self.inorder(p.right,level+1) if p.right!=None else None



t1 = TreeNode(1)
t2 = TreeNode(2)
t3 = TreeNode(3)
t4 = TreeNode(4)
t5 = TreeNode(5)
t6 = TreeNode(6)
t7 = TreeNode(7)
t8 = TreeNode(8)
t1.left = t2
t1.right = t3
t2.left = t4
t2.right = t6
t3.right = t5
t3.left = t7
t7.right = t8


s = Solution()
print(s.levelOrder(t7))

