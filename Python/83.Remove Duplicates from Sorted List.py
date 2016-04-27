#有序链表中的数字重复的结点只保留一个
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        if head==None:
            return head
        p = head
        while p.next!=None:
            if p.val == p.next.val:
                p.next = p.next.next
            else:
                p = p.next
        return head



l1 = ListNode(1)
l2 = ListNode(1)
l3 = ListNode(2)
l1.next = l2
l2.next = l3

l4 = ListNode(5)
l5 = ListNode(6)
l6 = ListNode(4)
l4.next = l5
l5.next = l6

l7 = ListNode(5)
l8 = ListNode(5)

l9 = ListNode(9)
l10 = ListNode(9)

s = Solution()
p = s.deleteDuplicates(l1)
while p!=None:
    print(p.val)
    p = p.next