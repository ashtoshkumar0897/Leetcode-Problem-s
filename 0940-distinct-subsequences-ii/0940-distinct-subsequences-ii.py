class Solution:
    def distinctSubseqII(self, s: str) -> int:
        MOD = 10 ** 9 + 7
        count = [0] * 26
        total_sum = 0

        for c in s:
            total = (1 + total_sum) % MOD
            idx = ord(c) - ord('a')

            total_sum = (total_sum + total - count[idx]) % MOD
            count[idx] = total
        return total_sum
        