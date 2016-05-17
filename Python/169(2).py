#找到一个数组中的主要元素(超过一半的)，假设该元素始终存在
#多数投票算法
#如果counts==0，则将Majority的值设置为数组的当前元素，将count赋值为1；
#反之，如果Majority和现在数组元素值相同，则counts++，反之counts-–；
#重复上述两步，直到扫描完数组。
#任何一个未超过一半次数的数，它的counts都不可能大于0，必将易主主元素值
#任何一个出现超过一半次数的，它的counts都不可能降为0
class Solution(object):
    def majorityElement(self, nums):
        counts = 0
        for n in nums:
            if counts==0:
                majority = n
                counts = 1
            else:
                if n==majority:
                    counts += 1
                else:
                    counts+=-1
        return majority

s = Solution()
print(s.majorityElement([1,2,3,2,2,2,5,3,2]))