class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        n = len(grid[0])
        m = len(grid) 
        k= k% (m*n)
        # Flatten the 2D grid into a 1D list
        flat = [grid[r][c] for r in range(m) for c in range(n)]
        flat = flat[-k:] +flat[:-k]
        new_grid = [flat[i*n:(i+1)*n] for i in range(m)]
        return new_grid