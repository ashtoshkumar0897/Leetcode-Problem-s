class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        // Initialize a 2D distance matrix with INT_MAX for unvisited cells
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        
        // Deque for 0-1 BFS
        deque<pair<int, int>> dq;
        dq.push_front({0, 0});
        
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            
            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                
                // Check if the next cell is within grid bounds
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newDist = dist[x][y] + grid[nx][ny];
                    
                    // If this path offers a smaller number of obstacle removals
                    if (newDist < dist[nx][ny]) {
                        dist[nx][ny] = newDist;
                        if (grid[nx][ny] == 1) {
                            dq.push_back({nx, ny});  // Add to the back if it's an obstacle
                        } else {
                            dq.push_front({nx, ny});  // Add to the front if it's an empty cell
                        }
                    }
                }
            }
        }
        
        // Return the minimum obstacle removals required to reach the bottom-right corner
        return dist[m - 1][n - 1];
    }
};