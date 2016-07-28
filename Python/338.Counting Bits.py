#给一个正整数num，对于每一个i满足0<=i<=num，计算每一个i的二进制位共有多少个1，并按数组返回。
#如num=5,返回[0,1,1,2,1,2]
class Solution(object):
    def countBits(self, num):
        result = []
        for i in range(num+1):
            tmp = 0
            while i!=0:
                tmp += i & 1
                i = i>>1
            result += [tmp]
        return result


s = Solution()
print(s.countBits(5))

