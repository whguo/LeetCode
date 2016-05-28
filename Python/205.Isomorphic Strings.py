#判断两个字符串是否可以“对应”,一个字符串里的字母对应另外一个字符串里的字母
#两个不同字母不能对应同一个，但是自己可以和自己对应

#思路：用两个字典，正反对应
class Solution(object):
    def isIsomorphic(self, s, t):
        lens , lent = len(s) , len(t)
        if lens!=lent:  return False
        dic , redic = {} , {}
        for i in range(lens):
            if dic.get(s[i],-1)==-1:
                dic[s[i]] = t[i]
            if redic.get(t[i],-1)==-1:
                redic[t[i]] = s[i]
            if dic[s[i]]!=t[i] or redic[t[i]]!=s[i]:
                return False
        return True

s = Solution()
print(s.isIsomorphic("ab","ba"))
