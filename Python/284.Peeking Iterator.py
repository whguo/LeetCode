#实现队列头迭代器，能够判断队列是否有下一个，返回下一个数，返回并弹出下一个数(只能利用已知迭代器的函数)
class PeekingIterator(object):
    def __init__(self, iterator):
        self.iterator = iterator
        self.nnext = self.iterator.next() if self.iterator.hasNext() else None

    def peek(self):
        return self.nnext

    def next(self):
        result = self.nnext
        self.nnext = self.iterator.next() if self.iterator.hasNext() else None
        return result

    def hasNext(self):
        return self.nnext!=None


