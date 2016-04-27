#根据二叉树的前序遍历和中序遍历复原二叉树
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        if preorder==[]:
            return None
        return self.buildSubTree(preorder,inorder,0,len(preorder)-1,0,len(inorder)-1)

    def buildSubTree(self,preorder,inorder,l,r,ll,rr):
        if l>r or ll>rr:
            return None
        node = TreeNode(preorder[l])
        i = ll
        while i<=rr:
            if inorder[i]==preorder[l]:
                break
            i += 1
        length1 = i-ll-1    ##表示分为左子树的长度
        length2 = rr-i-1    ##表示分为右子树的长度
        node.left = self.buildSubTree(preorder,inorder,l+1,i-ll+l,ll,i-1)
        node.right = self.buildSubTree(preorder,inorder,r-rr+i+1,r,i+1,rr)
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
root = s.buildTree([1,2,4,6,3,7,5],[4,2,6,1,7,3,5])
print(ss.inorderTraversal(root))



