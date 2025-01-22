class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        int n = (int)mat.size(), m = (int)mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1)); // Changed from 0 to -1
        queue<pair<int, int>> que;
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    que.push({i, j});
                    ans[i][j] = 0; 
                }
            }
        }
        int dis = 1;
        while (!que.empty()) {
            int N = (int)que.size();
            bool chk=false;
            while (N--) {
                auto cur = que.front();
                que.pop();
                for (auto& it : dir) {
                    int new_x = cur.first + it.first;
                    int new_y = cur.second + it.second;
                    if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && ans[new_x][new_y] == -1) {
                        que.push({new_x, new_y});
                        ans[new_x][new_y] = dis;
                        chk=true;
                    }
                }
            }
            if(chk)dis++;
        }
        return ans;
    }
};