#合并两个有序数组(把数组2合到1里)
#最好从后往前插入
class Solution(object):
    def merge(self, nums1, m, nums2, n):
        i,j = 0,0
        while j<n:
            while i<m+j and nums1[i]<nums2[j]:
                i+=1
            nums1[i+1::]=nums1[i:len(nums1)-1:]
            nums1[i] = nums2[j]
            j+=1
        return nums1

s = Solution()
print(s.merge([-1,0,0,3,3,3,0,0,0],6,[1,2,2],3))
