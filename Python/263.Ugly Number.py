#判断一个数是否是Ugly Number，定义为因数只包含2,3,5的。
#特殊的，1是Ugly Number。
class Solution(object):
    def isUgly(self, num):
        if num==0:  return False
        if num==1:  return True
        while num%2==0:     num = num//2
        while num%3==0:     num = num//3
        while num%5==0:     num = num//5
        return num==1

s = Solution()
print(s.isUgly(14))
