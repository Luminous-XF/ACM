//
// Created by Luminous on 2024/12/22 18:10
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:

    std::unordered_map<int, int> book;

    int getK(int x) {
        if (x == 1) return 0;
        if ((x & 1) == 0) return getK(x / 2) + 1;
        return getK(3 * x + 1) + 1;
    }

    int getKth(int lo, int hi, int k) {
        std::vector<std::array<int, 2>> v;
        for (int i = lo; i <= hi; i++) {
            v.push_back({getK(i), i});
        }

        std::sort(v.begin(), v.end());

        return v[k - 1][1];
    }
};