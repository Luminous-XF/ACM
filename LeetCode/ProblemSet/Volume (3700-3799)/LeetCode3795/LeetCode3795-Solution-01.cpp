//
// Created by Luminous on 2026/3/15 3:16
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int minLength(std::vector<int>& nums, int k) {
        const int n = (int) nums.size();

        std::unordered_map<int, int> book;
        int ans = INT_MAX;
        long long sum = 0;
        for (int i = 0, j = 0; i < n; i++) {
            if (book[nums[i]] == 0) {
                sum += nums[i];
            }
            book[nums[i]]++;

            while (sum - nums[j] >= k || book[nums[j]] > 1) {
                book[nums[j]]--;
                if (book[nums[j]] == 0) {
                    sum -= nums[j];
                }
                j++;
            }

            if (sum >= k) {
                ans = std::min(ans, i - j + 1);
            }
        }

        if (ans == INT_MAX) {
            ans = -1;
        }

        return ans;
    }
};