class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        // Prefix sum array for amounts
        vector<int> prefix(n+1, 0);
        for (int i = 0; i < n; ++i)
            prefix[i+1] = prefix[i] + fruits[i][1];

        // Find the range of indices you can reach within k steps (left-most and right-most)
        int res = 0;
        int l = 0;
        // Sliding window: fix right end, move left bound to keep within k steps
        for (int r = 0; r < n; ++r) {
            // To harvest from fruits[l] to fruits[r] (inclusive)
            // minimum steps required (can go left first or right first)
            while (l <= r) {
                int left = fruits[l][0], right = fruits[r][0];
                int goLeftFirst = abs(startPos - left) + (right - left);
                int goRightFirst = abs(startPos - right) + (right - left);
                if (min(goLeftFirst, goRightFirst) > k)
                    ++l;
                else
                    break;
            }
            res = max(res, prefix[r+1] - prefix[l]);
        }
        return res;
    }
};