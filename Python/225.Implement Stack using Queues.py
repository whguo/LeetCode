#完成一个堆栈类
class Stack(object):
    def __init__(self):
        self.queue = []

    def push(self, x):
        self.queue.append(x)

    def pop(self):
        if self.queue!=[]:
            self.queue.pop()

    def top(self):
            return self.queue[-1] if self.queue!=[] else None

    def empty(self):
        return self.queue==[]

