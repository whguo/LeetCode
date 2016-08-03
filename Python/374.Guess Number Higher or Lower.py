#猜数游戏，在1到n间猜一个数，每次猜错告诉是猜大了还是小了，直至猜对。
#-1,猜大了。1，猜小了。0，猜对了。
class Solution(object):
    def guessNumber(self, n):
        l , r = 1 , n
        while l<=r:
            mid = (l+r)//2
            response = self.guess(mid)
            if response==0:
                return mid
            elif response==1:
                l = mid+1
            else:
                r = mid-1

    def guess(self,x):
        if x==6:    return 0
        elif x>6:   return -1
        else:       return 1

s = Solution()
print(s.guessNumber(10))


