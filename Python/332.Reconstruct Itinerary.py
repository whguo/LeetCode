#给出一系列飞机票，从JFK开始，返回航班串
#如果有多种合法的串，则返回字母序列小的，如：LGA比LGB小
class Solution(object):

    #错误，因为这样做所有票不一定都被使用，即结果长度不够。但是字典建立是对的。
    def findItinerary1(self, tickets):
        dic , result = {} , ['JFK']
        for ticket in tickets:
            if dic.get(ticket[0],-1)==-1:
                dic[ticket[0]]=[ticket[1]]
            else:
                i = 0
                while i<len(dic[ticket[0]]) and ticket[1]>dic[ticket[0]][i]:
                    i+=1
                dic[ticket[0]].insert(i,ticket[1])
        while dic.get(result[-1],-1)!=-1 and dic[result[-1]]!=[]:
            result.append(dic[result[-1]].pop(0))
        return result

    #要求所有票都使用，那么结果长度必为len(tickets)+1，使用dfs
    def findItinerary(self, tickets):
        self.dic , self.l = {} , len(tickets)+1
        self.result = ['JFK']
        for ticket in tickets:
            if self.dic.get(ticket[0],-1)==-1:
                self.dic[ticket[0]]=[ticket[1]]
            else:
                i = 0
                while i<len(self.dic[ticket[0]]) and ticket[1]>self.dic[ticket[0]][i]:
                    i+=1
                self.dic[ticket[0]].insert(i,ticket[1])
        print(self.dic)
        self.dfs('JFK')
        return self.result


    def dfs(self,cur):
        if len(self.result) == self.l:   return True
        if self.dic.get(cur,-1)==-1:    return False
        for i,des in enumerate(self.dic[cur]):
            self.result.append(des)
            tmp = self.dic[cur].pop(i)
            if self.dfs(des)==True: return True
            self.result.pop()
            self.dic[cur].insert(i,tmp)
        return False

s = Solution()
print(s.findItinerary([["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]]))

