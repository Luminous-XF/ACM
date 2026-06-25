//
// Created by Luminous on 2026/3/14 4:23
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int maxConsecutiveAnswers(std::string answerKey, int k) {
        const int n = (int) answerKey.length();

        int ans = 0, cntT = 0, cntF = 0;
        for (int i = 0, j = 0; i < n; i++) {
            answerKey[i] == 'T' ? cntT++ : cntF++;
            while (std::min(cntT, cntF) > k) {
                answerKey[j] == 'T' ? cntT-- : cntF--;
                j++;
            }
            ans = std::max(ans, i - j + 1);
        }
        return ans;
    }
};