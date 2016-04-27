#把链表按照给定数分为两部分，小于它的和大于等于它的，然后按照原顺序排列起来
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def partition(self, head, x):
        Lower , Greater = ListNode(0) , ListNode(0)
        p , l , g = head , Lower , Greater
        while p!=None:
            q , p = p , p.next
            q.next = None
            if q.val < x:
                l.next = q
                l = q
            else:
                g.next = q
                g = q
        l.next = Greater.next
        return Lower.next


l1 = ListNode(1)
l2 = ListNode(4)
l3 = ListNode(3)
l4 = ListNode(2)
l5 = ListNode(5)
l6 = ListNode(2)
l1.next = l2
l2.next = l3
l3.next = l4
l4.next = l5
l5.next = l6


s = Solution()
p = s.partition(l1,3)
while p!=None:
    print(p.val)
    p = p.next