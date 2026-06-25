//
// Created by Luminous on 2026/3/14 2:05
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int maximumLengthSubstring(std::string s) {
        const int n = (int) s.length();

        std::unordered_map<int, int> book;
        int ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            while (book[s[i]] >= 2) {
                book[s[j]]--;
                j++;
            }

            book[s[i]]++;

            ans = std::max(ans, i - j + 1);
        }

        return ans;
    }
};