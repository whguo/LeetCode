#删掉链表中倒数第n个元素
class ListNode(object):
    def __init__(self,x):
        self.val = x
        self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        dic = {}
        p , i = head , 0
        while p:
            dic[i] = p
            i = i+1
            p = p.next
        if i == 1:
            return None
        if i-n>0:
            p = dic[i-n-1]
            q = dic[i-n]
            p.next = q.next
        elif i-n==0:
            return head.next
        return head

l1 = ListNode(1)
l2 = ListNode(2)
l3 = ListNode(3)
l4 = ListNode(4)
l5 = ListNode(5)
l1.next = l2
l2.next = l3
l3.next = l4
l4.next = l5
s = Solution()
p = s.removeNthFromEnd(l1,2)
while p:
    print(p.val)
    p = p.next
