#寻找n个数的全排列中第k大第数
#LeetCode中超时
class Solution(object):
    def getPermutation(self, n, k):
        num = [i for i in range(1,n+1)]
        while k>0:
            self.nextPermutation(num)
            k-=1
        st = ''
        for i in num:
            st = st+str(i)
        return st


    def nextPermutation(self, nums):
        l = len(nums)
        if l<=1:
            return False

        i = l-2
        while i>=0 and nums[i]>=nums[i+1]:     #从后往前，找出第一对后面比前面大的数
            i-=1
        if i<0:
            return False
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
        return True

s = Solution()
print(s.getPermutation(9,273815))




