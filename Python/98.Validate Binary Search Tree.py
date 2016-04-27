#判断一个二叉树是否为二叉搜索树
#中序遍历二叉搜索树的结果就是排好序的，如果中序遍历时发现不满足顺序的即可认为错误
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def isValidBST(self, root):
        self.result = []
        return self.inorder(root)

    def inorder(self,p):
        if p!=None:
            l = self.inorder(p.left)
            if self.result!=[] and self.result[-1]>p.val:
                return False
            else:
                self.result.append(p.val)
            r = self.inorder(p.right)
            return l and r
        else:
            return True

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

s = Solution()
print(s.isValidBST(t4))

