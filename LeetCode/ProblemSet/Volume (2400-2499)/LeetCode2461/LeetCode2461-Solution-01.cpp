//
// Created by Luminous on 2026/3/11 0:10
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    long long maximumSubarraySum(std::vector<int>& nums, int k) {
        const int n = (int) nums.size();

        std::unordered_map<int, int> map;
        long long ans = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            map[nums[i]]++;

            int j = i - k + 1;
            if (j < 0) {
                continue;
            }

            if (map.size() == k) {
                ans = std::max(ans, sum);
            }

            sum -= nums[j];
            auto it = map.find(nums[j]);
            it->second--;
            if (it->second == 0) {
                map.erase(it);
            }
        }

        return ans;
    }
};