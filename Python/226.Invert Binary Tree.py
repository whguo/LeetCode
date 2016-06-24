#把一棵二叉树翻转过来
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def invertTree(self, root):
        self.helpInvertTree(root)
        return root

    def helpInvertTree(self,node):
        if node:
            node.right , node.left = node.left , node.right
            self.helpInvertTree(node.left)
            self.helpInvertTree(node.right)

t1 = TreeNode(4)
t2 = TreeNode(2)
t3 = TreeNode(7)
t4 = TreeNode(1)
t5 = TreeNode(3)
t6 = TreeNode(6)
t7 = TreeNode(7)
t1.left = t2
t1.right = t3
t2.left = t4
t2.right = t6
t3.right = t5
t3.left = t7

s = Solution()
s.invertTree(t1)