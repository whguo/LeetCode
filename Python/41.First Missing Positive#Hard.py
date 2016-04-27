#找出数组中缺少的最小正整数，如：给出[1,2,0]，返回3，给出[3,4,-1,1]，返回2
class Solution(object):
    def firstMissingPositive(self, A):
        L = len(A)
        for i in range(L):
            while A[i] > 0 and A[i] <= L and A[i] != A[A[i] - 1] and i != A[i] - 1:
                A[A[i] - 1], A[i] = A[i], A[A[i] - 1]
                #A[i], A[A[i] - 1] = A[A[i] - 1], A[i]  dosen't work
        for i in range(L):
            if i != A[i] - 1:
                return i + 1
        return L + 1


s = Solution()
print(s.firstMissingPositive([3,4,2,1]))
