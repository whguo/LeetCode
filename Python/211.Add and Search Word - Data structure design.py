#自己设计数据结构，能够插入和查找字符串。
#支持'.'通配符，代表任意一个字符。（所有单词均为小写字母）
class TrieNode(object):
    def __init__(self):
        self.isStr = False
        self.next = {}

class WordDictionary(object):
    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word):
        p = self.root
        for w in word:
            if(p.next.get(w,-1)==-1):
                trie = TrieNode()
                p.next[w] = trie
            p = p.next[w]
        p.isStr = True

    def search(self, word):
        return self.searchTrie(word,self.root)

    def searchTrie(self,word,p):
        if word[0]=='.':
            if word[1::]=="":
                for key,value in p.next.items():
                    if value.isStr==True:   return True
                return False
            for key,value in p.next.items():
                if self.searchTrie(word[1::],value):
                    return True
            return False
        else:
            if(p.next.get(word[0],-1)==-1):
                return False
            return p.next[word[0]].isStr if word[1::]=="" else self.searchTrie(word[1::],p.next[word[0]])

wordDictionary = WordDictionary()
wordDictionary.addWord("word")
print(wordDictionary.search("w."))