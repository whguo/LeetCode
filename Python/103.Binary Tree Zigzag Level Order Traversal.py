#按照一条龙的顺序返回一棵二叉树
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def levelOrder(self, root):
        self.result = []
        self.inorder(root,0)
        for i in range(len(self.result)):           #把奇数行倒过来
            if i%2==1:
                self.result[i] = self.result[i][::-1]
        return self.result

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
print(s.levelOrder(t1))

