#判断一个单链表的数字是否是回文的
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def isPalindrome(self, head):
        stack = []
        while head:
            stack.append(head.val)
            head = head.next
        return stack==stack[::-1]