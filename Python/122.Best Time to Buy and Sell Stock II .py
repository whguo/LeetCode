#用一个数组表示股票每天的价格，数组的第i个数表示股票在第i天的价格。 如果允许多次交易(买一个再卖掉，再买)，
#但是，在买下一个前必须卖掉上一个，求最大的收益
class Solution(object):
    def maxProfit(self, prices):
        l  = len(prices)
        if l<=1:
            return 0
        maxpro = 0
        for i in range(1,l):
            if prices[i]>prices[i-1]:
                maxpro += (prices[i]-prices[i-1])
        return maxpro


s = Solution()
print(s.maxProfit([84,22,3,44,2]))

#只要后一天大于前一天，都算收益