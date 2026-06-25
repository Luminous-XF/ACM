//
// Created by Luminous on 2026/3/14 2:48
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int minRemoval(std::vector<int>& nums, int k) {
        const int n = (int) nums.size();

        std::ranges::sort(nums);
        int len = 0;
        for (int i = 0, j = 0; i < n; i++) {
            while ((long long) nums[j] * k < nums[i]) {
                j++;
            }
            len = std::max(len, i - j + 1);
        }

        int ans = n - len;

        return ans;
    }
};