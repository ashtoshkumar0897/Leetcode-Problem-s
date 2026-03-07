//Approach-3 (Sliding Window + without modifying input)
//T.C : O(2*n) ~= O(n)
//S.C : O(1)
class Solution {
public:
    int minFlips(string s) {
        int n = s.length();

        //khandani sliding window
        int result = INT_MAX;
        int flip1 = 0;
        int flip2 = 0;

        int i = 0;
        int j = 0;

        while(j < 2*n) {

            char expectedCharS1 = (j%2) ? '1' : '0';
            char expectedCharS2 = (j%2) ? '0' : '1';

            if(s[j%n] != expectedCharS1) {
                flip1++;
            }

            if(s[j%n] != expectedCharS2) {
                flip2++;
            }

            if(j-i+1 > n) { //shrink the window from left
                expectedCharS1 = (i%2) ? '1' : '0';
                expectedCharS2 = (i%2) ? '0' : '1';

                if(s[i%n] != expectedCharS1) {
                    flip1--;
                }

                if(s[i%n] != expectedCharS2) {
                    flip2--;
                }

                i++;
            }

            if(j-i+1 == n) {
                result = min({result, flip1, flip2});
            }

            j++;

        }
        return result;
    }
};
