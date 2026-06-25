//
// Created by Luminous on 2026/3/14 1:00
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        const int n = (int) s.length();

        std::unordered_set<char> set;
        int ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            while (set.contains(s[i])) {
                set.erase(s[j]);
                j++;
            }

            set.insert(s[i]);

            ans = std::max(ans, i - j + 1);
        }

        return ans;
    }
};