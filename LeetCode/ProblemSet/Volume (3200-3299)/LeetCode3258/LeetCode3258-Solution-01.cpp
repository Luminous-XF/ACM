//
// Created by Luminous on 2026/3/20 7:42
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int countKConstraintSubstrings(std::string s, int k) {
        const int n = (int) s.length();

        int ans = 0, cnt0 = 0, cnt1 = 0;
        for (int i = 0, j = 0; i < n; i++) {
            s[i] == '0' ? cnt0++ : cnt1++;
            while (j <= i && cnt0 > k && cnt1 > k) {
                s[j] == '0' ? cnt0-- : cnt1--;
                j++;
            }
            ans += i - j + 1;
        }
        return ans;
    }
};