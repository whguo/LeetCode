#把二叉树同一深度的节点串联起来(next)
class TreeLinkNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        self.next = None

class Solution(object):
    def connect(self, root):
        self.dic = {}
        self.inorder(root,0)
        return root

    def inorder(self,p,level):
        if p!=None:
            if len(self.dic)<=level:
                self.dic[level] = p
            else:
                self.dic[level].next = p
                self.dic[level] = p
            self.inorder(p.left,level+1) if p.left!=None else None
            self.inorder(p.right,level+1) if p.right!=None else None



t1 = TreeLinkNode(1)
t2 = TreeLinkNode(2)
t3 = TreeLinkNode(3)
t4 = TreeLinkNode(4)
t5 = TreeLinkNode(5)
t6 = TreeLinkNode(6)
t7 = TreeLinkNode(7)
t8 = TreeLinkNode(8)
t9 = TreeLinkNode(9)
t1.left = t2
t1.right = t3
t2.left = t4
t2.right = t5
t3.left = t6
t3.right = t7
t4.left = t8
t4.right = t9

s = Solution()
root = s.connect(t1)
while root!=None:
    p = root
    while p!=None:
        print(p.val)
        p = p.next
    print("next")
    root = root.left
