#给出一个整数数组nums，返回一个数组，每个位置i对应元素为除了nums[i]其他数的乘积
#不能用除法，而且O(n)
#执行两趟循环：
#第一趟正向遍历数组，计算x0 ~ xi-1的乘积
#第二趟反向遍历数组，计算xi+1 ~ xn-1的乘积

class Solution(object):
    def productExceptSelf(self, nums):
        l = len(nums)
        output  , left , right = [1] * l ,1 ,1
        for i in range(l-1):
            left *= nums[i]
            output[i+1] *= left
        for i in range(l-1,0,-1):
            right *= nums[i]
            output[i-1] *= right
        return output

s = Solution()
print(s.productExceptSelf([1,2,3,4]))