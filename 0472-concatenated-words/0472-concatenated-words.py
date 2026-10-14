class Solution:
    def findAllConcatenatedWordsInADict(self, words: list[str]) -> list[str]:
        word_set = set(words)
        res = []
        for w in words:
            n = len(w)
            if n == 0:
                continue
            word_set.discard(w)
            dp = [False] * (n + 1)
            dp[0] = True
            for i in range(1, n + 1):
                for j in range(max(0, i - 30), i):
                    if dp[j] and w[j:i] in word_set:
                        dp[i] = True
                        break
            if dp[n]:
                res.append(w)
            word_set.add(w)
        return res