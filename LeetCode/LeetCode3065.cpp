//
// Created by Luminous on 2025/1/14 21:17
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        int ans = std::count_if(nums.begin(), nums.end(), [&](int num){
            return num < k;
        });

        return ans;
    }
};