#找到一堆版本中第一个出错的版本,(第一个出错后边都错)
#二分法
class Solution(object):
    def firstBadVersion(self, n):
        l , r = 0 , n
        while l<=r:
            mid = (l+r)//2
            if self.isBadVersion(mid):  r = mid-1
            else:   l = mid+1
        return l

    def isBadVersion(self,version):
        return version>3

s = Solution()
print(s.firstBadVersion(6))
