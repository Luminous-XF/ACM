//
// Created by Luminous on 2026/3/24 10:40
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int countCompleteSubarrays(std::vector<int> &nums) {
        const int n = (int) nums.size();

        int k = (int) std::unordered_set<int>(nums.begin(), nums.end()).size();
        std::unordered_map<int, int> book;
        int ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            book[nums[i]]++;

            if (book.size() < k) {
                continue;
            }

            while (book.size() > k || book[nums[j]] > 1) {
                auto it = book.find(nums[j]);
                it->second--;
                if (it->second == 0) {
                    book.erase(it);
                }
                j++;
            }

            ans += j + 1;
        }

        return ans;
    }
};