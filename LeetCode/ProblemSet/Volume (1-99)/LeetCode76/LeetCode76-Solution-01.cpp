//
// Created by Luminous on 2026/3/15 16:44
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        const int n = (int) s.length();

        std::unordered_map<char, int> bookT;
        for (char c : t) {
            bookT[c]++;
        }

        std::unordered_map<char, int> book;
        int minLen = INT_MAX, idx = -1;
        for (int i = 0, j = 0; i < n; i++) {
            book[s[i]]++;
            while (j < i && book[s[j]] > bookT[s[j]]) {
                book[s[j]]--;
                j++;
            }

            bool ok = true;
            for (auto [ch, cnt] : bookT) {
                if (book[ch] < cnt) {
                    ok = false;
                    break;
                }
            }

            int len = i - j + 1;
            if (ok && len < minLen) {
                minLen = len;
                idx = j;
            }
        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(idx, minLen);
    }
};