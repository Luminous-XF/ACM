//
// Created by Luminous on 2025/1/14 21:44
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int waysToSplitArray(std::vector<int>& nums) {
        const int n = (int) nums.size();

        long long preSum = 0;
        long long sufSum = std::accumulate(nums.begin(), nums.end(), 0LL);
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            preSum += nums[i];
            sufSum -= nums[i];
            if (preSum >= sufSum) {
                ans++;
            }
        }

        return ans;
    }
};