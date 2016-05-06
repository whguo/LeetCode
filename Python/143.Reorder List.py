#把一个链表重新排列顺序
#如：1,2,3,4改为1,4,2,3
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def reorderList(self, head):
        #用快慢指针把链表从中间分开
        if head==None:  return
        slow , fast = head , head.next
        if fast==None:  return head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        head2 = slow.next
        slow.next=None

        #把后边的链表翻转
        pre , cur = head2 , head2.next
        pre.next = None
        while cur:
            after = cur.next
            cur.next = pre
            pre = cur
            cur = after

        #把两个链结合起来
        cur = head
        while cur:
            tmp = cur.next
            cur.next = pre
            cur = tmp
            if pre:          #有奇数个情况下，第一个比第二个多一个数
                tmp = pre.next
                pre.next = cur
                pre = tmp

        return head



l1 = ListNode(1)
l2 = ListNode(2)
l3 = ListNode(3)
l4 = ListNode(4)
l5 = ListNode(5)
l6 = ListNode(6)
#l1.next = l2
#l2.next = l3
#l3.next = l4
#l4.next = l5
#l5.next = l6

s = Solution()
p = s.reorderList(l1)
while p:
    print(p.val)
    p = p.next