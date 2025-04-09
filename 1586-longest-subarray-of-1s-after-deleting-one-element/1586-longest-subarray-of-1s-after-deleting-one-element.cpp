class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int flips = 0, i = 0, j = 0;
        int maxlen = 0; // Corrected initialization
        while (j < n) {
            if (nums[j] == 1)
                j++;
            else {
                if (flips == 0) { // Allow only one flip
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
        return maxlen-1; // Return maxlen after the loop ends
    }
};