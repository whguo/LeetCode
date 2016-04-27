#将字母相同的字符串归类，而且同一类的按照字母顺序排列
class Solution(object):
    def groupAnagrams(self, strs):
        dic , i , result = {} , 0 , []
        for st in strs:
            tmp = str(sorted(st))
            re = dic.get(tmp,-1)
            if re == -1:
                dic[tmp] = i
                result.append([st])
                i+=1
            else:
                result[re].append(st)
        rrr = []
        for l in result:
            a = sorted(l)
            rrr.append(a)
        return rrr


s = Solution()
print(s.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))

