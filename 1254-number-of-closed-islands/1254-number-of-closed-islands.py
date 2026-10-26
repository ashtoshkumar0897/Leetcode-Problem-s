
class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:

        m, n = len(grid), len(grid[0])
        dirs = (-1, 0, 1, 0, -1)

        def dfs(i: int, j: int) -> bool:

            if i < 0 or i >= m or j < 0 or j >= n:
                return False

            if grid[i][j] == 1:
                return True

            grid[i][j] = 1

            closed = True

            for d in range(4):
                x, y = i + dirs[d], j + dirs[d + 1]

                if not dfs(x, y):
                    closed = False

            return closed

        count = 0

        for i in range(m):
            for j in range(n):

                if grid[i][j] == 0:
                    if dfs(i, j):
                        count += 1

        return count
