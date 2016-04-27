#一串序列，按照读法一直往下顺延，如下：
# 1, 11, 21, 1211, 111221, 312211, 13112221, 1113213211, 31131211131221 ...
# 1 is read off as "one 1" or 11.
# 11 is read off as "two 1s" or 21.
# 21 is read off as "one 2, then one 1" or 1211.

class Solution(object):
    def countAndSay(self, n):
        string = '1'
        while n>1:
            l , tmp = len(string) , ''
            i =  0
            while i<l:
                m = 1
                while i+1<l and string[i]==string[i+1]:
                    m+=1
                    i+=1
                tmp += str(m)
                tmp += string[i]
                i+=1
            string = tmp
            n-=1
        return string

s = Solution()
print(s.countAndSay(9))
