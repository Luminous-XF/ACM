//
// Created by Luminous on 2026/3/20 7:55
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    long long countSubarrays(std::vector<int>& nums, long long k) {
        const int n = (int) nums.size();

        long long sum = 0, ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            sum += nums[i];
            while (j <= i && sum * (i - j + 1) >= k) {
                sum -= nums[j];
                j++;
            }
            ans += i - j + 1;
        }
        return ans;
    }
};