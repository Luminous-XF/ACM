//
// Created by Luminous on 2024/11/30 15:29.
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum1 = 0, sum2 = 0;
        for (int v : nums) {
            if (v < 10) {
                sum1 += v;
            } else {
                sum2 += v;
            }
        }

        return sum1 != sum2;
    }
};