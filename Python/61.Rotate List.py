#链表循环右移k个位置
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        if head==None:
            return None
        if k==0:
            return head
        nHead = ListNode(0)
        nHead.next , p , n = head , head , 1
        while p.next!=None:
            p = p.next
            n = n+1
        p.next = head
        i = n-k%n
        p = p.next
        while i>1:
            p = p.next
            i-=1
        nHead.next = p.next
        p.next = None
        return nHead.next

l1 = ListNode(1)
l2 = ListNode(2)
l3 = ListNode(3)
l4 = ListNode(4)
l5 = ListNode(5)
l6 = ListNode(6)
l1.next = l2
l2.next = l3
l3.next = l4
l4.next = l5
l5.next = l6
l8 = ListNode(8)

s = Solution()
p = s.rotateRight(None,0)
while p:
    print(p.val)
    p = p.next




