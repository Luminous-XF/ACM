//
// Created by Luminous on 2026/3/6 23:43
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    bool checkOnesSegment(std::string s) {
        const int n = (int) s.length();

        int i = -1;
        while (i + 1 < n && s[i + 1] == '1') {
            i++;
        }

        int j = n;
        while (j - 1 >= 0 && s[j - 1] == '0') {
            j--;
        }

        return i + 1 == j;
    }
};