#用一个数组表示股票每天的价格，数组的第i个数表示股票在第i天的价格。 如果最多允许两次交易，求最大的收益
#第一次的卖可以和第二次的买在同一时间，但第二次的买不能在第一次的卖左边
class Solution(object):
    def maxProfit(self, prices):
        l  = len(prices)
        if l<=1:
            return 0
        maxpro,curmin = 0,prices[0]
        premax , postmax = [0 for i in range(l)] , [0 for i in range(l)]
        for i in range(1,l):
            premax[i] = max(prices[i]-curmin,premax[i-1])
            curmin = min(curmin,prices[i])
        curmax = prices[l-1]
        i = l-2
        while i>0:
            postmax[i] = max(postmax[i+1],curmax-prices[i])
            curmax = max(curmax,prices[i])
            i -= 1
        for i in range(l):
            maxpro = max(maxpro,premax[i]+postmax[i])
        print(premax)
        print(postmax)
        return maxpro


s = Solution()
print(s.maxProfit([3,6,9,4,2,8,7,5]))
