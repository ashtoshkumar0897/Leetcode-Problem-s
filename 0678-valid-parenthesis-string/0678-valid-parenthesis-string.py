class Solution:
    def checkValidString(self, s: str) -> bool:

        open  = 0
        close = 0

        #left to right
        for ch in s:
            if ch in '(*':
                open += 1
            else:
                open -= 1

            if open < 0:
                return False

        #Right to left
        for ch in reversed(s):
            if ch in ')*':
                close += 1
            else:
                close -= 1
            if close < 0:
                return False
        return True
        