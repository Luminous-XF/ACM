//
// Created by Luminous on 2026/3/15 16:22
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int minSizeSubarray(std::vector<int>& nums, int target) {
        const int n = (int) nums.size();

        long long total = std::accumulate(nums.begin(), nums.end(), 0LL);
        int ans = target / total * n;
        target %= total;

        int minLen = INT_MAX;
        long long sum = 0;
        for (int i = 0, j = 0; i < n * 2; i++) {
            sum += nums[i % n];

            while (sum > target) {
                sum -= nums[j % n];
                j++;
            }

            if (sum == target) {
                minLen = std::min(minLen, i - j + 1);
            }
        }

        if (minLen == INT_MAX) {
            return -1;
        }

        ans += minLen;

        return ans;
    }
};