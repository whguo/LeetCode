#摆动排序，对给定数组排序，要求nums[0] < nums[1] > nums[2] < nums[3]....
#例：nums = [1, 5, 1, 1, 6, 4], 结果 [1, 4, 1, 5, 1, 6]
class Solution(object):
    def wiggleSort(self, nums):
        sortnums = sorted(nums)
        l = len(nums)
        i , j = (l+1)//2 , l
        for k in range(l):
            if k&1==0:
                i -= 1
                nums[k] = sortnums[i]
            else:
                j -= 1
                nums[k] = sortnums[j]

        return nums

s = Solution()
print(s.wiggleSort([1,5,1,1,6,4]))
