from typing import List

class Solution:
    def sortPermutation(self, nums: List[int]) -> int:
        n = len(nums)

        K = -1  # Initially, all bits are set to 1

        for i in range(n):
            # Check if the element is not at its correct index
            if nums[i] != i:
                # Keep only the bits that are set in both K and nums[i]
                K = K & nums[i]

        # If no misplaced elements were found, return 0
        return 0 if K == -1 else K