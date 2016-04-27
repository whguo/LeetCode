#把两个链表数相加
class ListNode(object):
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        L1,L2,L3 = [],[],[]
        while l1 != None:
            L1.append(l1.val)
            l1 = l1.next
        while l2 != None:
            L2.append(l2.val)
            l2 = l2.next
        
        if len(L1)>=len(L2):
            L3 = L1
        else:
            L3 = L2
            L2 = L1
        flag = 0
        for i in range(len(L2)):
            tmp = L3[i]+L2[i]+flag
            L3[i] = tmp%10
            flag = int(tmp/10)

        if len(L3)!=len(L2):
            for i in range(len(L2),len(L3)):
                 tmp = L3[i]+flag
                 L3[i] = tmp%10
                 flag = int(tmp/10)
        if flag!=0:
            L3.append(flag)
        return L3

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
for i in range(len(L)-1):
     print('%d -> ' % L[i],end="")
print(L[-1])
