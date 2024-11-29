//
// Created by Luminous on 2024/11/27 16:25.
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int len = (int) colors.size(), ans = 0;
        for (int i = 0; i < len; i++) {
            int before = colors[(i - 1 + len) % len];
            int after = colors[(i + 1) % len];
            if (colors[i] != before && colors[i] != after) ans++;
        }

        return ans;
    }
};