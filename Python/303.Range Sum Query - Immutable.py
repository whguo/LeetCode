#求数组下标i到j之间的数之和
class NumArray(object):
    def __init__(self, nums):
        self.nums , l = nums , len(nums)
        if l==0:    return
        self.cursum = [self.nums[0]]+[0]*(l-1)
        for i in range(1,l):
            self.cursum[i] = self.cursum[i-1] + self.nums[i]

    def sumRange(self, i, j):
        return self.cursum[j] - self.cursum[i] + self.nums[i] if self.nums!=[] else 0

numArray = NumArray([-2,0,3,-5,2,-1])
print(numArray.sumRange(0, 1))
print(numArray.sumRange(2, 5))
