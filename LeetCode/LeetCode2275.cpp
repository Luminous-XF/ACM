//
// Created by Luminous on 2025/1/12 22:08
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

#define endl "\n"


class Solution {
public:
    int largestCombination(std::vector<int>& candidates) {
        int ans = 0;
        for (int k = 0; k < 24; k++) {
            int res = 0;
            for (int num : candidates) {
                if ((num & (1 << k)) > 0) {
                    res++;
                }
            }
            ans = std::max(ans, res);
        }

        return ans;
    }
};