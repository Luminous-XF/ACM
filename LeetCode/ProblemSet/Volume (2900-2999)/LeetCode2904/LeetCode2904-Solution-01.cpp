//
// Created by Luminous on 2026/3/15 3:37
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    std::string shortestBeautifulSubstring(std::string s, int k) {
        const int n = (int) s.length();

        std::string ans;
        int cnt = 0;
        for (int i = 0, j = 0; i < n; i++) {
            if (s[i] == '1') {
                cnt++;
            }

            if (cnt < k) {
                continue;
            }

            while (cnt > k || s[j] == '0') {
                if (s[j] == '1') {
                    cnt--;
                }
                j++;
            }

            int len = i - j + 1;
            if (ans.empty() || len < ans.length()) {
                ans = s.substr(j, len);
            } else if (len == ans.length()) {
                ans = std::min(ans, s.substr(j, len));
            }
        }

        return ans;
    }
};