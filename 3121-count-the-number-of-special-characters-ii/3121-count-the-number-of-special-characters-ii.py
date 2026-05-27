class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        n = len(word)
        lastSmall =[-1] *26
        firstCapital = [-1] *26

        for i in range(n):
            ch = word[i]
            if ch.islower():
                lastSmall[ord(ch) - ord('a')] = i
            else: 
                if firstCapital[ord(ch) - ord('A') ] == -1:
                    firstCapital[ord(ch) - ord('A') ] = i
                
        count =0
        for i in range(26):
            if lastSmall[i] != -1 and firstCapital[i] != -1 and lastSmall [i] < firstCapital[i]:
                count +=1
        return count