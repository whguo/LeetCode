#求出所有从根节点到叶节点的路径，路径上的数之和为目标数
import copy
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def hasPathSum(self, root, sum):
        self.sum = sum
        self.result , tmp = [] , []
        self.inorder(root,0,tmp)
        return self.result

    def inorder(self,p,cursum,tmp):
        if p!=None:
            cursum += p.val
            tmp.append(p.val)
            if p.left==None and p.right==None:
                if cursum==self.sum:
                    self.result.append(copy.deepcopy(tmp))
            else:
                self.inorder(p.left,cursum,tmp)
                self.inorder(p.right,cursum,tmp)
            tmp.pop()



t1 = TreeNode(5)
t2 = TreeNode(4)
t3 = TreeNode(8)
t4 = TreeNode(11)
t5 = TreeNode(13)
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
print(s.hasPathSum(t1,22))