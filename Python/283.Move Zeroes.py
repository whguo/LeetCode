#把数组中的0都移动到最后，而保持其他数的顺序不变(在原数组上操作)
class Solution(object):
    def moveZeroes(self, nums):
        i , j , l = 0 , 0 , len(nums)
        while j<l:
            if nums[j]!=0:
                nums[i] , i = nums[j] , i+1
            j += 1
        while i<l:
            nums[i] , i = 0 , i+1
        return nums

s = Solution()
print(s.moveZeroes([0,1,0,3,12]))
