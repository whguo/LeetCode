#在有序循环数组中寻找目标数(数字不重复)
class Solution(object):
    def search(self, nums, target):
        l , r = 0 , len(nums)-1
        while l<=r:
            if nums[l]==target:
                return l
            if nums[r]==target:
                return r
            if nums[l]<target and nums[r]>target:
                while l<=r:
                    mid = (r+l)//2
                    if nums[mid]==target:
                        return mid
                    elif nums[mid]<target:
                        l = mid+1
                    else:
                        r = mid-1
                return -1
            else:
                l += 1
                r -= 1
        return -1

s = Solution()
print(s.search([1,3],2))