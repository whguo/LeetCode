#在有序循环数组中寻找目标数（有重复的数)
class Solution(object):
    def search(self, nums, target):
        l , r = 0 , len(nums)-1
        while l<=r:
            if nums[l]==target:
                return True
            if nums[r]==target:
                return True
            if nums[l]<target and nums[r]>target:
                while l<=r:
                    mid = (r+l)//2
                    if nums[mid]==target:
                        return True
                    elif nums[mid]<target:
                        l = mid+1
                    else:
                        r = mid-1
                return False
            else:
                l += 1
                r -= 1
        return False

s = Solution()
print(s.search([1,1,1,2,2,3,3,3],2))