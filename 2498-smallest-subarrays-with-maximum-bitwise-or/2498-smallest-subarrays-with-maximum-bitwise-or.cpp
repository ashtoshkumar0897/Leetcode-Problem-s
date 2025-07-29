class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        vector<int> setBitIndex(32, -1); 
        // setBitIndex[j] = latest index where the j-th bit is set

        for (int i = n - 1; i >= 0; i--) {
            int endIndex = i;

            for (int j = 0; j < 32; j++) {
                if (nums[i] & (1 << j)) {
                    setBitIndex[j] = i;
                } else if (setBitIndex[j] != -1) {
                    endIndex = max(endIndex, setBitIndex[j]);
                }
            }

            result[i] = endIndex - i + 1;
        }

        return result;
    }
};