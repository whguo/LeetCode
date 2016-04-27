#通配符，'.'可代表所有字符，'*'可表示0或者n个
#没通过，处理某些字符串超时
class Solution(object):
    def isMatch(self, s, p):
        i,j = 0,0
        ls,lp = len(s),len(p)
        while i<ls and j<lp:
            if p[j]=='.':
                i += 1
                j += 1
            elif s[i]==p[j]:
                i += 1
                j += 1
            elif p[j]=='*':
                k = i-1
                while k<ls:
                    if j+1<lp and self.isMatch(s[k::],p[j+1::]):    #碰到*需要递归调用函数，看查找后面的串是否有匹配
                        break
                    k += 1
                if p[j-1]=='.':   #如果'#'前面是'.',那么只要在后边找到子串匹配即为匹配成功
                    if k==ls and j!=lp-1:
                        return False
                    else:
                        return True
                else: #如果'#'前面不是'.'，那么找到的匹配子串前面的字符必须与'*'前面的字符全都相同(表示*可以代表n个相同的字符)
                    k-=1
                    while k>=i and s[k]==s[i-1]:
                        k -= 1
                    if k==i-1:
                        return True
                    else:
                        return False
            else:
                if j+1<lp and p[j+1]=='*':  #如果二者不相等，且后边是*，那么跳过*
                    j += 2
                else:
                    return False
        if i==ls and j==lp:
            return True
        elif j<lp:
            if p[j]=='*':#解决这种匹配'a'和'a*a'
                while j<lp and p[j]=='*':
                    j+=2
                if (j == lp and p[j-1]==s[i-1]) or (j==lp+1):
                    return True
                else:
                    return False
            else: #解决这种匹配'a'和'ab*c*'
                j+=1
                while j<lp and p[j]=='*':
                    j+=2
                if j == lp+1:
                    return True
                else:
                    return False
        else:
            return False


s = Solution()
print(s.isMatch('aaaaaaaab','a*a*a*a*a*a*a*a*a*a*c'))
