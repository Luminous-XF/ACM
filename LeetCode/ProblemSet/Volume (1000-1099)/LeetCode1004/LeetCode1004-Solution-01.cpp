//
// Created by Luminous on 2026/3/14 4:33
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        const int n = (int) nums.size();

        std::vector<int> cnt(2, 0);
        int ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            cnt[nums[i]]++;
            while (cnt[0] > k) {
                cnt[nums[j]]--;
                j++;
            }
            ans = std::max(ans, i - j + 1);
        }

        return ans;
    }
};