class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        const int n = grid[0].size();
        long long ans = numeric_limits<long long>::max();
        long long prefix1 = accumulate(grid[0].begin(), grid[0].end(), 0ll);
        long long prefix2 = 0;
        for (int i = 0; i < n; ++i) {
            prefix1 -= grid[0][i];
            ans = min(ans, max(prefix1, prefix2));
            prefix2 += grid[1][i];
        }
        return ans;
    }
};