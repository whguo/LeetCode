#找出数组中的数之和为目标数字的所有组合（同一个数可以重复）
#如：[2,3,5],8 返回[[2,2,2,2],[2,3,3][3,5]]
class Solution(object):
    def combinationSum(self, candidates, target):
        sorted(candidates)
        self.ans, tmp = [], []
        self.dfs(candidates, target, 0, 0, tmp)
        return self.ans

    def dfs(self, candidates, target, p, now, tmp):
        if now == target:
            if not tmp in self.ans:
                self.ans.append(tmp[:])
            return
        for i in range(p, len(candidates)):
            if now + candidates[i] <= target:
                tmp.append(candidates[i])
                self.dfs(candidates, target, i, now+candidates[i], tmp)
                tmp.pop()

s = Solution()
print(s.combinationSum([2,2,3,5],8))
