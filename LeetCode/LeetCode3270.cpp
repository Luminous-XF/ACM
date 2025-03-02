//
// Created by Luminous on 2025/1/11 23:32
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

#define endl "\n"


class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        std::vector<int> nums{num1, num2, num3};

        int k = 1, ans = 0;
        for (int i = 0; i < 4; i++) {
            int res = INT_MAX;
            for (int j = 0; j < 3; j++) {
                if (nums[j] != 0) {
                    res = std::min(res, nums[j] % 10);
                    nums[j] /= 10;
                } else {
                    res = 0;
                }
            }

            ans += k * res;
            k *= 10;
        }

        return ans;
    }
};