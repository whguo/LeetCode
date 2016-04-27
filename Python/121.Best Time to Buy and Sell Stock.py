#一用一个数组表示股票每天的价格，数组的第i个数表示股票在第i天的价格。 如果只允许进行一次交易，也就是说只允许买一支股票并卖掉，求最大的收益
class Solution(object):
    def maxProfit(self, prices):
        l  = len(prices)
        if l == 0:
            return 0
        maxpro , curmin = 0 , prices[0]
        for i in range(1,l):
            maxpro = max(maxpro,prices[i]-curmin)
            curmin = min(prices[i],curmin)
        return maxpro


s = Solution()
print(s.maxProfit([84,22,3,44,2]))