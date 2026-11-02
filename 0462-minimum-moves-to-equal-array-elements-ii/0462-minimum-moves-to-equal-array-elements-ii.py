class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        def introselect(a, k):
            budget = 6 * len(a)  # how much random pivots may scan in total
            while True:
                if len(a) <= 1:
                    return a[0]
                budget -= len(a)
                if budget >= 0:  # on track: cheap random pivot
                    p = random.choice(a)
                else:  # too slow: median of medians from now on
                    medians = [sorted(g)[len(g) // 2] for g in batched(a, 5)]
                    p = introselect(medians, len(medians) // 2)
                lo = [x for x in a if x < p]
                if k < len(lo):
                    a = lo
                    continue
                hi = [x for x in a if x > p]
                if k >= len(a) - len(hi):
                    k -= len(a) - len(hi)
                    a = hi
                    continue
                return p  # pivot sits at position k

        med = introselect(nums, len(nums) // 2)
        return sum(abs(x - med) for x in nums)