#根据排序数组生成一个平衡二叉排序树
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def sortedArrayToBST(self, nums):
        return self.toBST(nums,0,len(nums)-1)

    def toBST(self,nums,l,r):
        if l>r:
            return None
        mid = (l+r)//2
        node = TreeNode(nums[mid])
        node.left = self.toBST(nums,l,mid-1)
        node.right = self.toBST(nums,mid+1,r)
        return node

class Ssolution(object):
    def inorderTraversal(self, root):
        self.result = []
        self.inorder(root)
        return self.result

    def preorderTraversal(self, root):
        self.result = []
        self.preorder(root)
        return self.result

    def inorder(self,p):
        if p!=None:
            self.inorder(p.left) if p.left!=None else None
            self.result.append(p.val)
            self.inorder(p.right) if p.right!=None else None

    def preorder(self,p):
        if p!=None:
            self.result.append(p.val)
            self.preorder(p.left) if p.left!=None else None
            self.preorder(p.right) if p.right!=None else None

ss = Ssolution()
s = Solution()
root = s.sortedArrayToBST([1,2,3,5,8,9,15,30])
print(ss.inorderTraversal(root))
print(ss.preorderTraversal(root))


