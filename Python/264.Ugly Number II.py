#返回第n个的Ugly Number（从1开始）
#蛮力法：重复调用isUgly函数，直到第n个
#利用三个链表合并的方法：丑陋数序列可以拆分为下面3个子列表：
#(1) 1×2, 2×2, 3×2, 4×2, 5×2, 6×2, 8×2…
#(2) 1×3, 2×3, 3×3, 4×3, 5×3, 6×3, 8×3…
#(3) 1×5, 2×5, 3×5, 4×5, 5×5, 6×5, 8×5…
#发现每个子列表都是一个丑陋数分别乘以2,3,5，而要求的丑陋数就是从已经生成的序列中取出来的，我们每次都从三个列表中取出当前最小的那个加入序列
class Solution(object):
    def nthUglyNumber(self, n):
        if n==1:    return 1
        stack = [1,1]
        i , j , k = 1 , 1 , 1
        while len(stack)<=n:
            m2,m3,m5 = stack[i]*2,stack[j]*3,stack[k]*5
            mn = min(m2,m3,m5)
            if mn==m2:  i+=1
            if mn==m3:  j+=1
            if mn==m5:  k+=1
            stack.append(mn)
        return stack[-1]

s = Solution()
print(s.nthUglyNumber(14))
