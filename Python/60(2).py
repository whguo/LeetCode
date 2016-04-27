#寻找n个数的全排列中第k大第数
#LeetCode中超时
class Solution(object):
    def getPermutation(self, n, k):
        d, ans, use = [0, 1], [], ['0'] * n
        for i in range(2, 10) : d.append( i * d[-1])
        for i in range(n):
            ans.append(0)
            for j in range(n):
                if use[j] == 1:
                    continue;
                ans[i] = chr(ord('0') + j + 1)
                if k <= d[n-i-1]:
                    use[j] = 1
                    break
                k -= d[n-i-1]
        return ''.join(ans)

s = Solution()
print(s.getPermutation(5,63))




