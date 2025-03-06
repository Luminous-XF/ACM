//
// Created by Luminous on 2025/3/6 11:59
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    long long beautifulSubarrays(std::vector<int> &nums) {
        std::unordered_map<int, int> cnt;
        cnt[0] = 1;

        long long ans = 0;
        int k = 0;
        for (int num: nums) {
            k ^= num;
            ans += cnt[k];
            cnt[k]++;
        }

        return ans;
    }
};