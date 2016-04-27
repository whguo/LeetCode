#有序链表中的数字重复的结点全部删除
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        if head==None:
            return head
        nHead = ListNode(0)
        nHead.next = head
        p , q = nHead , head
        while q.next!=None:
            if q.val == q.next.val:
                while q.next!=None and q.val == q.next.val:
                    q = q.next
                q = q.next
                p.next = q
                if q==None:
                    return nHead.next

            else:
                q = q.next
                p = p.next
        return nHead.next



l1 = ListNode(1)
l2 = ListNode(1)
l3 = ListNode(2)
l4 = ListNode(2)
l1.next = l2
l2.next = l3
l3.next = l4


s = Solution()
p = s.deleteDuplicates(l1)
while p!=None:
    print(p.val)
    p = p.next