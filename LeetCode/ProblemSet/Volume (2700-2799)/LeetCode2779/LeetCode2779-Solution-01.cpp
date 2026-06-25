//
// Created by Luminous on 2026/3/14 15:14
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int maximumBeauty(std::vector<int> &nums, int k) {
        const int n = (int) nums.size();

        std::ranges::sort(nums);
        int ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            while (nums[j] + k < nums[i] - k) {
                j++;
            }
            ans = std::max(ans, i - j + 1);
        }
        return ans;
    }
};