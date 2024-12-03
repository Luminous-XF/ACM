//
// Created by Luminous on 2024/12/3 18:18
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        dfs(0, n, 0, 0, 0, ans);
        return ans;
    }

    void dfs(int step, int n, int col, int left, int right, int &ans) {
        if (step == n) {
            ans++;
            return;
        }

        for (int i = 0; i < n; i++) {
            bool check = (((col >> i) | (left >> (step - i + n - 1)) | (right >> (step + i))) & 1) == 0;
            if (!check) continue;
            dfs(step + 1, n, col | (1 << i), left | (1 << (step - i + n - 1)), right | (1 << (step + i)), ans);
        }
    }
};