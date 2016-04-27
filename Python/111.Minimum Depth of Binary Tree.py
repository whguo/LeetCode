#求叶结点的最小深度
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def inorderTraversal(self, root):
        self.mindepth , self.init = 0 , 0
        self.inorder(root,1)
        return self.mindepth

    def inorder(self,p,depth):
        if p!=None:
            if p.left==None and p.right==None:
                if self.init==0:
                    self.mindepth = depth
                    self.init = 1
                else:
                    self.mindepth = depth if self.mindepth>depth else self.mindepth
            else:
                self.inorder(p.left,depth+1) if p.left!=None else None
                self.inorder(p.right,depth+1) if p.right!=None else None


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

s = Solution()
print(s.inorderTraversal(t7))