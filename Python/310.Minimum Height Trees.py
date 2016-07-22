#对于一棵无向树，我们可以选择它的任意节点作为根。得到的结果就是有根树。
#在所有可能的有根树中，高度最小的称为最小高度树（MHT）。给定一个无向图，编写函数找出所有的最小高度树，并返回其根标号的列表。
#首先，最小高度树的根只可能是1个或2个。
#基本思路是“逐层删去叶子节点，直到剩下根节点为止”，有点类似于拓扑排序
class Solution(object):
    def findMinHeightTrees(self, n, edges):
        children = [set() for x in range(n)]
        for s, t in edges:
            children[s].add(t)
            children[t].add(s)
        leaves = [x for x in range(n) if len(children[x]) <= 1]
        while n > 2:
            n -= len(leaves)
            newLeaves = []
            for x in leaves:
                for y in children[x]:
                    children[y].remove(x)
                    if len(children[y]) == 1:
                        newLeaves.append(y)
            leaves = newLeaves
        return leaves

s = Solution()
print(s.findMinHeightTrees(6,[[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]))
