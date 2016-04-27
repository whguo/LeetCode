#罗马数字转换成数字
class Solution(object):
    def intToRoman(self, str):
        roval = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        num , l ,i = 0 ,len(str), 0
        while i<l:
            if i+1<l and roval[str[i]]<roval[str[i+1]]:
                num = num - roval[str[i]]
            else:
                num +=  roval[str[i]]
            i+=1
        return num

s = Solution()
print(s.intToRoman('DCXXI'))
