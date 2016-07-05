#判断一个字符串是否符合某种模式
#如：给出模式abbb,那么字符串"dog cat cat dog"满足，而"dog cat cat fish"不满足
class Solution(object):
    def wordPattern(self, pattern, str):
        slist = str.split(' ')
        slen , llen = len(pattern) , len(slist)
        if slen!=llen:  return False
        dic = {}
        for i in range(slen):
            if dic.get(pattern[i],-1)==-1:
                dic[pattern[i]] = slist[i]
            else:
                if dic[pattern[i]]!=slist[i]:   return False

        #反向确保是一一映射的
        if len(set(dic.values()))!=len(dic):    return False
        return True

s = Solution()
print(s.wordPattern("abba","dog cat cat dog"))
print(s.wordPattern("ab","dog dog"))
