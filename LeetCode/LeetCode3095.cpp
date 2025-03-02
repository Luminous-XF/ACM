//
// Created by Luminous on 2025/1/16 22:18
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int minimumSubarrayLength(std::vector<int>& nums, int k) {
        const int n = (int) nums.size();

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int res = 0;
            for (int j = i; j < n; j++) {
                res |= nums[j];
                if (res >= k) {
                    ans = std::min(ans, j - i + 1);
                    break;
                }
            }
        }

        if (ans == INT_MAX) {
            ans = -1;
        }

        return ans;
    }
};