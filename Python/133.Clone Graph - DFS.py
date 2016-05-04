#克隆一个无向图
class UndirectedGraphNode(object):
    def __init__(self, x):
        self.label = x
        self.neighbors = []

class Solution(object):
    def cloneGraph(self, node):
        if node == None: return None
        return self.dfs(node,{})

    def dfs(self,input,map):
        if input in map:
            return map[input]
        output = UndirectedGraphNode(input.label)
        map[input] = output
        for neighbor in input.neighbors:
            output.neighbors.append(self.dfs(neighbor,map))
        return output



n1 = UndirectedGraphNode(0)
n2 = UndirectedGraphNode(1)
n3 = UndirectedGraphNode(2)
n1.neighbors = [n2,n3]
n2.neighbors = [n3]
n3.neighbors = [n3]

s = Solution()
r = s.cloneGraph(n1)
print(r.label,r.neighbors[1].neighbors[0].label)