#对给定数字，每个位求和，直到结果为一位数
class Solution(object):
    #不循环的做法：使用数字根公式
    def addDigits(self, num):
        return num-9*((num-1)//9) if num!=0 else 0

    #循环的做法
    def addDigits1(self, num):
        while num>9:
            num = sum([int(x) for x in str(num)])
        return num

s = Solution()
print(s.addDigits(38))
