#判断两个二叉树是否相同(形状相同，对应结点的值相同)
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def isSameTree(self, p, q):
        if p==None and q==None:
            return True
        elif p==None or q==None:
            return False
        if p.val !=q.val:
            return False
        else:
            return self.isSameTree(p.left,q.left) and self.isSameTree(p.right,q.right)


t1 = TreeNode(1)
t2 = TreeNode(2)
t3 = TreeNode(3)
t4 = TreeNode(4)
t5 = TreeNode(5)
t6 = TreeNode(6)
t4.left = t2
t4.right = t6
t2.left = t1
t2.right = t3
t6.right = t5

t11 = TreeNode(1)
t12 = TreeNode(2)
t13 = TreeNode(3)
t14 = TreeNode(4)
t15 = TreeNode(5)
t16 = TreeNode(6)
t14.left = t12
t14.right = t16
t12.left = t11
t12.right = t13
t16.right = t15

s = Solution()
print(s.isSameTree(t4,t14))

