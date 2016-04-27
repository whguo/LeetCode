#判断一棵二叉树是否为平衡二叉树(任意两子树深度差不超过2)
#更快(仅需要一次遍历)
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def __init__(self):
        self.dic = {}
    def isBalanced(self, root):
        if root==None:
            self.dic[root] = 0
            return True
        if self.isBalanced(root.left) and self.isBalanced(root.right):
            if abs(self.dic[root.right]-self.dic[root.left])>1:
                return False
            else:
                self.dic[root] = max(self.dic[root.left],self.dic[root.right])+1
                return True
        else:
            return False



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
print(s.isBalanced(t1))