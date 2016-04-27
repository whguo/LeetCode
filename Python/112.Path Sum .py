#判断是否存在一条从根节点到叶节点的路径，这条路径的数之和为目标数
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def hasPathSum(self, root, sum):
        self.sum = sum
        return self.inorder(root,0)

    def inorder(self,p,cursum):
        if p!=None:
            cursum += p.val
            if p.left==None and p.right==None:
                return cursum==self.sum
            else:
                if self.inorder(p.left,cursum)==True:
                    return True
                if self.inorder(p.right,cursum)==True:
                    return True
                return False


t1 = TreeNode(5)
t2 = TreeNode(4)
t3 = TreeNode(8)
t4 = TreeNode(11)
t5 = TreeNode(13)
t6 = TreeNode(4)
t7 = TreeNode(7)
t8 = TreeNode(2)
t9 = TreeNode(1)
t1.left = t2
t1.right = t3
t2.left = t4
t3.right = t6
t3.left = t5
t4.left = t7
t4.right = t8
t6.right = t9

s = Solution()
print(s.hasPathSum(t1,19))