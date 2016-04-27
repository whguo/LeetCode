#返回一个数加一后的值(数可以任意大)
class Solution(object):
    def addBinary(self, a, b):
        l1 , l2 ,flag = len(a)-1 , len(b)-1 , 0
        result  = ''
        while l1>=0 or l2>=0 or flag!=0:
            sum = 0
            if l1>=0:
                sum += int(a[l1])
            if l2>=0:
                sum += int(b[l2])
            sum += flag
            flag = sum//2
            result += str(sum%2)
            l1 , l2 = l1-1 , l2-1
        return result[::-1]

s = Solution()
print(s.addBinary('11','1'))