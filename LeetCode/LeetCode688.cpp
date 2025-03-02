//
// Created by Luminous on 2024/12/7 17:23
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    const int dx[8] = {-2, -1, -2, -1, 2, 1, 2, 1};
    const int dy[8] = {-1, -2, 1, 2, -1, -2, 1, 2};

    double knightProbability(int n, int k, int row, int column) {
        double dp[k + 1][n][n];
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j < n; j++) {
                std::fill(dp[i][j], dp[i][j] + n, 0);
            }
        }

        for (int step = 0; step <= k; step++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (step == 0) {
                        dp[step][i][j] = 1;
                    } else {
                        for (int t = 0; t < 8; t++) {
                            int nx = i + dx[t];
                            int ny = j + dy[t];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                            dp[step][i][j] += dp[step - 1][nx][ny] / 8;
                        }
                    }
                }
            }
        }

        return dp[k][row][column];
    }
};