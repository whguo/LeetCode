#给定一个起始词和一个终结词，从起始词开始，每次变换一个字母，直到变为终结词，求出最小变换次数，过程中每次变换的结果必须在给定的词汇列表中
class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        length = 2
        words = set([beginWord])
        wordList.discard(beginWord)
        wordList.discard(endWord)

        while words:
            newwords = set()
            for word in words:
                for i in range(len(word)):
                    for c in "abcdefghijklmnopqrstuvwxyz":
                        new_word = word[:i] + c + word[i + 1:]
                        if new_word == endWord:
                            return length
                        if new_word in wordList:
                            newwords.add(new_word)
            words = newwords
            length += 1
            wordList -= words
        return 0

s = Solution()
print(s.ladderLength("hit","cog",{"hot","dot","dog","lot","log"}))
#wordList为set类型