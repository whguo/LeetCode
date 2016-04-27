#把链表中第n到第m个位置之间逆序
class ListNode(object):
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution(object):
    def reverseBetween(self, head, m, n):
        nHead = ListNode(0)
        nHead.next = head
        i , p , q = 0 , nHead , head
        while i<m-1 and q!=None:
            i , p  ,q = i+1 , p.next , q.next
        mm , p = p , q
        q = p.next
        while i<n-1:
            if q!=None:
                t = q.next
            q.next = p
            i , p , q = i+1 , q , t
        nn = mm.next
        nn.next = q
        mm.next = p
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

s = Solution()
p = s.reverseBetween(l1,1,6)
while p!=None:
    print(p.val)
    p = p.next
