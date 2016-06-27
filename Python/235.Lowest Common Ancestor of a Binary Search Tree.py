#返回二叉搜素树两个节点的最小共同祖先
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        cur = root
        if p.val>q.val: q , p = p , q
        while cur:
            if cur==p or cur==q:
                return cur
            if cur.val>p.val and cur.val<q.val:
                return cur
            elif cur.val>q.val:
                cur = cur.left
            else:
                cur = cur.right

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
print(s.lowestCommonAncestor(t6,t3,t2).val)