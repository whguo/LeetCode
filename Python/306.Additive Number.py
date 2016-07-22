#加法数：至少含有三个数字，除去前两个数外，每个数字都是前面两个数字的和
#穷举前面两段的分割方式，然后check就行，square的复杂度。
#找到成立的第三个数，那么后边的数就可以一直循环下去
class Solution(object):
    def isAdditiveNumber(self, num):
        n = len(num)
        for i in range(1, n):
            for j in range(i + 1, n):
                a1,a2 = num[:i], num[i:j]
                if str(int(a1)) != num[:i] or str(int(a2)) != num[i:j]:
                    continue
                while j < n:
                    part = str(int(a1) + int(a2))
                    if not num[j:].startswith(part):
                        break
                    else:
                        j += len(part)
                        a1 = a2
                        a2 = part
                if j == n:
                    return True
        return False

s = Solution()
print(s.isAdditiveNumber("199100199"))
