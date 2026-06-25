//
// Created by Luminous on 2026/3/11 0:38
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int maxScore(std::vector<int>& cardPoints, int k) {
        const int n = (int) cardPoints.size();

        int sufSum = 0;
        for (int i = n - 1; i >= n - k; i--) {
            sufSum += cardPoints[i];
        }

        int ans = sufSum, preSum = 0;
        for (int i = 0, j = n - k; i <= k && j < n; i++, j++) {
            preSum += cardPoints[i];
            sufSum -= cardPoints[j];
            ans = std::max(ans, preSum + sufSum);
        }

        return ans;
    }
};