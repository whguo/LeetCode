#求完全二叉树的节点个数
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):

    #先计算总共多少层，计算出除了最后一层的节点数，然后计算最后一层的数量
    def countNodes(self, root):
        if root==None: return 0
        if root.left==None: return 1
        height , nodesSum , curr = 0 , 0 , root
        while curr.left:
            nodesSum += (1<<height)
            height+=1
            curr = curr.left
        return nodesSum + self.countLastLevel(root, height)

    #最后一层的数量计算：根节点的左子节点一直向右走，找到中间节点
    #中间节点为空，则最后一层不到一半，计算左子树的最后一层；不为空，则超过一半，计算右子树的最后一层。
    def countLastLevel(self,root, height):
        if height==1:
            if root.right!=None: return 2
            elif root.left!=None: return 1
            else:   return 0
        midNode = root.left
        currHeight = 1
        while currHeight<height:
            currHeight+=1
            midNode = midNode.right
        if midNode==None: return self.countLastLevel(root.left, height-1)
        else: return (1<<(height-1)) + self.countLastLevel(root.right, height-1)

    #根据分层返回数字修改来的，超时
    def countNodes1(self, root):
        self.result = []
        self.inorder(root,0)
        return sum(self.result)

    def inorder(self,p,level):
        if p!=None:
            if len(self.result)<=level:
                self.result.append(1)
            else:
                self.result[level]+=1
            self.inorder(p.left,level+1) if p.left!=None else None
            self.inorder(p.right,level+1) if p.right!=None else None

t1 = TreeNode(1)
t2 = TreeNode(2)
t3 = TreeNode(2)
t4 = TreeNode(3)
t5 = TreeNode(3)
t6 = TreeNode(4)
t7 = TreeNode(4)
t1.left = t2
t1.right = t3
t2.left = t4
t2.right = t6
t3.right = t5
t3.left = t7

s = Solution()
print(s.countNodes(t1))
