class Solution:
    def minMoves(self, nums: List[int]) -> int:
        max_el = max(nums)
        return len(nums)* max_el - sum(nums)
        