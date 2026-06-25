//
// Created by Luminous on 2026/3/20 8:54
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int numberOfSubstrings(std::string s, int k) {
        const int n = (int) s.length();

        std::unordered_map<char, int> book;
        int cnt = 0, ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            book[s[i]]++;
            if (book[s[i]] == k) {
                cnt++;
            }

            if (cnt == 0) {
                continue;
            }

            while (cnt > 1 || book[s[j]] != k) {
                if (book[s[j]] == k) {
                    cnt--;
                }
                book[s[j]]--;
                j++;
            }

            ans += j + 1;
        }

        return ans;
    }
};