//
// Created by Luminous on 2026/3/15 2:57
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        const int n = (int) nums.size();

        int ans = INT_MAX, sum = 0;
        for (int i = 0, j = 0; i < n; i++) {
            sum += nums[i];
            while (sum - nums[j] >= target) {
                sum -= nums[j];
                j++;
            }
            if (sum >= target) {
                ans = std::min(ans, i - j + 1);
            }
        }

        if (ans == INT_MAX) {
            ans = 0;
        }

        return ans;
    }
};