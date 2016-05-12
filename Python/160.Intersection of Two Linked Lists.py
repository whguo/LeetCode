#寻找两个链表的交汇节点，时间O(n).空间O(1)。
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        if headA==None or headB==None: return None
        la , ha = 1 , headA
        while ha.next:
            la += 1
            ha = ha.next
        lb , hb = 1 , headB
        while hb.next:
            lb += 1
            hb = hb.next
        if ha != hb:    return None
        ha , hb = headA , headB
        if la>lb:
            i = la-lb
            while i>0:
                ha , i = ha.next , i-1
        else:
            i = lb-la
            while i>0:
                hb , i = hb.next , i-1
        while ha!=hb:
            ha , hb = ha.next , hb.next
        return ha

l1 = ListNode(1)
l2 = ListNode(2)
l3 = ListNode(3)
l4 = ListNode(4)
l5 = ListNode(5)
l6 = ListNode(6)
l7 = ListNode(7)
l8 = ListNode(8)
l1.next = l2
l2.next = l8
l3.next = l4
l4.next = l5
l5.next = l6
l6.next = l7
l7.next = l8

s = Solution()
print(s.getIntersectionNode(l1,l3).val)