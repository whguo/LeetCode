#根据排序链表生成一个平衡二叉排序树
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def sortedListToBST(self, head):
        nums , p = [] , head
        while p!=None:
            nums.append(p.val)
            p = p.next
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

l1 = ListNode(1)
l2 = ListNode(2)
l3 = ListNode(3)
l4 = ListNode(5)
l5 = ListNode(8)
l6 = ListNode(9)
l7 = ListNode(15)
l8 = ListNode(30)
l1.next = l2
l2.next = l3
l3.next = l4
l4.next = l5
l5.next = l6
l6.next = l7
l7.next = l8



ss = Ssolution()
s = Solution()
root = s.sortedListToBST(l1)
print(ss.inorderTraversal(root))
print(ss.preorderTraversal(root))


