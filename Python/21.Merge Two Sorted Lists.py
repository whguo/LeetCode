#合并两个有序数字链表
class ListNode(object):
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        nHead = ListNode(0)
        p = nHead
        while l1 or l2:
            if l1==None or (l2!=None and l1.val>=l2.val):
                q = ListNode(l2.val)
                p.next = q
                p = p.next
                l2 = l2.next
                continue
            if l2==None or (l1!=None and l1.val<l2.val):
                q = ListNode(l1.val)
                p.next = q
                p = p.next
                l1 = l1.next
                continue
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
l = None
ll = ListNode(0)

s = Solution()
p = s.mergeTwoLists(ll,l)
while p:
    print('%d ->' % p.val,end='')
    p = p.next
