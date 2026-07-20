#include <bits/stdc++.h>

class Solution {
public:
    std::vector<std::vector<int>> shiftGrid(std::vector<std::vector<int>>& grid, int k) {
        const int n = (int) grid.size();
        const int m = (int) grid[0].size();

        int total = n * m;
        std::vector<std::vector<int>> ans(n, std::vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int id = (i * m + j + k) % total;
                ans[id / m][id % m] = grid[i][j];
            }
        }

        return ans;
    }
};