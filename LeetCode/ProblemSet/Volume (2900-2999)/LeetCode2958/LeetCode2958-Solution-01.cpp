//
// Created by Luminous on 2026/3/14 4:11
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int maxSubarrayLength(std::vector<int>& nums, int k) {
        const int n = (int) nums.size();

        std::unordered_map<int, int> book;
        int ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            book[nums[i]]++;
            while (book[nums[i]]> k) {
                book[nums[j]]--;
                j++;
            }
            ans = std::max(ans, i - j + 1);
        }

        return ans;
    }
};