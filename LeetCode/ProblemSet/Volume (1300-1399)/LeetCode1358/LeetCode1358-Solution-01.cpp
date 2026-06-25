//
// Created by Luminous on 2026/3/20 8:10
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int numberOfSubstrings(std::string s) {
        const int n = (int) s.length();

        std::unordered_map<char, int> book;
        int ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            book[s[i]]++;

            if (book['a']  == 0 || book['b'] == 0 || book['c'] == 0) {
                continue;
            }

            while (book[s[j]] > 1) {
                book[s[j]]--;
                j++;
            }

            ans += j + 1;
        }

        return ans;
    }
};