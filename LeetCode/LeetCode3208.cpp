//
// Created by Luminous on 2024/11/27 16:23.
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        const int n = (int) colors.size();
        int cnt = 1, ans = 0;
        for (int i = -k + 2; i < n; i++) {
            if (colors[(i + n) % n] != colors[(i - 1 + n) % n]) {
                cnt++;
            } else {
                cnt = 1;
            }

            if (cnt >= k) ans++;
        }

        return ans;
    }
};