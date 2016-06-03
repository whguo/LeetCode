#写出字典树(小写字母单词)的插入查找和以某字符串开头的单词函数
class TrieNode(object):
    def __init__(self):
        self.isStr = False
        self.next = {}

class Trie(object):
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        p = self.root
        for w in word:
            if(p.next.get(w,-1)==-1):
                trie = TrieNode()
                p.next[w] = trie
            p = p.next[w]
        p.isStr = True


    def search(self, word):
        p = self.root
        for w in word:
            if(p.next.get(w,-1)==-1):
                return False
            p = p.next[w]
        return p.isStr

    def startsWith(self, prefix):
        if prefix=="":  return False
        p = self.root
        for w in prefix:
            if(p.next.get(w,-1)==-1):
                return False
            p = p.next[w]
        return (not p.next=={} or p.isStr)


trie = Trie()
trie.insert("somestring")
trie.insert("a")
print(trie.search("somestring"))
print(trie.startsWith("somestring"))
print(trie.startsWith("a"))