//
// Created by Luminous on 2026/3/20 8:30
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    long long countSubarrays(std::vector<int>& nums, int k) {
        const int n = (int) nums.size();

        long long ans = 0;
        int cnt = 0, maxNum = *std::ranges::max_element(nums);
        for (int i = 0, j = 0; i < n; i++) {
            if (nums[i] == maxNum) {
                cnt++;
            }

            if (cnt < k) {
                continue;
            }

            while (nums[j] != maxNum || (nums[j] == maxNum && cnt > k)) {
                if (nums[j] == maxNum) {
                    cnt--;
                }
                j++;
            }

            ans += j + 1;
        }

        return ans;
    }
};