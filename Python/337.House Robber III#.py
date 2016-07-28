#房子构成二叉树，节点数字代表金额。
#相邻的两个父子节点不能同时被偷取，求出最大能偷取的金额。

#树形dp
#定义两个DP，一个是被偷取的DP1，一个是不偷取的DP2。然后进行深度优先搜索，计算每一个节点的DP1和DP2，最后输出根节点中DP1和DP2的较大者。
#即 rob_root = max(rob_L + rob_R , no_rob_L + no_nob_R + root.val)
#   no_rob_root = rob_L + rob_R
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def rob(self, root):
        return self.dfs_rob(root)[0]

    def dfs_rob(self, root):
        if not root: return 0,0
        rob_L, no_rob_L = self.dfs_rob(root.left)
        rob_R, no_rob_R = self.dfs_rob(root.right)
        return max(no_rob_L + no_rob_R + root.val , rob_L + rob_R), rob_L + rob_R

t1 = TreeNode(3)
t2 = TreeNode(2)
t3 = TreeNode(3)
t4 = TreeNode(3)
t5 = TreeNode(1)
t1.left = t2
t1.right = t3
t2.right = t4
t3.right = t5


s = Solution()
print(s.rob(t1))

