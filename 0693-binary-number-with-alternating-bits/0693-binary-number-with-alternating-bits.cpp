//Approach-3 (Using shift operators and Xor operation)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int result = n^(n >>1);

        return (result & (result +1)) == 0;
        
    }
};