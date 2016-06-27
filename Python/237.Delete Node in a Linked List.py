#给定一个访问节点的路径，写一个函数去删除在一个单向链表中除尾部以外的节点。
#假设这个链表是1 -> 2 -> 3 -> 4，并且你被给予了第3个值为3的节点，那么在调用你的函数之后这个链表应该变为1 -> 2 -> 4。
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def deleteNode(self, node):
        node.val = node.next.val
        node.next = node.next.next

