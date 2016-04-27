#列出数字对应9按键键盘字母的所有组合
class Solution(object):
    def letterCombinations(self, digits):
        dic = {'1':'','2':'abc','3':'def','4':'ghi','5':'jkl',
               '6':'mno','7':'pqrs','8':'tuv','9':'wxyz','0':' '}
        l = len(digits)
        if l==0:
            return []
        L = [m for m in dic[digits[0]]]
        for i in range(1,l):
            L = [m+n for m in L for n in dic[digits[i]]]
        return L


s = Solution()
print(s. letterCombinations("123"))
