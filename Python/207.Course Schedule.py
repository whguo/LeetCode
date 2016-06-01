#给出课程个数与课程的先修关系，返回是否能完成所有课程。
#先修关系[1,0]表示修课程1前必须先修课程0
class Solution(object):

    #做一个子节点list
    def canFinish(self, numCourses, prerequisites):
        degrees = [0] * numCourses
        childs = [[] for x in range(numCourses)]
        for pair in prerequisites:
            degrees[pair[0]] += 1
            childs[pair[1]].append(pair[0])
        courses = set(range(numCourses))
        flag = True
        while flag and len(courses):
            flag = False
            removeList = []
            for x in courses:
                if degrees[x] == 0:
                    for child in childs[x]:
                        degrees[child] -= 1
                    removeList.append(x)
                    flag = True
            for x in removeList:
                courses.remove(x)
        return len(courses) == 0

    #用队列，2000个课程时超时
    def canFinish1(self, numCourses, prerequisites):
        innum = [0] * numCourses
        for pre in prerequisites:
            innum[pre[0]] += 1
        queue = []
        for i in range(numCourses):
            if innum[i]==0:     queue.append(i)
        while queue:
            top ,i  = queue.pop(0) , 0
            while i<len(prerequisites):
                if prerequisites[i][1] == top:
                    innum[prerequisites[i][0]] -= 1
                    if innum[prerequisites[i][0]] == 0:     queue.append(prerequisites[i][0])
                    prerequisites.remove(prerequisites[i])
                    i -= 1
                i += 1
        if innum== [0] * numCourses:
            return True
        else:
            return False

s = Solution()
print(s.canFinish(6,[[1,0],[3,2],[4,1],[4,3],[5,4]]))
