#求出所有根节点到叶节点的路径
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def binaryTreePaths(self, root):
        if root==None:  return []
        self.result = []
        self.dfs(root,"")
        return self.result

    def dfs(self,node,path):
        if node.right==None and node.left==None:
            self.result.append(path+str(node.val))
            return
        if node.left!=None:
            self.dfs(node.left,path+str(node.val)+"->")
        if node.right!=None:
            self.dfs(node.right,path+str(node.val)+"->")


t1 = TreeNode(1)
t2 = TreeNode(2)
t3 = TreeNode(3)
t4 = TreeNode(4)
t5 = TreeNode(5)
t6 = TreeNode(6)
t7 = TreeNode(7)
t1.left = t2
t1.right = t3
t2.left = t4
t2.right = t6
t3.right = t5
t3.left = t7

s = Solution()
print(s.binaryTreePaths(t1))
