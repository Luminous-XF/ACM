//
// Created by Luminous on 2026/3/14 14:55
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int longestSemiRepetitiveSubstring(std::string s) {
        const int n = (int) s.length();

        int cnt = 0, ans = 1;
        for (int i = 1, j = 0; i < n; i++) {
            if (s[i] == s[i - 1]) {
                cnt++;
            }

            while (cnt > 1) {
                if (s[j] == s[j + 1]) {
                    cnt--;
                }
                j++;
            }

            ans = std::max(ans, i - j + 1);
        }

        return ans;
    }
};