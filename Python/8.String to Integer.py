#字符串转换为数字
import math
class Solution(object):
    def myAtoi(self, str):
        l = len(str)
        if l==0:
            return 0
        x=0
        flag = 1
        i = 0
        while str[i]==' ':
            i += 1
        if str[i]=='-':
            flag = -1
            i+=1
        elif str[i]=='+':
            flag = 1
            i+=1
        elif str[i]>='0' and str[i] <='9':
             x = 10*x+int(str[i])
             i+=1
        else:
            return 0
        while  i<l:
            if str[i]>='0' and str[i] <='9':
                x = 10*x+int(str[i])
                i += 1
            else:
                break
        x = x*flag
        if x>2147483647:
            return 2147483647
        elif x<-2147483648:
            return -2147483648
        return x

s = Solution()
print(s.myAtoi("      -11919730356x"))
