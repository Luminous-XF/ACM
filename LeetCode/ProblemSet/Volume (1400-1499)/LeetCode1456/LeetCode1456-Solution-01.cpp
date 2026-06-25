//
// Created by Luminous on 2026/3/10 0:13
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    std::unordered_set<char> set = {'a', 'e', 'i', 'o', 'u'};

    int maxVowels(std::string s, int k) {
        const int n = (int) s.length();

        int ans = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (set.contains(s[i])) {
                cnt++;
            }

            int j = i - k + 1;
            if (j < 0) {
                continue;
            }

            ans = std::max(ans, cnt);

            if (set.contains(s[j])) {
                cnt--;
            }
        }

        return ans;
    }
};