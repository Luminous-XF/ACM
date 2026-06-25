//
// Created by Luminous on 2026/3/20 7:29
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
        const int n = (int) nums.size();

        if (k == 0) {
            return 0;
        }

        long long res = 1;
        int ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            res *= nums[i];
            while (j <= i && res >= k) {
                res /= nums[j];
                j++;
            }
            ans += i - j + 1;
        }
        return ans;
    }
};