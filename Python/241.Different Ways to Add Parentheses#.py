#给定一个运算式，求出在各个位置加括号能得到的所有运算结果
#Input: "2-1-1".
#((2-1)-1) = 0
#(2-(1-1)) = 2
#Output: [0, 2]
#思路：每碰到一个运算符，都可以两边分开计算，然后合并。
class Solution(object):
    #List生成器
    def diffWaysToCompute(self, input):
        return [a+b if c == '+' else a-b if c == '-' else a*b
            for i, c in enumerate(input) if c in '+-*'
            for a in self.diffWaysToCompute(input[:i])
            for b in self.diffWaysToCompute(input[i+1:])] or [int(input)]

    #分治法
    def diffWaysToCompute1(self, input):
        if input.isdigit():
            return [eval(input)]
        res = []
        for i, s in enumerate(input):
            if s in "+-*":
                l = self.diffWaysToCompute(input[:i])
                r = self.diffWaysToCompute(input[i+1:])
                res.extend(self.compute(l, r, s))
        return res

    def compute(self, l, r, op):
        return [eval(str(m)+op+str(n)) for m in l for n in r]

s = Solution()
print(s.diffWaysToCompute("2*3-4*5"))
