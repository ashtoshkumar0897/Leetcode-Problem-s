#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0, i = 0, j = 0;
        int maxlen = 0; // Corrected initialization
        while (j < n) {
            if (nums[j] == 1)
                j++;
            else {
                if (flips < k) {
                    flips++;
                    j++;
                } else {
                    int len = j - i; // Corrected calculation of len
                    maxlen = max(maxlen, len);
                    while (nums[i] == 1) // Corrected condition
                        i++;
                    i++;
                    j++;
                }
            }
        }
        int len = j - i; // Consider the case where the loop ends without hitting nums[j] == 0
        maxlen = max(maxlen, len);
        return maxlen; // Return maxlen after the loop ends
    }
};