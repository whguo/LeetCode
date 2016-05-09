#用插入排序给一个链表排序
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def insertionSortList(self, head):
        if not head:
            return head
        dummy = ListNode(0)                         #为链表加一个头节点
        dummy.next = head
        curr = head
        while curr.next:
            if curr.next.val < curr.val:            #如果链表是升序的，那么curr指针一直往后移动
                pre = dummy                         #直到一个节点的值小于前面节点的值
                while pre.next.val < curr.next.val: #然后寻找插入的位置
                    pre = pre.next
                tmp = curr.next
                curr.next = tmp.next
                tmp.next = pre.next
                pre.next = tmp
            else:
                curr = curr.next
        return dummy.next

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