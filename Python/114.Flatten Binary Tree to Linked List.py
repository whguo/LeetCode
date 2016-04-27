#把二叉树扁平化(全都放在右子树)
import copy
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def flatten(self, root):
        if root == None:
            return root
        self.flattenSubTree(root)
        return root

    def flattenSubTree(self,root):
        if root.right==None and root.left==None:
            return root
        if root.right==None:
            deepleft = self.flattenSubTree(root.left)
            root.right = root.left
            root.left = None
            return deepleft
        elif root.left==None:
            deepright = self.flattenSubTree(root.right)
            return deepright
        else:
            deepleft = self.flattenSubTree(root.left)
            deepright = self.flattenSubTree(root.right)
            deepleft.right = root.right
            root.right = root.left
            root.left = None
            return deepright


t1 = TreeNode(1)
t2 = TreeNode(2)
t3 = TreeNode(3)
t4 = TreeNode(4)
t5 = TreeNode(5)
t6 = TreeNode(6)
t7 = TreeNode(7)
t8 = TreeNode(8)
t9 = TreeNode(9)
t1.left = t2
t1.right = t3
t2.left = t4
t2.right = t5
t3.left = t6
t3.right = t7
t4.left = t8
t8.right = t9

s = Solution()
root = s.flatten(t1)
while root!=None:
    print(root.val)
    root = root.right
