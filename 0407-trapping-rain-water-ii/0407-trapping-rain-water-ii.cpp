class Solution {
#define PII pair<int, int>
    int R, C;
    bool inline inside(int r, int c) {
        return r >= 0 && r < R && c >= 0 && c < C;
    }
#define NDIR 4
    int dr[NDIR] = {1, -1, 0, 0};
    int dc[NDIR] = {0, 0, 1, -1};
    PII inline getRowCol(int cell) { return {cell / C, cell % C}; }
    int inline getCell(int r, int c) { return r * C + c; }

public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        R = heightMap.size();
        C = heightMap[0].size();
        vector<bool> visited(R * C, false);
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        for (int i = 0; i < R; ++i) {
            auto cell = getCell(i, 0);
            pq.push({heightMap[i][0], cell});
            visited[cell] = true;
            cell = getCell(i, C - 1);
            pq.push({heightMap[i][C - 1], cell});
            visited[cell] = true;
        }
        for (int i = 1; i < C - 1; ++i) {
            auto cell = getCell(0, i);
            pq.push({heightMap[0][i], cell});
            visited[cell] = true;
            cell = getCell(R - 1, i);
            pq.push({heightMap[R - 1][i], cell});
            visited[cell] = true;
        }
        int water = 0;
        while (!pq.empty()) {
            auto [height, cell] = pq.top();
            pq.pop();
            auto [row, col] = getRowCol(cell);

            for (int i = 0; i < NDIR; ++i) {
                auto nextRow = row + dr[i];
                auto nextCol = col + dc[i];
                auto next = getCell(nextRow, nextCol);
                if (inside(nextRow, nextCol) && !visited[next]) {
                    water += max(0, height - heightMap[nextRow][nextCol]);
                    pq.push({max(height, heightMap[nextRow][nextCol]), next});
                    visited[next] = true;
                }
            }
        }
        return water;
    }
};