//
// Created by Luminous on 2026/3/10 21:35
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> getAverages(std::vector<int>& nums, int k) {
        const int n = (int) nums.size();

        std::vector<int> ans(n, -1);
        long long sum = 0;
        int len = k * 2 + 1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];

            int j = i - len + 1;
            if (j < 0) {
                continue;
            }

            ans[i - k] = sum / len;

            sum -= nums[j];
        }

        return ans;
    }
};