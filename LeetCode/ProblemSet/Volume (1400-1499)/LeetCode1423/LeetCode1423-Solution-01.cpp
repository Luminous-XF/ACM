//
// Created by Luminous on 2026/3/11 0:22
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int maxScore(std::vector<int>& cardPoints, int k) {
        const int n = (int) cardPoints.size();

        int total = std::accumulate(cardPoints.begin(), cardPoints.end(), 0);
        if (k == n) {
            return total;
        }

        int len = n - k, sum = 0, minSum = total;
        for (int i = 0; i < n; i++) {
            sum += cardPoints[i];

            int j = i - len + 1;
            if (j < 0) {
                continue;
            }

            minSum = std::min(minSum, sum);

            sum -= cardPoints[j];
        }

        int ans = total - minSum;

        return ans;
    }
};