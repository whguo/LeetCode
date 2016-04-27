#返回一个数加一后的值(数可以任意大)
class Solution(object):
    def plusOne(self, digits):
        l = len(digits)
        if l==0:
            return []
        i = l-1
        flag = (digits[i]+1)//10
        digits[i] = (digits[i]+1)%10
        i = i-1
        while i>=0 and flag!=0:
            flag = (digits[i]+1)//10
            digits[i] = (digits[i]+1)%10
            i-=1
        if flag!=0:
            digits.insert(0,1)
        return digits

s = Solution()
print(s.plusOne([9,9,9,9]))