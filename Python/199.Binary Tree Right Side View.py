#从二叉树的右边看，返回每一层的最右边一个元素
#根据分层返回二叉树元素改编来
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def rightSideView(self, root):
        self.result = []
        self.inorder(root,0)
        return [self.result[i][-1] for i in range(len(self.result))]

    def inorder(self,p,level):
        if p!=None:
            if len(self.result)<=level:
                self.result.append([p.val])
            else:
                self.result[level].append(p.val)
            self.inorder(p.left,level+1) if p.left!=None else None
            self.inorder(p.right,level+1) if p.right!=None else None

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
print(s.rightSideView(t1))