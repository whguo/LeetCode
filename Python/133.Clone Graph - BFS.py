#克隆一个无向图
class UndirectedGraphNode(object):
    def __init__(self, x):
        self.label = x
        self.neighbors = []

class Solution(object):
    def cloneGraph(self, node):
        if node==None:
            return None
        queue , dic = [] , {}
        queue.append(node)
        newnode = UndirectedGraphNode(node.label)
        dic[node] = newnode
        while queue:
            print(queue[0].label)
            p = queue.pop(0)
            for n in p.neighbors:
                if n in dic:
                    dic[p].neighbors.append(dic[n])
                else:
                    nclone = UndirectedGraphNode(n.label)
                    dic[p].neighbors.append(nclone)
                    dic[n] = nclone
                    queue.append(n)
        return newnode


n1 = UndirectedGraphNode(0)
n2 = UndirectedGraphNode(1)
n3 = UndirectedGraphNode(2)
n1.neighbors = [n2,n3]
n2.neighbors = [n3]
n3.neighbors = [n3]

s = Solution()
r = s.cloneGraph(n1)
print(r.label,r.neighbors[1].neighbors[0].label)