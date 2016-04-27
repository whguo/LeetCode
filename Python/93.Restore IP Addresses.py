#返回数字字符串所有可能的IP地址
class Solution(object):
    def restoreIpAddresses(self, s):
        i , result = 1 , []
        while i<=3:
            if len(s[i::])>9 or len(s[i::])<3 or int(s[0:i])>255:   #剪枝
                i+=1
                continue
            s = s[0:i]+"."+s[i::]
            for j in range(1,4):
                if len(s[i+j+1::])>6 or len(s[i+j+1::])<2 or int(s[i+1:i+j+1])>255:
                    continue
                s = s[0:i+j+1]+"."+s[i+j+1::]
                for k in range(1,4):
                    if len(s[i+j+k+2::])>3 or len(s[i+j+k+2::])<1 or int(s[i+j+2:i+j+k+2])>255 or int(s[i+j+k+2::])>255:
                        continue
                    s = s[0:i+j+k+2]+"."+s[i+j+k+2::]
                    print(s)
                    result.append(s)
                    tmp = s.split('.')
                    for st in tmp:
                        if st[0]=='0' and len(st)>1:
                            result.pop()
                            break
                    s = s[0:i+j+k+2]+s[i+j+k+3::]
                s = s[0:i+j+1]+s[i+j+2::]
            s = s[0:i]+s[i+1::]
            i += 1
        return result


s = Solution()
print(s.restoreIpAddresses("172162541"))

