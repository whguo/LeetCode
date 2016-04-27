#根据二叉树的后序遍历和中序遍历复原二叉树
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def buildTree(self, inorder, postorder):
        return self.buildSubTree(postorder,inorder,0,len(postorder)-1,0,len(inorder)-1)

    def buildSubTree(self,postorder,inorder,l,r,ll,rr):
        if l>r or ll>rr:
            return None
        node = TreeNode(postorder[r])
        i = ll
        while i<=rr:
            if inorder[i]==postorder[r]:
                break
            i += 1
        length1 = i-ll-1    ##表示分为左子树的长度
        length2 = rr-i-1    ##表示分为右子树的长度
        node.left = self.buildSubTree(postorder,inorder,l,length1+l,ll,i-1)
        node.right = self.buildSubTree(postorder,inorder,r-length2-1,r-1,i+1,rr)
        return node

class Ssolution(object):
    def inorderTraversal(self, root):
        self.result = []
        self.inorder(root)
        return self.result

    def inorder(self,p):
        if p!=None:
            self.inorder(p.left) if p.left!=None else None
            self.result.append(p.val)
            self.inorder(p.right) if p.right!=None else None

ss = Ssolution()
s = Solution()
root = s.buildTree([4,2,8,9,6,1,7,3,5],[4,9,8,6,2,7,5,3,1])
print(ss.inorderTraversal(root))



