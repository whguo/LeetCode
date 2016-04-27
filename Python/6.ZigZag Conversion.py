#字符串以Z字形摆放，按照每横行的顺序重新输出
class Solution(object):
    def convert(self, s, numRows):
        ls = len(s)
        if  numRows==1 or numRows >= ls or ls <= 1:
            return s
        L = ""
        for i in range(0,numRows):
            j = i
            down = (numRows-i)*2-2 if i!=numRows-1 else 0
            up = i*2 if i!=0 else 0
            L += s[j]
            j = j+down if down!=0 else j+up
            while j<ls and len(L)<ls:
                if up!= 0:
                    L += s[j]
                    j += up
                if len(L)>=ls:
                    break
                if down!=0 and j<ls:
                    L += s[j]
                    j += down


        return L

s = Solution()
l = s.convert("ABCDE",4)
print(l)
