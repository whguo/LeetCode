#给出股票价格数组，可以买卖任意次，但是不能同时进行多桩交易(买另一个股票前必须卖掉上一个)
#每卖掉一个股票，第二天不能买进股票(冷却一天)
class Solution(object):
    def maxProfit(self, prices):
        if len(prices) < 2:     return 0
        sell, buy, prev_sell, prev_buy = 0, -prices[0], 0, 0
        for price in prices:
            prev_buy = buy
            buy = max(prev_sell - price, prev_buy)
            prev_sell = sell
            sell = max(prev_buy + price, prev_sell)
        return sell

s = Solution()
print(s.maxProfit([1,2,3,0,2]))
