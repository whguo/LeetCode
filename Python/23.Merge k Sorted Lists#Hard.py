#合并k个有序链表:利用合并两个链表的函数即可
class ListNode(object):
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution(object):
    def mergeKLists(self, lists):
        l = len(lists)
        if l==0:
            return None
        elif l==1:
            return lists[0]

        L = self.mergeTwoLists(lists[0],list[1])
        i = 2
        while i<l:
            L = self.mergeTwoLists(lists[i],L)
            i+=1
        return L


    def mergeTwoLists(self, l1, l2):
        nHead = ListNode(0)
        p = nHead
        while l1 or l2:
            if l1==None or (l2!=None and l1.val>=l2.val):
                q = ListNode(l2.val)
                p.next = q
                p = p.next
                l2 = l2.next
                continue
            if l2==None or (l1!=None and l1.val<l2.val):
                q = ListNode(l1.val)
                p.next = q
                p = p.next
                l1 = l1.next
                continue
        return nHead.next
