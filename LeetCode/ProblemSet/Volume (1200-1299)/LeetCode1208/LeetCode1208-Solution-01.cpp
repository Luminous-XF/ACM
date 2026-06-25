//
// Created by Luminous on 2026/3/14 3:04
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int equalSubstring(std::string s, std::string t, int maxCost) {
        const int n = (int) s.length();

        int cost = 0, ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            cost += std::abs(s[i] - t[i]);
            while (cost > maxCost) {
                cost -= std::abs(s[j] - t[j]);
                j++;
            }
            ans = std::max(ans, i - j + 1);
        }

        return ans;
    }
};