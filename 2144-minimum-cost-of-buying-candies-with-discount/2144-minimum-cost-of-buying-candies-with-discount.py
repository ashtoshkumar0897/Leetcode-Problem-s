class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        n = len(cost)
        cost.sort(reverse = True)

        total = 0
        for i in range(n):
            if i % 3 != 2:
                total += cost[i]
        return total

        