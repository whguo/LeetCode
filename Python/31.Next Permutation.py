#求出比给出数大的下一个数，如：1，2，3，输出1，3，2
class Solution(object):
    def nextPermutation(self, nums):
        l = len(nums)
        if l<=1:
            return

        i = l-2
        while i>=0 and nums[i]>=nums[i+1]:     #从后往前，找出第一对后面比前面大的数
            i-=1
        if i<0:
            nums.reverse()                  #如果没找到，那么直接翻过来
            #print(nums)
            return
        else:
            j = l-1
            while j>i and nums[j]<=nums[i]: #然后从后往前，找到第一个比nums[i]小的数
                j-=1
            if j==i:                         #没找到则和最后一个数互换，然后后面的数顺序翻过来
                tmp = nums[l-1]
                nums[l-1] = nums[i]
                nums[i] = tmp
                nums[i+1::] = nums[i+1::][::-1]
            else:
                tmp = nums[j]
                nums[j] = nums[i]
                nums[i] = tmp
                nums[i+1::] = nums[i+1::][::-1]
        #print(nums)
        return

s = Solution()
s.nextPermutation([3,2,1])
