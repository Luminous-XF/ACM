//
// Created by Luminous on 2026/3/10 23:44
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>


class Solution {
public:
    int minimumRecolors(std::string blocks, int k) {
        int n = (int) blocks.length();

        int cnt = 0, maxCnt = 0;
        for (int i = 0; i < n; i++) {
            if (blocks[i] == 'B') {
                cnt++;
            }

            int j = i - k + 1;
            if (j < 0) {
                continue;
            }

            maxCnt = std::max(maxCnt, cnt);

            if (blocks[j] == 'B') {
                cnt--;
            }
        }

        int ans = k - maxCnt;

        return ans;
    }
};