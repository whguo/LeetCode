#给出课程个数与课程的先修关系，返回一个完成所有课程的顺序。
#没有的返回空
class Solution(object):
    def findOrder(self, numCourses, prerequisites):
        degrees = [0] * numCourses
        childs = [[] for x in range(numCourses)]
        for pair in prerequisites:
            degrees[pair[0]] += 1
            childs[pair[1]].append(pair[0])
        courses = set(range(numCourses))
        flag , result = True , []
        while flag and len(courses):
            flag = False
            removeList = []
            for x in courses:
                if degrees[x] == 0:
                    for child in childs[x]:
                        degrees[child] -= 1
                    removeList.append(x)
                    result.append(x)
                    flag = True
            for x in removeList:
                courses.remove(x)
        return result if len(courses) == 0 else []

s = Solution()
print(s.findOrder(6,[[1,0],[3,2],[4,1],[4,3],[5,4]]))