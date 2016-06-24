#计算字符串运算式子的值，包含加减乘除运算还有空格
class Solution(object):
    def calculate(self, s):
        num , oper , stack , l = 0 , '+' , [0] , len(s)-1
        #除法不能用//，负数除会出错
        operdic = {'+': lambda x,y:y , '-':lambda x,y:-y , '*':lambda x,y:x*y , '/':lambda x,y:(int)(float(x)/float(y))}
        for i,ch in enumerate(s):
            if ch.isdigit():
                num = num*10 + int(ch)
            if not ch.isdigit() and ch!=' ' or i==l:
                prev = 0 if oper in '+-' else stack.pop()
                stack.append(operdic[oper](prev,num))
                num , oper = 0 , ch
        return sum(stack)

s = Solution()
print(s.calculate("14-3/2"))
