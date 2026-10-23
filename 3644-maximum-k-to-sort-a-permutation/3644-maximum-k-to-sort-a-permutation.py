class Solution:
    def sortPermutation(self, nums: List[int]) -> int:
        n = len(nums)
        k = -1 # //"1111111" (all bits set)

        for i in range(n):
            if nums[i] != i:# age same position par nahi rha tu
                k &= nums[i]
        return 0 if k == -1 else k        