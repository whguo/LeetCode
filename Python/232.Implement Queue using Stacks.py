#用栈实现一个队列
class Queue(object):
    def __init__(self):
        self.stack = []

    def push(self, x):
        self.stack.append(x)

    def pop(self):
        if self.stack!=[]:
            self.stack.pop(0)

    def peek(self):
        if self.stack!=[]:
            return self.stack[0]

    def empty(self):
        return self.stack==[]
