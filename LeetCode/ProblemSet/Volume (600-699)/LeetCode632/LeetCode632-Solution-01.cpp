//
// Created by Luminous on 2026/3/16 2:32
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> smallestRange(std::vector<std::vector<int>>& nums) {
        const int n = (int) nums.size();

        std::vector<std::pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            for (int num : nums[i]) {
                v.emplace_back(num, i);
            }
        }

        std::ranges::sort(v);
        std::unordered_map<int, int> book;
        int ansL = v.front().first, ansR = v.back().first;
        for (int i = 0, j = 0; i < v.size(); i++) {
            book[v[i].second]++;
            while (book[v[j].second] > 1) {
                book[v[j].second]--;
                j++;
            }
            if (book.size() == n && v[i].first - v[j].first < ansR - ansL) {
                ansL = v[j].first;
                ansR = v[i].first ;
            }
        }

        return {ansL, ansR};
    }
};