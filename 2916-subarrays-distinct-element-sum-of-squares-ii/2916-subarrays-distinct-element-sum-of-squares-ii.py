class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        MOD  = 10**9 + 7
        n = len(nums)

        sq_sum_tree = [0] * (4 * n)
        sum_tree = [0]* (4 * n)
        lazy =[0] * (4 *n)

        def lazy_addition(i,l,r, val):
            length = r - l + 1

            sq_sum_tree[i] += (
                2 * val * sum_tree[i] + length * val * val
            )
            sum_tree[i] += length * val
        def update_range(start,end,i,l,r,val):
            if lazy[i] != 0:
                lazy_addition(i,l,r, lazy[i])

                if l != r:
                    lazy[2 * i + 1] += lazy[i]
                    lazy[2 * i + 2] += lazy[i]
                lazy[i] = 0
            # out of range
            if l > end or r < start or l > r:
                return
            
            # completely within range
            if start <= l and r <= end:
                lazy_addition(i,l,r,val)

                if l != r:
                    lazy[2 * i + 1] += val
                    lazy[2 * i + 2] += val
                return

            mid = l + (r - l) // 2

            update_range(start,end,2 * i + 1, l, mid,val)
            update_range(start,end,2 * i + 2,mid + 1, r, val)

            sum_tree[i] = (
                sum_tree[2*i+1] + sum_tree[2 * i + 2]
            )
            sq_sum_tree[i] =(
                sq_sum_tree[2*i+1] + sq_sum_tree[2*i+2]
            )

        last_seen = [-1]* 100001
        result = 0

        for i, num in enumerate(nums):
            start = last_seen[num] + 1
            end = i
            update_range(start,end,0,0,n -1,1)
            result =(result + sq_sum_tree[0]) % MOD
            last_seen[num] = i
        return result
            
            
        