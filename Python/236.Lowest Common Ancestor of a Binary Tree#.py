#返回二叉树两个节点的最小共同祖先
#递归方法，从根节点开始，看p和q在左右哪个节点
#如果left不为空，right也不为空，那么p和q分别在root的两侧，返回root
#否则，返回二者中不为空的一个节点
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        if root == None: return None;
        if root == p or root == q: return root;
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        return   root if (left != None and right != None) else  (right if left == None else left)


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
print(s.lowestCommonAncestor(t6,t7,t9).val)