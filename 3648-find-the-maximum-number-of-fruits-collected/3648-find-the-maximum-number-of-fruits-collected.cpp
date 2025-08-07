class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        vector<vector<int>> t(n, vector<int>(n, 0));

        // Child 1 collects diagonal fruits
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result += fruits[i][i];
        }

        // Nullify cells that child2 and child3 can't visit
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i < j && i + j < n - 1) || (i > j && i + j < n - 1)) {
                    t[i][j] = 0;
                } else {
                    t[i][j] = fruits[i][j];
                }
            }
        }

        // Child 2 collects fruits (upper triangle: i < j)
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int leftDiag = (j - 1 >= 0) ? t[i - 1][j - 1] : 0;
                int up = t[i - 1][j];
                int rightDiag = (j + 1 < n) ? t[i - 1][j + 1] : 0;
                t[i][j] += max({leftDiag, up, rightDiag});
            }
        }

        // Child 3 collects fruits (lower triangle: i > j)
        for (int j = 1; j < n; ++j) {
            for (int i = j + 1; i < n; ++i) {
                int leftDiag = (i - 1 >= 0 && j - 1 >= 0) ? t[i - 1][j - 1] : 0;
                int left = t[i][j - 1];
                int downDiag = (i + 1 < n && j - 1 >= 0) ? t[i + 1][j - 1] : 0;
                t[i][j] += max({leftDiag, left, downDiag});
            }
        }

        // Find max for child2 and child3 from valid regions
        int maxChild2 = 0, maxChild3 = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i < j && i + j >= n - 1) {
                    maxChild2 = max(maxChild2, t[i][j]);
                }
                if (i > j && i + j >= n - 1) {
                    maxChild3 = max(maxChild3, t[i][j]);
                }
            }
        }

        return result + maxChild2 + maxChild3;
    }
};