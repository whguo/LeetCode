def reverseBetween(self, head, m, n):
        prem, pre, next, now, nowm = None, None, None, head, None;
        ind = 1;
        while now is not None:
            next = now.next
            if ind >= m and ind <= n:
                now.next = pre
            if ind == m:
                prem, nowm = pre, now
            if ind == n:
                nowm.next = next
                if prem is None:
                    head = now
                else:
                    prem.next = now
            pre, now, ind = now, next, ind + 1
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
p = s.reverseBetween(l1,1,6)
while p!=None:
    print(p.val)
    p = p.next