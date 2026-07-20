from typing import *

class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        n, m = len(grid), len(grid[0])

        total = n * m
        ans = [[0] * m for _ in range(n)]
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                id = (i * m + j + k) % total
                ans[id // m][id % m] = x
        
        return ans