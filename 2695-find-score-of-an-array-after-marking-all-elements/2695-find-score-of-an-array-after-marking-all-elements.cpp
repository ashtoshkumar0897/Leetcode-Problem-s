class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();

        vector<bool> marked(n, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++)
            pq.emplace(nums[i], i);

        long long ans = 0;
        while (!pq.empty()) {
            pair<int, int> curr = pq.top();
            pq.pop();
            if (marked[curr.second])
                continue;
            ans += curr.first;
            if (curr.second + 1 < n)
                marked[curr.second + 1] = true;
            if (curr.second - 1 >= 0)
                marked[curr.second - 1] = true;
        }

        return ans;
    }
};