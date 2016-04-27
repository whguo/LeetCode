class ListNode(object):
     def __init__(self, x):
         self.val = x
         self.next = None
         
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        nHead, flag = ListNode(0), 0
        head = nHead
        while flag or l1 or l2:     #从低位到高位，每次建立一个新结点，把flag和两个链的值同等看待
            node = ListNode(flag)
            if l1: 
                node.val += l1.val
                l1 = l1.next
            if l2: 
                node.val += l2.val
                l2 = l2.next
            flag = node.val // 10
            node.val %= 10
            head.next, head = node, node
        return nHead.next


l1 = ListNode(2)
l2 = ListNode(4)
l3 = ListNode(3)
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
l9.next = l10
l11 = ListNode(1)

s = Solution()
L = s.addTwoNumbers(l1,l4)
while L.next:
     print('%d -> ' % L.val,end="")
     L = L.next
print(L.val)
