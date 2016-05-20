#求出长度为10的重复DNA串
class Solution(object):
    def findRepeatedDnaSequences(self, s):
        l = len(s)
        if l<10:    return []
        result , dic = [] , {}
        for i in range(0,l-9):
            tmp = s[i:i+10]
            if dic.get(tmp,-1)==-1:
                dic[tmp] = 1
            elif dic.get(tmp)==1:
                result.append(tmp)
                dic[tmp] = 2
        return result

s = Solution()
print(s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"))