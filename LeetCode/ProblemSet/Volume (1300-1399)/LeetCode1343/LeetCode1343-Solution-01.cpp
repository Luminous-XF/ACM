//
// Created by Luminous on 2026/3/10 21:14
//


#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int numOfSubarrays(std::vector<int>& arr, int k, int threshold) {
        const int n = (int) arr.size();

        threshold = threshold * k;
        int sum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];

            int j = i - k + 1;
            if (j < 0) {
                continue;
            }

            if (sum >= threshold) {
                ans++;
            }

            sum -= arr[j];
        }

        return ans;
    }
};