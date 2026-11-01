class Solution:
    def minMoves(self, nums: list[int]) -> int:
        n = len(nums)

        total_sum = 0
        min_el = float('inf')

        for i in range(n):
            total_sum += nums[i]
            min_el = min(min_el,nums[i])

        return total_sum - n * min_el
        