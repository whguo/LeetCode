#判断一个数是否是4的次方
#先把不是2的次方的排除掉：num&(num-1)
class Solution(object):
    def isPowerOfFour(self, num):
        return num & (num-1)==0 and num & 0x55555555 != 0

s = Solution()
print(s.isPowerOfFour(8))

