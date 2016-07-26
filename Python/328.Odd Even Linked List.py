#把链表重新排序，奇数节点放在一起，偶数节点放在一起(链表号奇偶数，不是链表中的数)
#eg：1->2->3->4->5->NULL，返回1->3->5->2->4->NULL
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def oddEvenList(self, head):
        if head==None or head.next==None:  return head
        l2 , i =  head.next , 0
        p , cu1 , cu2 = l2.next , head , l2
        while p:
            if i==0:
                cu1.next , p , i = p , p.next , 1
                cu1 = cu1.next
            else:
                cu2.next , p , i = p , p.next , 0
                cu2 = cu2.next
        cu1.next = l2
        cu2.next = None
        return head

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


s = Solution()
p = s.oddEvenList(l1)
while p:
    print(p.val)
    p = p.next
