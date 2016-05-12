#比较两个版本号的大小
class Solution(object):
    def compareVersion(self, version1, version2):
        l1 , l2  = version1.split('.') , version2.split('.')
        i , L1 , L2 = 0 , len(l1) , len(l2)
        while i<L1 and i<L2:
            if int(l1[i])<int(l2[i]):
                return -1
            elif int(l1[i])>int(l2[i]):
                return 1
            i+=1
        if i>=L1:
            if i>=L2 or self.ifzero(l2[i::]):
                return 0
            else:
                return -1
        if i>=L2:
            if i>=L1 or self.ifzero(l1[i::]):
                return 0
            else:
                return 1

    def ifzero(self,l):
        for i in l:
            if int(i)!=0:
                return False
        return True

s = Solution()
print(s.compareVersion("3.00.1","3.0.2"))