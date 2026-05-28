from typing import List

class Solution:
    class TrieNode:
        def __init__(self, idx: int):
            self.idx = idx
            self.children = [None] * 26

    def getNode(self, i: int) -> 'Solution.TrieNode':
        return Solution.TrieNode(i)

    def insertTrie(self, pCrawl: 'Solution.TrieNode', i: int, wordsContainer: List[str]):
        word = wordsContainer[i]
        n = len(word)

        for j in range(n - 1, -1, -1):  # traverse backwards
            ch_idx = ord(word[j]) - ord('a')

            if pCrawl.children[ch_idx] is None:
                pCrawl.children[ch_idx] = self.getNode(i)

            pCrawl = pCrawl.children[ch_idx]

            if len(wordsContainer[pCrawl.idx]) > n:
                pCrawl.idx = i

    def search(self, pCrawl: 'Solution.TrieNode', word: str) -> int:
        result_idx = pCrawl.idx
        n = len(word)

        for i in range(n - 1, -1, -1):
            ch_idx = ord(word[i]) - ord('a')
            if pCrawl.children[ch_idx] is None:
                return result_idx
            pCrawl = pCrawl.children[ch_idx]
            result_idx = pCrawl.idx

        return result_idx

    def stringIndices(self, wordsContainer: List[str], wordsQuery: List[str]) -> List[int]:
        m = len(wordsContainer)
        n = len(wordsQuery)
        result = [0] * n

        root = self.getNode(0)

        for i in range(m):
            if len(wordsContainer[root.idx]) > len(wordsContainer[i]):
                root.idx = i
            self.insertTrie(root, i, wordsContainer)

        for i in range(n):
            result[i] = self.search(root, wordsQuery[i])

        return result
