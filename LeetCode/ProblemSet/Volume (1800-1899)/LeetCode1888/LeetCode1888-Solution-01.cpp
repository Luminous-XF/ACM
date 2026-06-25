//
// Created by Luminous on 2026/3/7 19:45
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int minFlips(std::string s) {
        const int n = (int) s.length();

        int first0 = 0, first1 = 0;
        for (int i = 0; i < n; i++) {
            if ((i & 1) == 0) {
                if (s[i] == '0') {
                    first1++;
                } else {
                    first0++;
                }
            } else {
                if (s[i] == '0') {
                    first0++;
                } else {
                    first1++;
                }
            }
        }

        int ans = std::min(first0, first1);
        int second0 = 0, second1 = 0;
        for (int i = 0; i < n; i++) {
            if ((i & 1) == 0) {
                if (s[i] == '0') {
                    first1--;
                    second1++;
                } else {
                    first0--;
                    second0++;
                }

                if (((n - i - 1) & 1) == 0) {
                    ans = std::min(ans, first0 + second1);
                    ans = std::min(ans, first1 + second0);
                } else {
                    ans = std::min(ans, first0 + second0);
                    ans = std::min(ans, first1 + second1);
                }
            } else {
                if (s[i] == '0') {
                    first0--;
                    second0++;
                } else {
                    first1--;
                    second1++;
                }

                if (((n - i - 1) & 1) == 0) {
                    ans = std::min(ans, first0 + second0);
                    ans = std::min(ans, first1 + second1);
                } else {
                    ans = std::min(ans, first0 + second1);
                    ans = std::min(ans, first1 + second0);
                }
            }
        }

        return ans;
    }
};