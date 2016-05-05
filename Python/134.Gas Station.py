#在一个环路上有N个加油站，第i个加油站有的油为gas[i]，从第i个到第i+1个消耗的油为cost[i]，汽车的油箱无限大
#返回能够使汽车行驶一圈的起始加油站号
#这个方法最核心的思想是基于如下的事实：
# 假如从第0个station可以到达第j=1,2,⋯,i−1j=1,2,⋯,i−1个station，但无法到达第i个station的话，
# 那么从第j=1,2,⋯,i−1j=1,2,⋯,i−1个station出发也肯定无法到达第i个station。
# 原因很简单，假如可以从第j个station到达第i个station，那么我们可以先从第0个到达第j个，
# 然后在从第j个到达第i个，也就是说我们可以从第0个到达第i个，故这个假设是不成立的。
# 这样的话，当我们判断从第0个station无法到达第i个时，可以不用回过头从第1个station判断，我们可以直接继续从第i+1个station开始判断。
# 如果总油量大于消耗量的话，那么一定存在解
class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        start , cur , sum = 0 , 0 , 0
        l = len(gas)
        for i in range(l):
            left = gas[i]-cost[i]
            sum += left
            cur += left
            if cur<0:
                start=(i+1)%l
                cur = 0
        if sum<0:
            return -1
        else:
            return start


#蛮力法，超时
    def canCompleteCircuit1(self, gas, cost):
        l = len(gas)
        if l==0:
            return 0
        for i in range(l):
            curr = gas[i]-cost[i]
            if curr<0:
                continue
            j = (i+1)%l
            while j!=i:
                curr=curr+gas[j]-cost[j]
                if curr<0:
                    break
                j = (j+1)%l
            if j==i:
                return i
        return -1




s = Solution()
print(s.canCompleteCircuit([1,4,3,4,6,7],[2,5,3,2,9,4]))