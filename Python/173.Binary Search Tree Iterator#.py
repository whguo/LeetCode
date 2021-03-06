#写函数，是否有下一个节点，求出下一个数字最小的节点
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class BSTIterator(object):
    def __init__(self, root):
        self.stack = []
        self.pushLeft(root)

    def hasNext(self):
        return self.stack

    def next(self):
        top = self.stack.pop()
        self.pushLeft(top.right)
        return top.val

    def pushLeft(self,node):
        while node:
            self.stack.append(node)
            node = node.left


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

i, v = BSTIterator(t6), []
while i.hasNext(): v.append(i.next())
print(v)