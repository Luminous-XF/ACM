//
// Created by Luminous on 2024/11/29 18:36.
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = (int) 1e9 + 7;

    int countOfPairs(vector<int>& nums) {
        const int n = (int) nums.size();
        const int m = 50;

        int dp[n][m +  1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = 0;
            }
        }

        for (int v = 0; v <= nums[0]; v++) {
            dp[0][v] = 1;
        }

        for (int i = 1; i < n; i++) {
            int preSum[m + 1];
            preSum[0] = dp[i - 1][0];
            for (int j = 1; j <= m; j++) {
                preSum[j] = (preSum[j - 1] + dp[i - 1][j]) % MOD;
            }

            for (int v = 0; v <= nums[i]; v++) {
                int maxK = min({nums[i - 1], v, nums[i - 1] - nums[i] + v});
                if (maxK < 0) continue;
                dp[i][v] = (dp[i][v] + preSum[maxK]) % MOD;
            }
        }

        int ans = 0;
        for (int v = 0; v <= nums[n - 1]; v++) {
            ans = (ans + dp[n - 1][v]) % MOD;
        }

        return ans;
    }
};