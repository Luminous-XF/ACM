//
// Created by Luminous on 2026/3/15 15:48
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int balancedString(std::string s) {
        const int n = (int) s.length();
        const int k = n / 4;

        std::unordered_map<char, int> book;
        for (char c : s) {
            book[c]++;
        }

        if (book['Q'] == k && book['W'] == k && book['E'] == k && book['R'] == k) {
            return 0;
        }

        int ans = n;
        for (int i = 0, j = 0; i < n; i++) {
            book[s[i]]--;

            if (book['Q'] > k || book['W'] > k || book['E'] > k || book['R'] > k) {
                continue;
            }

            while (book[s[j]] < k) {
                book[s[j]]++;
                j++;
            }

            ans = std::min(ans, i - j + 1);
        }

        return ans;
    }
};