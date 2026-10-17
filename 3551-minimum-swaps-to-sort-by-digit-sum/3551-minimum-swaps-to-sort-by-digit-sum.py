from typing import List

class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        def getDigitSum(num: int) -> int:
            total = 0
            while num > 0:
                total += num % 10
                num //= 10
            return total

        n = len(nums)
        after_sorted = sorted(nums, key=lambda x: (getDigitSum(x), x))

        val_to_idx = {val: i for i, val in enumerate(nums)}
        swap_count = 0

        for i in range(n):
            expected_val = after_sorted[i]
            curr_val = nums[i]

            if expected_val == curr_val:
                continue

            idx = val_to_idx[expected_val]

            nums[i], nums[idx] = nums[idx], nums[i]

            val_to_idx[expected_val] = i
            val_to_idx[curr_val] = idx

            swap_count += 1

        return swap_count
