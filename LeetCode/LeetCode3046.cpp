//
// Created by Luminous on 2024/12/29 16:34
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    bool isPossibleToSplit(std::vector<int>& nums) {
        std::unordered_map<int, int> book;
        for (int num : nums) {
            book[num]++;
        }

        for (auto& [num, cnt] : book) {
            if (cnt > 2) {
                return false;
            }
        }

        return true;
    }
};