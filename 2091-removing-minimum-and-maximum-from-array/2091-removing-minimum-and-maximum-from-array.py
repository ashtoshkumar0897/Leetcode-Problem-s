from typing import List

class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        n = len(nums)

        minElIdx = nums.index(min(nums))
        maxElIdx = nums.index(max(nums))

        left = min(minElIdx, maxElIdx)
        right = max(minElIdx, maxElIdx)

        # Three possible strategies:
        # 1. Remove from left up to 'right'
        # 2. Remove from right down to 'left'
        # 3. Remove from both sides (left+1 from left, n-right from right)
        return min(left + 1 + n - right, right + 1, n - left)
