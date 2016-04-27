#给出数字数组中，目标数字第一个和最后一个出现的位置，没有则返回[-1,1]
#要求算法O(log n)
class Solution(object):
    def searchRange(self, nums, target):
        l , r = 0 , len(nums)-1
        while l<=r:
            mid = (l+r)//2
            if nums[mid] == target:
                break
            elif nums[mid]<target:
                l = mid+1
            else:
                r = mid-1

        if nums[mid]==target:
            l = mid
            while l>=0 and nums[l]==nums[mid]:
                l-=1
            r = mid
            while r<len(nums) and nums[r]==nums[mid]:
                r+=1
            return [l+1,r-1]
        else:
            return [-1,-1]



s = Solution()
print(s.searchRange([5,7,7,8,8,10],10))
