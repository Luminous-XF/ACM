//
// Created by Luminous on 2024/12/26 20:36
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    bool isSubstringPresent(std::string s) {
        const int n = (int) s.size();
        bool book[26][26];
        for (int i = n - 1; i > 0; i--) {
            book[s[i] - 'a'][s[i - 1] - 'a'] = true;
        }

        for (int i = 0; i < n - 1; i++) {
            if (book[s[i] - 'a'][s[i + 1] - 'a']) {
                return true;
            }
        }

        return false;
    }
};