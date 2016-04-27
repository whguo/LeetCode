#把链表中的两个两个节点互相交换(不能直接换数字)
#如1->2->3->4变为2->1->4->3
class ListNode(object):
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution(object):
    def swapPairs(self, head):
        nHead = ListNode(0)
        nHead.next = head
        p = nHead
        q = nHead.next
        while q:
            t = q.next
            if t:
                p.next = t
                q.next = t.next
                t.next = q
            p = p.next.next
            q = q.next
        return nHead.next

l1 = ListNode(1)
l2 = ListNode(2)
l3 = ListNode(3)
l4 = ListNode(4)
l5 = ListNode(5)
l1.next = l2
l2.next = l3
l3.next = l4
l4.next = l5
s = Solution()
p = s.swapPairs(l1)
while p:
    print(p.val)
    p = p.next
