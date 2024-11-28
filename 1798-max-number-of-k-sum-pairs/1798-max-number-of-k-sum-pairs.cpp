class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();

        // Edge case: If there's only one element, no pair can be formed.
        if (n == 1) {
            if (nums[0] == k) { // Corrected condition
                return 1;
            } else {
                return 0;
            }
        }

        int i = 0;                  // Start of the array
        int j = n - 1;              // End of the array
        int ops = 0;                // Counter for valid operations

        // Sort the array to enable the two-pointer technique
        sort(nums.begin(), nums.end());

        // Two-pointer logic
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == k) {
                ops++;
                i++;
                j--;
            } else if (sum > k) {
                j--;
            } else {
                i++;
            }
        }

        return ops;
    }
};

