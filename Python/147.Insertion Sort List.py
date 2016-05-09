#用插入排序给一个链表排序
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def insertionSortList(self, head):
        if not head: return head
        nHead = ListNode(0)
        nHead.next , pre , cur = head , head , head.next
        while cur:
            post = cur.next
            prev , curr = nHead , nHead.next
            while curr!=cur:
                if curr.val >= cur.val:
                    break
                prev = curr
                curr = curr.next
            if curr!=cur:
                prev.next = cur
                cur.next = curr
                pre.next = post
            else:
                pre = cur
            cur = post
        return nHead.next

l1 = ListNode(3)
l2 = ListNode(2)
l3 = ListNode(1)
l4 = ListNode(9)
l5 = ListNode(6)
l6 = ListNode(11)
l1.next = l2
l2.next = l3
l3.next = l4
l4.next = l5
l5.next = l6

s = Solution()
p = s.insertionSortList(l1)
while p:
    print(p.val)
    p = p.next