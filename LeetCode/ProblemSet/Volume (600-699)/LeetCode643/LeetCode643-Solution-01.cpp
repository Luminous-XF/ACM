//
// Created by Luminous on 2026/3/10 20:38
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        const int n = (int) nums.size();

        double sum = 0, ans = -1e4 - 10;
        for (int i = 0; i < n; i++) {
            sum += nums[i];

            int j = i - k + 1;
            if (j < 0) {
                continue;
            }

            double avg = sum / k;
            ans = std::max(ans, avg);

            sum -= nums[j];
        }

        return ans;
    }
};