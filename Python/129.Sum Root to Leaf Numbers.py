#每个节点是一个个位数，从根节点到叶节点的一条路径组成一个大数，求所有这些数的和
#    1
#   / \
#  2   3     返回12+13=25
import copy
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def sumNumbers(self, root):
        self.sum  = 0
        self.inorder(root,0)
        return self.sum

    def inorder(self,p,cursum):
        if p!=None:
            tmp = cursum*10 + p.val
            if p.left==None and p.right==None:
                self.sum += tmp
            else:
                self.inorder(p.left,tmp)
                self.inorder(p.right,tmp)


t1 = TreeNode(5)
t2 = TreeNode(4)
t3 = TreeNode(8)
t4 = TreeNode(1)
t5 = TreeNode(3)
t6 = TreeNode(4)
t7 = TreeNode(7)
t8 = TreeNode(2)
t9 = TreeNode(5)
t1.left = t2
t1.right = t3
t2.left = t4
t3.right = t6
t3.left = t5
t4.left = t7
t4.right = t8
t6.right = t9

s = Solution()
print(s.sumNumbers(t1))