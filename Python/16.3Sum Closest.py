#在一串数字中找三个数字，使它们的和最接近目标数字，返回最接近的和
class Solution(object):
    def threeSum(self, nums,target):
        nums.sort()         #先排序
        closest , dis =  nums[0]+nums[1]+nums[2] , abs(nums[0]+nums[1]+nums[2]-target)
        for i in range(0, len(nums)):
            if (i > 0 and nums[i] == nums[i-1]):
                continue     #和前面一个数一样的话，跳过
            l, r = i + 1, len(nums) - 1
            while l < r:
                sum = nums[l] + nums[r] + nums[i]
                if sum == target:
                    return sum
                elif sum < target:
                    l = l + 1
                else:
                    r = r - 1
                if abs(target-sum)<dis:
                    dis = abs(target-sum)
                    closest = sum
        return closest

s = Solution()
print(s.threeSum([-1,2,1,-4],1))
