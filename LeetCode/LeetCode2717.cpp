//
// Created by Luminous on 2024/12/11 11:49
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    int semiOrderedPermutation(std::vector<int>& nums) {
        const int n = (int) nums.size();
        int inx1 = std::find(nums.begin(), nums.end(), 1) - nums.begin();
        int inx2 = std::find(nums.begin(), nums.end(), n) - nums.begin();
        int ans = inx1 + n - inx2 - 1;
        if (inx1 > inx2) ans -= 1;
        return ans;
    }
};