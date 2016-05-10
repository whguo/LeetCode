#计算逆波兰表达式值,有效运算符为+-*/
class Solution(object):
    def evalRPN(self, tokens):
        stack = []
        for ch in tokens:
            if ch=="+":
                a = stack.pop()
                b = stack.pop()
                stack.append(a+b)
            elif ch=="-":
                a = stack.pop()
                b = stack.pop()
                stack.append(b-a)
            elif ch=="*":
                a = stack.pop()
                b = stack.pop()
                stack.append(a*b)
            elif ch=="/":
                a = stack.pop()
                b = stack.pop()
                flag = 1
                if a<0:
                    a = -a
                    flag = flag * -1
                if b<0:
                    b = -b
                    flag = flag * -1
                stack.append(flag*int(b/a))        #6/-132结果为-1，而答案要求0，所以"//"操作符不好使
            else:
                stack.append(int(ch))
        return stack[0]

s = Solution()
print(s.evalRPN(["10","6","9","3","+","-11","*","/","*","17","+","5","+"]))
