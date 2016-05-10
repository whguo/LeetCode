#把一句话中的所以单词逆序
class Solution(object):
    def reverseWords(self, s):
        return " ".join(s.split()[::-1])

s = Solution()
print(s.reverseWords("the sky is blue "))
