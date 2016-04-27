#判断一个二叉树是否为对称二叉树
#递归方法
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def isSymmetric(self, root):
        return self.symmetric(root.left,root.right) if root!=None else True

    def symmetric(self,l,r):
        if l==None and r==None:
            return True
        elif l==None or r==None:
            return False
        elif l.val != r.val:
            return False
        else:
            return  self.symmetric(l.left,r.right) and self.symmetric(l.right,r.left)


t1 = TreeNode(1)
t2 = TreeNode(2)
t3 = TreeNode(2)
t4 = TreeNode(3)
t5 = TreeNode(3)
t6 = TreeNode(4)
t7 = TreeNode(4)
t1.left = t2
t1.right = t3
t2.left = t4
t2.right = t6
t3.right = t5
t3.left = t7


s = Solution()
print(s.isSymmetric(t1))

