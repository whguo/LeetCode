#寻找两个字符串，使得两字符串长度的乘积最大。
#要求两个字符串不能存在相同的字母。不存在返回0。
from functools import reduce
class Solution(object):
    #采用位操作，把单词转换成二进制数，a对应2的0次，b对应2的1次，以此类推。
    #比较两个单词是不是包含重复字母的时候，只需要用&运算看结果是否为0。
    def maxProduct(self, words):
        faker,res=[0]*len(words),0
        for i in range(len(faker)):
            faker[i]=reduce(lambda x,y:x|y,[1<<(ord(w)-97) for w in words[i]],0) #use bit to distinct diff char
        for i in range(len(faker)-1):
            for j in range(i+1,len(faker)):
                if faker[i]&faker[j]==0:
                    res=max(res,len(words[i])*len(words[j]))
        return res

    #蛮力法，超时
    def maxProduct1(self, words):
        words = sorted(words,key = lambda x:len(x),reverse = True)
        l , maxproduct = len(words) , 0
        setlist = [set(words[i]) for i in range(l)]
        lenlist = [len(words[i]) for i in range(l)]
        for i in range(l-1):
            for j in range(i+1,l):
                tmplen = lenlist[i]*lenlist[j]
                if (setlist[i]&setlist[j]==set()) and tmplen>maxproduct:
                    maxproduct = tmplen
                    break
        return maxproduct

s = Solution()
print(s.maxProduct(["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]))
