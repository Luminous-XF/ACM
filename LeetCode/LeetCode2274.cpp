//
// Created by Luminous on 2025/1/6 16:10
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

#define endl "\n"

class Solution {
public:
    int maxConsecutive(int bottom, int top, std::vector<int>& special) {
        std::sort(special.begin(), special.end());

        int ans = std::max({0, special.front() - bottom, top - special.back()});
        int before = special.front();
        for (int x : special) {
            ans = std::max(ans, x - before - 1);
            before = x;
        }

        return ans;
    }
};