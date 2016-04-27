#找出数组中的数之和为目标数字的所有组合（同一个数不可以使用多次）
#如：[10,1,2,7,6,1,5],8 返回[[1, 1, 6], [1, 2, 5], [1, 7], [2, 6]]
class Solution(object):
    def combinationSum(self, candidates, target):
        candidates = sorted(candidates)
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
                self.dfs(candidates, target, i+1, now+candidates[i], tmp)
                tmp.pop()

s = Solution()
print(s.combinationSum([10,1,2,7,6,1,5],8))
