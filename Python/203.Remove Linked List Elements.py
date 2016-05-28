#删除链表中的给定数字节点
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def removeElements(self, head, val):
        nHead = ListNode(0)
        nHead.next = head
        head = nHead
        while  head.next:
            if head.next.val == val:
                head.next = head.next.next
            else:
                head = head.next
        return nHead.next

l1 = ListNode(6)
l2 = ListNode(2)
l3 = ListNode(6)
l4 = ListNode(3)
l5 = ListNode(5)
l6 = ListNode(4)
l7 = ListNode(6)
l1.next = l2
l2.next = l3
l3.next = l4
l4.next = l5
l5.next = l6
l6.next = l7

s = Solution()
p = s.removeElements(l1,6)
while p:
    print(p.val)
    p = p.next