#include <bits/stdc++.h>

class Solution {
public:
    const int MOD = 1'000'000'007;

    int dfs(int i, int j, int k, std::vector<std::vector<std::vector<int>>>& dp, std::vector<int>& nums) {
        if (i < 0) {
            return j == k ? 1 : 0;
        }
    
        int& res = dp[i][j][k];
        if (res == -1) {
            res = (
                (long long) dfs(i - 1, j, k, dp, nums) +
                (long long) dfs(i - 1, std::gcd(j, nums[i]), k, dp, nums) + 
                (long long) dfs(i - 1, j, std::gcd(k, nums[i]), dp, nums)
            ) % MOD;
        }
        
        return res;
    }

    int subsequencePairCount(std::vector<int>& nums) {
        const int n = (int) nums.size();
        const int m = (int) std::ranges::max(nums);
        std::vector<std::vector<std::vector<int>>> dp(n, std::vector(m + 1, std::vector<int>(m + 1, -1)));

        return (dfs(n - 1, 0, 0, dp, nums) - 1 + MOD) % MOD;
    }
};