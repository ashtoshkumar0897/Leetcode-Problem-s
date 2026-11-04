class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        min_price = float('inf')
        max_pro = 0
        for price in prices:
            min_price = min(min_price, price)
            max_pro = max(max_pro, price - min_price)
        return max_pro
        


       