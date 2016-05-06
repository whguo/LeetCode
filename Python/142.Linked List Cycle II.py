#判断一个链表是否有环
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def hasCycle(self, head):
        dic = {}
        while head:
            if dic.get(head,False)==False:
                dic[head] = 1
            else:
                return head
            head = head.next
        return None


l1 = ListNode(1)
l2 = ListNode(2)
l3 = ListNode(3)
l4 = ListNode(4)
l5 = ListNode(5)
l6 = ListNode(6)
l1.next = l2
l2.next = l3
l3.next = l4
l4.next = l5
l5.next = l6
l6.next = l2

s = Solution()
print(s.hasCycle(l1).val)