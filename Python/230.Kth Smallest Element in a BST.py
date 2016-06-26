#返回二叉搜索树中第K小的数
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def kthSmallest(self, root, k):
        stack , p , i = [] , root , 1
        while p:
            stack.append(p)
            p = p.left
        while i!=k:
            p = stack.pop().right
            while p:
                stack.append(p)
                p = p.left
            i += 1
        return stack[-1].val

t1 = TreeNode(1)
t2 = TreeNode(2)
t3 = TreeNode(3)
t4 = TreeNode(4)
t5 = TreeNode(5)
t6 = TreeNode(6)
t7 = TreeNode(7)
t8 = TreeNode(8)
t9 = TreeNode(9)
t6.left = t4
t6.right = t8
t4.left = t2
t4.right = t5
t2.left = t1
t2.right = t3
t8.left =  t7
t8.right = t9

s = Solution()
print(s.kthSmallest(t6,9))
