#返回数字对应的字母串,1->A..26->Z...27->AA,28->AB...
class Solution(object):
    def convertToTitle(self, n):
        res = ''
        while n > 0:
            tmp = n
            n = (tmp-1)//26
            res += chr(65+(tmp-1)%26)
        return res[::-1]

s = Solution()
print(s.convertToTitle(128))