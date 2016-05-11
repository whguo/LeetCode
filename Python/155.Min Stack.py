#实现一个堆栈，能够返回栈中最小值
class MinStack(object):
    def __init__(self):
        self.stack = []
        self.first = 0

    def push(self, x):
        self.stack.append(x)
        if self.first==0:
            self.minStack = x
            self.first = 1
        else:
            self.minStack = min(self.minStack,x)

    def pop(self):
        if len(self.stack)==0:return
        self.stack.pop()
        if self.stack ==[]:
            self.first = 0
        else:
            self.minStack = min(self.stack)

    def top(self):
        return self.stack[-1]

    def getMin(self):
        return self.minStack

st = MinStack()
st.push(-2)
st.push(0)
st.push(-3)
print(st.getMin())
st.pop()
print(st.top())
print(st.getMin())