#把链表逆序
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
class Solution(object):
    def reverseList(self, head):
        if head==None:  return None
        pre , cur = head , head.next
        pre.next = None
        while cur:
            post = cur.next
            cur.next = pre
            pre = cur
            cur = post
        return pre



l1 = ListNode(1)
l2 = ListNode(2)
l3 = ListNode(6)
l4 = ListNode(3)
l5 = ListNode(5)
l6 = ListNode(4)
l7 = ListNode(7)
l1.next = l2
l2.next = l3
l3.next = l4
l4.next = l5
l5.next = l6
l6.next = l7

s = Solution()
p = s.reverseList(l1)
while p:
    print(p.val)
    p = p.next