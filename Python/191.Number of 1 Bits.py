#求32位整数中，按位算，1的个数有多少
class Solution(object):
    def hammingWeight(self, n):
        hanmmingweight = 0
        while n>0:
            if n&1==1:
                hanmmingweight += 1
            n>>=1
        return hanmmingweight

s = Solution()
print(s.hammingWeight(111))