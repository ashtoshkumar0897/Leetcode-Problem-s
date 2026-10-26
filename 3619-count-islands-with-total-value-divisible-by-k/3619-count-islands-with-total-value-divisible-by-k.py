class Solution:
    def countIslands(self, grid: List[List[int]], k: int) -> int:
        m  = len(grid)
        n = len(grid[0])

        direction =[
            (1,0),
            (-1,0),
            (0,1),
            (0,-1)
        ]

        def dfs(r,c):

            if r < 0 or r >= m or c < 0 or c >= n :
                return 0
            if grid[r][c] ==0:
                return 0
            val = grid[r][c]
            grid[r][c] =0 # mark visited

            total = val

            for dr,dc in direction:
                nr = r + dr
                nc = c + dc

                total += dfs(nr,nc)
            return total
        count =0

        for r in range(m):
            for c in range(n):

                if grid[r][c] > 0:
                    total = dfs(r,c)

                    if total % k == 0:
                        count += 1
        return count
        