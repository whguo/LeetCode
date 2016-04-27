#列出所有匹配的n组括号
class Solution(object):
    def generateParenthesis(self, n):
        if n==0:
            return []
        elif n==1:
            return ['()']

        L = ['()']
        while n>1:
            T = []
            for l in L:
                for i in range(len(l)):
                    t = ''
                    t += l[0:i]
                    t += '()'
                    t += l[i:]
                    if not t in T:
                        T.append(t)
            L = T
            n -= 1
        return T

s = Solution()
print(s.generateParenthesis(3))
