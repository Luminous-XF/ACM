//
// Created by Luminous on 2026/3/14 2:23
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        const int n = (int) nums.size();

        int ans = 0, cnt1 = 0, cnt2 = 0;
        for (int i = 0, j = 0; i < n; i++) {
            if (nums[i] == 1) {
                cnt1++;
            } else {
               cnt2++;
                while (cnt2 > 1) {
                    nums[j] == 1 ? cnt1-- : cnt2--;
                    j++;
                }
            }

            if (cnt2 == 0) {
                ans = std::max(ans, cnt1 - 1);
            } else {
                ans = std::max(ans, cnt1);
            }
        }

        return ans;
    }
};