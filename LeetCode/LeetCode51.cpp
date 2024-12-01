//
// Created by Luminous on 2024/12/1 15:12.
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    vector<string> grid;

    vector<vector<string>> solveNQueens(int n) {
        dfs(0, n, 0, 0, 0);
        return ans;
    }

    void dfs(int step, int n, int col, int left, int right) {
        if (step == n) {
            ans.push_back(grid);
            return;
        }

        string s(n, '.');
        for (int i = 0; i < n; i++) {
            bool check = (((col >> i) | (left >> (step - i + n - 1)) | (right >> (step + i))) & 1) == 0;
            if (!check) continue;

            s[i] = 'Q';
            grid.push_back(s);

            dfs(step + 1, n, col | (1 << i), left | (1 << (step - i + n - 1)), right | (1 << (step + i)));

            grid.pop_back();
            s[i] = '.';
        }
    }
};