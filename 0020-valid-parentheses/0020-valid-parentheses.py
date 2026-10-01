class Solution:
    def isValid(self, s: str) -> bool:
        st = []

        for ch in s:
            if ch == '(':
                st.append(')')
            elif ch =='{':
                st.append('}')
            elif ch =='[':
                st.append(']')
            elif not st or st[-1] != ch:
                return False
            else:
                st.pop()
        return not st
            
        