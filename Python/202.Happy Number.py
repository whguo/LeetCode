#Happy Number
#一直循环做：把数的各个位数求平方和。直到结果为1，就是Happy Number。
class Solution(object):
    def isHappy(self, n):
        dic = {}
        while n!=1 and (dic.get(n,-1))==-1:
            dic[n] = 1
            l = [int(x) for x in str(n)]
            n = sum(map(self.square,l))
        if n==1:
            return True
        else:
            return False

    def square(self,x):
        return x*x


s = Solution()
print(s.isHappy(21))