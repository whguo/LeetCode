#从第一个数出发，跳到最后一个数，当前位置的大小为可以跳的最大步数
import copy
class Solution(object):
    def canJump(self, nums):
        l , maxstep = len(nums) , 0
        for i in range(l):
            maxstep -= 1
            maxstep = max(maxstep,nums[i])
            if i+maxstep>=l-1:
                return True
            elif maxstep==0:
                return False

s = Solution()
print(s.canJump([5,9,3,2,1,0,2,3,3,1,0,0]))
print(s.canJump([1,0,1,0]))
print(s.canJump([0,2,3]))
print(s.canJump([2,0,0]))
print(s.canJump([2,3,1,1,4]))
print(s.canJump([3,2,1,0,4]))



