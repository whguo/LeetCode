#求数组下标i到j之间的数之和
#并可以更新数组内容：update(x,y)把下标为x的数改为y
#能够实现更新后快速计算i到j只间的和

#Binary index tree(Fenwick tree)树状数组
class NumArray(object):
    def __init__(self, nums):
        self.sum_array = [0] * (len(nums) + 1)
        self.nums = nums
        self.n = len(nums)
        for i in range(self.n):
            self.add(i + 1,nums[i])

    def add(self,x,val):
        while x <= self.n:
            self.sum_array[x] += val
            x += self.lowbit(x)

    #求x二进制位最后一个1的位置，利用补码，-x是x按位取反加1的结果
    def lowbit(self,x):
        return x & -x

    def sum(self,x):
        res = 0
        while x >0:
            res += self.sum_array[x]
            x -= self.lowbit(x)
        return res

    def update(self, i, val):
        self.add(i + 1, val - self.nums[i])
        self.nums[i] = val

    def sumRange(self, i, j):
        if not self.nums: return  0
        return self.sum(j+1) - self.sum(i)

#线段树
import math
class NumArray1(object):
    def __init__(self, nums):
        self.nums = nums
        self.size = size = len(nums)
        h = int(math.ceil(math.log(size, 2))) if size else 0
        maxSize = 2 ** (h + 1) - 1
        self.st = [0] * maxSize
        if size:
            self.initST(0, size-1, 0)

    def update(self, i, val):
        if i < 0 or i >= self.size:
            return
        diff = val - self.nums[i]
        self.nums[i] = val
        self.updateST(0, self.size - 1, i, diff, 0)

    def sumRange(self, i, j):
        if i < 0 or j < 0 or i >= self.size or j >= self.size:
            return 0
        return self.sumRangeST(0, self.size - 1, i, j, 0)

    def initST(self, ss, se, si):
        if ss == se:
            self.st[si] = self.nums[ss]
        else:
            mid = (ss + se) / 2
            self.st[si] = self.initST(ss, mid, si * 2 + 1) + self.initST(mid + 1, se, si * 2 + 2)
        return self.st[si]

    def updateST(self, ss, se, i, diff, si):
        if i < ss or i > se:
            return
        self.st[si] += diff
        if ss != se:
            mid = (ss + se) / 2
            self.updateST(ss, mid, i, diff, si * 2 + 1)
            self.updateST(mid + 1, se, i, diff, si * 2 + 2)

    def sumRangeST(self, ss, se, qs, qe, si):
        if qs <= ss and qe >= se:
            return self.st[si]
        if se < qs or ss > qe:
            return 0
        mid = (ss + se) / 2
        return self.sumRangeST(ss, mid, qs, qe, si * 2 + 1) + self.sumRangeST(mid + 1, se, qs, qe, si * 2 + 2)

numArray = NumArray([1,3,8])
print(numArray.sumRange(0, 2))
numArray.update(1, 10)
print(numArray.sumRange(1, 2))
