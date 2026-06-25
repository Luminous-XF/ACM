//
// Created by Luminous on 2026/3/14 3:43
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int maximumUniqueSubarray(std::vector<int>& nums) {
        const int n = (int) nums.size();

        std::unordered_set<int> set;
        int ans = 0, sum = 0;
        for (int i = 0, j = 0; i < n; i++) {
            while (set.contains(nums[i])) {
                sum -= nums[j];
                set.erase(nums[j]);
                j++;
            }
            set.insert(nums[i]);
            sum += nums[i];
            ans = std::max(ans, sum);
        }

        return ans;
    }
};