//
// Created by Luminous on 2026/3/11 11:53
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int minutes) {
        const int n = (int) customers.size();

        int ans1 = 0, ans2 = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                ans1 += customers[i];
            } else {
                sum += customers[i];
            }

            int j = i - minutes + 1;
            if (j < 0) {
                continue;
            }

            ans2 = std::max(ans2, sum);

            if (grumpy[j] == 1) {
                sum -= customers[j];
            }
        }

        int ans = ans1 + ans2;

        return ans;
    }
};