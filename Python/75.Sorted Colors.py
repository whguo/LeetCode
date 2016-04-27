#将数组按照0，1，2的顺序排列
class Solution(object):
    def sortColors(self, nums):
        i , j , k = 0 , len(nums)-1 , 0
        while k<=j:
            if nums[k]==0:
                nums[i] , nums[k] = nums[k] , nums[i]
                i+=1
                k+=1
            elif nums[k]==2:
                nums[j] , nums[k] = nums[k] , nums[j]
                j-=1
            else:
                k+=1
        print(nums)


s = Solution()
print(s.sortColors([1,0,2,2,2,1,0,1,1,2,2,0,1]))