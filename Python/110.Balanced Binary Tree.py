#判断一棵二叉树是否为平衡二叉树(任意两子树深度差不超过2)
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def isBalanced(self, root):
        if root==None:
            return True
        depthLeft = self.getDepth(root.left,1)
        depthRight = self.getDepth(root.right,1)
        if abs(depthLeft-depthRight)>1:
            return False
        else:
            return self.isBalanced(root.left) and self.isBalanced(root.right)

    def getDepth(self,node,depth):
        if node==None:
            return depth
        else:
            return max(self.getDepth(node.left,depth+1),self.getDepth(node.right,depth+1))



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
t7 = TreeNode(0)

s = Solution()
print(s.isBalanced(t7))