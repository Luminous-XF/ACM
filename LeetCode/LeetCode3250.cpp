//
// Created by Luminous on 2024/11/28 22:46.
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    const int MOD = (int) 1e9 + 7;

    int countOfPairs(vector<int>& nums) {
        const int n = (int) nums.size();
        const int m = 50;

        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m + 1, -1));
        for (int v = 0; v <= nums[n - 1]; v++) {
            ans = (ans + dfs(n - 1, v, nums, dp, n, m)) % MOD;
        }

        return ans;
    }

    int dfs(int i, int v, vector<int> &nums, vector<vector<int>> &dp, int n, int m) {
        if (i == 0) return 1;
        if (dp[i][v] != -1) return dp[i][v];

        int res = 0;
        int maxK = min({nums[i - 1], v, nums[i - 1] - nums[i] + v});
        for (int k = 0; k <= maxK; k++) {
            res = (res + dfs(i - 1, k, nums, dp, n, m)) % MOD;
        }

        dp[i][v] = res;

        return res;
    }
};


class Solution2 {
public:
    const int MOD = (int) 1e9 + 7;

    int countOfPairs(vector<int>& nums) {
        const int n = (int) nums.size();
        const int m = 50;

        int dp[n][m + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = 0;
            }
        }

        for (int v = 0; v <= nums[0]; v++) {
            dp[0][v] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int v = 0; v <= nums[i]; v++) {
                int maxK = min({nums[i - 1], v, nums[i - 1] - nums[i] + v});
                for (int k = 0; k <= maxK; k++) {
                    dp[i][v] = (dp[i][v] + dp[i - 1][k]) % MOD;
                }
            }
        }

        int ans = 0;
        for (int v = 0; v <= nums[n - 1]; v++) {
            ans = (ans + dp[n - 1][v]) % MOD;
        }

        return ans;
    }
};